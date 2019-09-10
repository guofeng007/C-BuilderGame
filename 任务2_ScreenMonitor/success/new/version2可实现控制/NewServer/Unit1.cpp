//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "jpeg.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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
         int port = this->Edit1->Text.ToInt();
        this->ServerSocket1->Port = port ;
        //try open 
        if(this->ServerSocket1->Active == false)
        {
        this->ServerSocket1->Open();
        }
        //judge open
       if(this->ServerSocket1->Active == true )
       {
        this->Button1->Visible = false ;
        this->Button2->Visible = true ;
        AppendText("Server start at "+AnsiString(port));
       }
       else
       {
         AppendText("Server start error");
       }
        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
          //try close
        if(this->ServerSocket1->Active == true)
        {
                this->ServerSocket1->Close();
        }
        //judge
       if(this->ServerSocket1->Active == false)
       {
                this->Button1->Visible = true ;
                this->Button2->Visible = false ;
                 AppendText("Server close");
        }
        else
        {
                 AppendText("Server not start");
        }        
}
void __fastcall TForm1::AppendText(AnsiString str)
{
      this->Memo1->Lines->Add(str);  
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket1Accept(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AppendText(Socket->RemoteAddress+"  Accepted");        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket1ClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
         AppendText(Socket->RemoteAddress+"  Connected");          
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket1ClientDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
         AppendText(Socket->RemoteAddress+"  Disconnected");          
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket1ClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
         AppendText(Socket->RemoteAddress+"  Error"+ErrorCode);
         ErrorCode = 0 ;          
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AnsiString recvText =   Socket->ReceiveText() ;
        AppendText(Socket->RemoteAddress+"  Data:"+recvText);
        TStringList *temp = new TStringList ;
        temp->DelimitedText = recvText ;
        for(int i = 0 ; i < temp->Count ; i++)
        {
                ParseString(temp->Strings[i],Socket);
        }
               
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ParseString(String recvString,TCustomWinSocket *Socket)
{

        AnsiString command;      
	int pos = recvString.Pos(";");//get first command tpye
        command = recvString.SubString(1,pos-1);
        recvString = recvString.SubString(pos+1,recvString.Length()-pos) ;// start length
        int cq = 0 ;
        TMemoryStream *ImageStream = new TMemoryStream();

       //command 1  ImageCommand
       // 1;6
        if(command == "1")
        {
          //compress quality 6
            cq = recvString.ToInt() ;
           try
           {
           	
                CaptureImage(cq,ImageStream);
                if(ImageStream->Size>0)
                {
                ImageStream->Position = 0 ; //care
                Socket->SendStream(ImageStream)  ;
                }
           }
           catch(...)
           {
                AppendText("cmd:1 get image error");
           }
        }
        //command = 2   mouse message
        if(command == "2")
        {     // x;y;flag
                int pos = recvString.Pos(";");//get
                AnsiString xStr =  recvString.SubString(1,pos-1);
                int x = xStr.ToInt();
                 recvString = recvString.SubString(pos+1,recvString.Length()-pos) ;// start length

                //y;flag
                pos = recvString.Pos(";");//get
                AnsiString yStr =  recvString.SubString(1,pos-1);
                int y = yStr.ToInt();
                 recvString = recvString.SubString(pos+1,recvString.Length()-pos) ;// start length

                 //flag
                 int flag = recvString.ToInt() ;

                 // x y flag
                 //construct message
                //VC++ MessageSend widnows base
                SetCursorPos(x,y);
                long result = y<<16+x ;
               	HWND desk = GetDesktopWindow();
                if(flag == 1)
                {
                //dobule
                        mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
                        mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
                        mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
                        mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
                }
                if(flag == 2)
                {
                      mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
                      mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
                }



        }
        //command = 3  ok i got one image get next
        if(command == "3")       
        {

           try
           {
           
                CaptureImage(cq,ImageStream);
                if(ImageStream->Size>0)
                {
                ImageStream->Position = 0 ; //care
                Socket->SendStream(ImageStream)  ;
                }
           }
            catch(...)
           {
                AppendText("cmd:3 resend error");
           }
        }


       // delete ImageStream ;
   }


void __fastcall TForm1::CaptureImage(int cq,TMemoryStream * imgstream)
{
	LONG width ,height ;
        RECT capRect ;
        HDC DesktopDC ;

        GetWindowRect(GetDesktopWindow(),&capRect);

        DesktopDC = GetDC(GetDesktopWindow()); //memDC
        width = capRect.right - capRect.left;
        height = capRect.bottom-capRect.top ;
        Graphics::TBitmap *bBitmap ;//birmap

        try
        {
                bBitmap = new Graphics::TBitmap();
                bBitmap->Width = width ;
                bBitmap->Height = height ;
                //deep
                 bBitmap->PixelFormat = TPixelFormat(pf24bit);

                //copy
                BitBlt(bBitmap->Canvas->Handle,0,0,width,height,DesktopDC,capRect.left,capRect.top,SRCCOPY);
                // this->Image1->Picture->Bitmap = bBitmap ;
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
