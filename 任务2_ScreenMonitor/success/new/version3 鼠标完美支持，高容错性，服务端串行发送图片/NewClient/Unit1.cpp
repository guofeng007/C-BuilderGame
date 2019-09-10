//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "jpeg.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
bool    flag ;
TWndMethod oldWndProc ;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
        //form
{       oldWndProc = this->WindowProc ;
	this->WindowProc = MyWndProc ;
	flag = false ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	
	AnsiString ip = this->Edit1->Text;
	int port = this->Edit2->Text.ToInt();
         this->ClientSocket1->Host = ip ;
         this->ClientSocket1->Port = port ;
         //try open
        if(this->ClientSocket1->Active == false)
        {
        	 this->ClientSocket1->Open();
                 this->Button1->Visible = false ;
                 this->Button2->Visible = true ;
                 this->Button3->Visible = true ;
                 
        }
       if(this->ClientSocket1->Active == true )
       {
        AppendText("connect server at "+ip);
       }
       AppendText("connect server at "+ip);	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
		//try close
	 if(this->ClientSocket1->Active == true )
        {
                this->ClientSocket1->Close();
         }

         //judge close
       if(this->ClientSocket1->Active == false )
         {
                this->Button1->Visible = true ;
                this->Button2->Visible = false ;
                this->Button3->Visible = false ;
                AppendText("client close");
         }
        else
        {
                 AppendText("client not start");
        }		
}
//---------------------------------------------------------------------------
//start monitor
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	flag = true ;    
	int compress = this->TrackBar1->Position ; 
	AnsiString str = "\n1;"+AnsiString(compress)+"\n";
        if(this->ClientSocket1->Active == true)
        {
        	this->ClientSocket1->Socket->SendText(str);
                this->Button3->Visible = false ;
                this->Button4->Visible = true ;
        }
}
//stop monitor
void __fastcall TForm1::Button4Click(TObject *Sender)
{
        
                 flag = false ; //stop feedback
                 this->Button3->Visible = true ;
                this->Button4->Visible = false ;
        
}
void __fastcall TForm1::AppendText(AnsiString str)
{
      this->Memo1->Lines->Add(str);  
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AppendText("connect to server");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Disconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
       AppendText("disconnect to server");
        this->Button1->Visible = true ;
        this->Button2->Visible = false ;
        this->Button3->Visible = false ;
        this->Button4->Visible = false ;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{        ErrorCode = 0 ;
	 AppendText("error   errorcode  " + AnsiString(ErrorCode));

}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------




//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
	AppendText("recv Image");
	//1. read
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

                         //2. feedback    on any cases exception
                         if(flag == true)
                         {
                        AnsiString str  ="\n3;\n";
        		Socket->SendText(str);
                         }

                         delete jpeg;
                        }
                catch(...)
                	{
                         AppendText("jpeg error");
                         //2. feedback    on any cases exception
                         if(flag == true)
                         {
                        AnsiString str  ="\n3;\n";
        		Socket->SendText(str);
                         }

                	}
                }


                 delete ImageStream; 

        } 
      catch(...)
      {
      	AppendText("ImageStream error");
      }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
	//right click
	 if(Button == mbRight)
        {
        		//	send mouse
        //Button left right middle    left click  rightcllick
        AnsiString sendStr = "\n2;"+AnsiString(X)+";"+AnsiString(Y)+";" ;
        // "\n2;x;y;2;1\n"
        AnsiString buttonStr = "2";
        sendStr +=buttonStr+";1"+"\n";
	AppendText("mouse coming " + sendStr);
        this->ClientSocket1->Socket->SendText(sendStr);        
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemControlExitClick(TObject *Sender)
{
	Application->Terminate();	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemControlFullScreenClick(TObject *Sender)
{
	//hide panel
	this->LeftPanel->Visible = false ;
        this->CenterPanel->Visible = false ;
        //full window
        this->WindowState = wsMaximized ;
        this->MenuItemControlFullScreenExit->Visible = true ;
        this->MenuItemControlFullScreen->Visible = false ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemControlFullScreenExitClick(TObject *Sender)
{
        //show panel
	this->LeftPanel->Visible = true ;
        this->CenterPanel->Visible = true ;
        //full window
        this->WindowState = wsNormal ;
        this->MenuItemControlFullScreenExit->Visible = false ;
        this->MenuItemControlFullScreen->Visible = true ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1Click(TObject *Sender)
{
	//get cursor pos
	POINT p ;
	GetCursorPos(&p);
        p = this->Image1->ScreenToClient(p);
	int x = p.x ;
        int y = p.y ;
        //get event   

        //Button left right middle    left click  rightcllick
        AnsiString sendStr = "\n2;"+AnsiString(x)+";"+AnsiString(y)+";" ;
        // "\n2;x;y;1;1\n"
        // 1 left 2 right
        AnsiString buttonStr = "1";

        // 1 click 2 dbclk
        AnsiString dbCLK = "1";

        sendStr +=buttonStr+";"+dbCLK+"\n";
	AppendText("mouse coming " + sendStr);
        this->ClientSocket1->Socket->SendText(sendStr);
       
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1DblClick(TObject *Sender)
{
	//get cursor pos
	POINT p ;
	GetCursorPos(&p);
        p = this->Image1->ScreenToClient(p);
	int x = p.x ;
        int y = p.y ;
        //get event   

        //Button left right middle    left click  rightcllick
        AnsiString sendStr = "\n2;"+AnsiString(x)+";"+AnsiString(y)+";" ;
        // "\n2;x;y;1;2\n"
        // 1 left 2 right
        AnsiString buttonStr = "1";

        // 1 click 2 dbclk
        AnsiString dbCLK = "2";

        sendStr +=buttonStr+";"+dbCLK+"\n";
	AppendText("mouse coming " + sendStr);
        this->ClientSocket1->Socket->SendText(sendStr);	
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MyWndProc(Messages::TMessage &Message)
{

       
        if(Message.Msg == WM_KEYDOWN)
        {

           ShowMessage((int)Message.WParam);
        }
        else
        {
        	oldWndProc(Message);
        }
      
       
         
    
}

