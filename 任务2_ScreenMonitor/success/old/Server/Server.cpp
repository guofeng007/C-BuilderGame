//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Server.h"
#include "jpeg.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if(this->Button1->Caption == "启动服务端")
        {
        	this->ServerSocket1->Open();
                this->Button1->Caption = "停止服务端";
                Status("启动服务端，监听端口900");
        }
        else
        {
               this->ServerSocket1->Close();
                this->Button1->Caption = "启动服务端";
                Status("停止服务端监听");
        }
}
//---------------------------------------------------------------------------
void __fastcall  TForm1::Status(AnsiString str)
{
	  this->StatusBar1->Panels->Items[0]->Text = str ;"启动服务，监听端口900";
}

// opotion  1 screen   2 current form   ;level deep ;cq compress quality ,memstream
void __fastcall TForm1::CaptureImage(int options ,int level ,int cq,TMemoryStream * imgstream)
{
	LONG width ,height ;
        RECT capRect ;
        HDC DesktopDC ;
        switch(options)
        {
        	case 1:
                   GetWindowRect(GetDesktopWindow(),&capRect);
                   break ;
                case 2:
                   HWND ForegWin ;
                   ForegWin = GetForegroundWindow();
                   if(!ForegWin)
                   {
                         ForegWin =  GetDesktopWindow() ;//if no get desktop

                   }
                   GetWindowRect(ForegWin,&capRect);
                   break ;
                default:break ;
        }
        DesktopDC = GetDC(GetDesktopWindow()); //memDC
        width = capRect.right - capRect.left;
        height = capRect.bottom-capRect.top ;
        Graphics::TBitmap *bBitmap ;//birmap

        try
        {
                bBitmap = new Graphics::TBitmap();
                bBitmap->Width = width ;
                bBitmap->Height = height ;

                if((level > 0 )&&( level <=8))
                {
                	bBitmap->PixelFormat = TPixelFormat(level);
                }
                //copy
                BitBlt(bBitmap->Canvas->Handle,0,0,width,height,DesktopDC,capRect.left,capRect.top,SRCCOPY);
                // this->Image1->Picture->Bitmap = bBitmap ;
//server don't see                  
                //compress
                if(cq >=0)
                {
                	TJPEGImage *jpeg ;
                        try
                        {
                        	jpeg = new TJPEGImage() ;
                                jpeg->CompressionQuality = cq ;
                                jpeg->Assign(bBitmap);
                                jpeg->SaveToStream(imgstream);
                        } 
                        __finally
                        {
                        	delete jpeg;
                        }
                }
                else
                {
                      bBitmap->SaveToStream(imgstream);
                }
        } 
        __finally
        {
           delete bBitmap ;
        }
}
void __fastcall TForm1::ServerSocket1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
	AnsiString recvString = Socket->ReceiveText();
        AnsiString remoteAdress = Socket->RemoteAddress;
        AnsiString command;
        int option,level,cq ;
	int pos = recvString.Pos(";");//get first command tpye
        command = recvString.SubString(1,pos-1);
        recvString = recvString.SubString(pos+1,recvString.Length()-pos) ;// start length
       


        //getimage
        if(command == "1")
        {
           //get option level cq
                     // 1;1;1;10
           //option
           pos = recvString.Pos(";");
           option = recvString.SubString(1,pos-1).ToInt();
            recvString = recvString.SubString(pos+1,recvString.Length()-pos) ;// start length

            //level
             pos = recvString.Pos(";");
           level = recvString.SubString(1,pos-1).ToInt();
            recvString = recvString.SubString(pos+1,recvString.Length()-pos) ;// start length
            //cq     
           cq = recvString.ToInt();
           TMemoryStream *ImageStream ;
           try
           {
           	ImageStream = new TMemoryStream();
                if(option == 2)
                {
                	CaptureImage(2,level,cq,ImageStream);
                }
                else
                {
                         CaptureImage(1,level,cq,ImageStream);
                }
                ImageStream->Position = 0 ; //care
                  //  Socket->SendStream(ImageStream);
                //send
                    //    Socket->SendStreamThenDrop(ImageStream);

                if(!Socket->SendStream(ImageStream))
                {
                  MessageBox(0,"发送失败","错误",MB_ICONERROR);
                }
                
           }
           __finally
           {
             //delete ImageStream ;  //server want to see this bitmap ,dong free here 自动被释放的
           }
        }
        else
        {
        	//no change port
                ShowMessage("无效命令");
                return ;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1Accept(TObject *Sender,
      TCustomWinSocket *Socket)
{
	this->StatusBar1->SimpleText = "accept client:"+Socket->RemoteAddress;	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
		this->StatusBar1->SimpleText = "connect client:"+Socket->RemoteAddress;	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
		this->StatusBar1->SimpleText = "disconnect client:"+Socket->RemoteAddress;	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
		this->StatusBar1->SimpleText = "error client:"+Socket->RemoteAddress;	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	int result ;
        if(this->ServerSocket1->Socket->ActiveConnections>0)
        {
           result = MessageBox(this->Handle,"客户端还在连接中","确定断开吗",MB_OKCANCEL);
           if(result == IDCANCEL)
           {
           	CanClose = false ;
                return ;
           }
        }

        this->ServerSocket1->Close();
        CanClose = true ;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	this->ServerSocket1->Close();	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PopupExitClick(TObject *Sender)
{
	this->Close();	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PopupHideShowClick(TObject *Sender)
{
	this->PopupHideShow->Checked =   !this->PopupHideShow->Checked;
        this->Visible = 	this->PopupHideShow->Checked;

}
//---------------------------------------------------------------------------

