//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Client.h"
#include "SetParam.h"
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
void __fastcall TForm1::MenuItemImageFullScreenClick(TObject *Sender)
{
	if(!this->MenuItemImageFullScreen->Checked)
        {
        this->MenuItemImageFullScreen->Checked = true ;
       	this->BorderStyle =  bsNone ; //no border
        this->WindowState = wsMaximized ; //max
        this->PopupMenuItemFullScreen->Checked = true ;

        }
        else
        {
        this->MenuItemImageFullScreen->Checked = false ;
        this->PopupMenuItemFullScreen->Checked = false ;
       	this->BorderStyle =  bsSizeable ; // border
        this->WindowState = wsNormal ; //max
        //center method
        int width = Screen->Width ;
        int height = Screen->Height ;
        this->Width = width /2 ;
        this->Height = height/2 ;

        this->Left = (width - this->Width)/2 ;
        this->Top = (height - this->Height)/2 ;
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::MenuItemConnectSetClick(TObject *Sender)
{
	Form2->ShowModal();
        if(Form2->result == 1)
        {
         serverIP = Form2->serverIP;
         serverPort = Form2->serverPort;
         option  = 1;
         level = Form2->level ;
         cq = Form2->cq;
         this->MenuItemConnectConnect->Enabled = true ;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemConnectConnectClick(TObject *Sender)
{
	if(!this->ClientSocket1->Active)
        {
        	this->ClientSocket1->Address = this->serverIP;
                this->ClientSocket1->Port = this->serverPort;
                this->ClientSocket1->Open();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemConnectCloseClick(TObject *Sender)
{
	if(this->ClientSocket1->Active)
        {

                this->ClientSocket1->Close();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemConnectExitClick(TObject *Sender)
{
	this->Close();	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemImageNextClick(TObject *Sender)
{
	if(!this->ClientSocket1->Active)
        {
          return ; // no connect
        }
        AnsiString command = "1";
        AnsiString option = "1";
        AnsiString level = this->level;
        AnsiString cq = this->cq;
        AnsiString Msg = command+";"+option+";"+level+";"+cq;
        this->ClientSocket1->Socket->SendText(Msg);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
         this->StatusBar1->SimpleText = "收到数据";
	TMemoryStream *ImageStream ;
        TJPEGImage *jpeg ;
        try
        {
        	int n ;
                char Buffer[10240];
                ImageStream = new  TMemoryStream();
                do
                {
                	n = Socket->ReceiveBuf(Buffer,sizeof(Buffer));
	                if( n <= 0)
        	        {
                        	break ;//no data
                        }
                        else
                        {

                        ImageStream->Write(Buffer,n);
                        Sleep(50); //just sleep to wait for the data
                        }
                }while(1); //read all
                if(ImageStream->Size>0)
                {
               
                 ImageStream->Position = 0 ;

                 try
                 	{
                        jpeg = new TJPEGImage();
                        jpeg->LoadFromStream(ImageStream);
                        this->Image1->Picture->Bitmap->Assign(jpeg);

                        }
                __finally
                	{
                                delete jpeg; 
                	}
                }

        } 
        __finally
        {

                delete ImageStream; 
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        this->MenuItemImageNext->Click();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
        if(this->ClientSocket1->Active)
        {
         int result = MessageBox(this->Handle,"连接没有断开，确定要退出吗","确定",MB_OKCANCEL);
         if(result == IDOK)
         {
                 this->ClientSocket1->Close();
                 CanClose = true ;
         }
         else
         {
                CanClose = false ;
         }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        this->MenuItemConnectConnect->Enabled = false ;
        this->MenuItemConnectClose->Enabled = true ;
        this->StatusBar1->SimpleText = "与服务器连接成功";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
          this->StatusBar1->SimpleText = "服务器连接发生错误";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Disconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
      this->MenuItemConnectConnect->Enabled = true ;
        this->MenuItemConnectClose->Enabled = false ;
        this->StatusBar1->SimpleText = "与服务器断开连接";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Connecting(TObject *Sender,
      TCustomWinSocket *Socket)
{
          this->StatusBar1->SimpleText = "正在连接服务器";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemImageAutoScaleClick(TObject *Sender)
{
       this->MenuItemImageAutoScale->Checked = !this->MenuItemImageAutoScale->Checked;
       this->Image1->Stretch = this->MenuItemImageAutoScale->Checked ;
       this->PopupMenuItemAutoScale->Checked = this->MenuItemImageAutoScale->Checked ;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemImageSaveClick(TObject *Sender)
{
     if(this->SavePictureDialog1->Execute())
     {
        this->Image1->Picture->SaveToFile(this->SavePictureDialog1->FileName);
     }
}
//---------------------------------------------------------------------------

