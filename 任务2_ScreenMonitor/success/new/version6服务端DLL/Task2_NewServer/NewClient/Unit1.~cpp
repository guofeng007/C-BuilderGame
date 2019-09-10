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
int cq = 80 ;
bool log = false ;
bool recvFlag = false ;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
        //form
{      
	flag = false ;
        cq =   this->TrackBar1->Position ;
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
        AddToLog("connect server at "+ip);
       }
       AddToLog("connect server at "+ip);	
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
                AddToLog("client close");
         }
        else
        {
                 AddToLog("client not start");
        }		
}
//---------------------------------------------------------------------------
//start monitor
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	flag = true ;    

	AnsiString str = "DeliverImage;"+AnsiString(cq)+";\n";
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

//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AddToLog("connect to server");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Disconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
       AddToLog("disconnect to server");
        this->Button1->Visible = true ;
        this->Button2->Visible = false ;
        this->Button3->Visible = false ;
        this->Button4->Visible = false ;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{        ErrorCode = 0 ;
	 AddToLog("error   errorcode  " + AnsiString(ErrorCode));

}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------




//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
	AddToLog("recv Image");
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
                  Sleep(50);
                 ImageStream->Position = 0 ;

                 try
                 	{
                        jpeg = new TJPEGImage();
                        jpeg->LoadFromStream(ImageStream);
                        this->Image1->Picture->Bitmap->Assign(jpeg);

                         //2. feedback    on any cases exception  user stop 
                         if(flag == true)
                         {
                                recvFlag = true ;
                         }


                         delete jpeg;
                        }
                catch(...)
                	{
                         	AddToLog("jpeg error");
                         	//2. feedback    on any cases exception
                                if(flag == true)
                                 {
                                recvFlag = true ;
                                }
                	}
                
                }


                 delete ImageStream; 

        } 
      catch(...)
      {
      	AddToLog("ImageStream error");
      }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
	//RightClick
	 if(Button == mbRight)
        {
        //"RightClick;x;y;\n"
        AnsiString sendStr = "RightClick;"+AnsiString(X)+";"+AnsiString(Y)+";\n" ;
	//SendText
	AddToLog("mouse coming " + sendStr);
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
        this->BorderStyle = bsNone ;
        this->Menu = NULL ;
        //exit screen
        this->MenuItemControlFullScreen->Visible = false ;
        this->MenuItemControlFullScreenExit->Visible  = true ;
        this->NorthPanel->Visible = true ;
       
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemControlFullScreenExitClick(TObject *Sender)
{
        //show panel
	this->LeftPanel->Visible = true ;
        this->CenterPanel->Visible = true ;
        //full window
        this->WindowState = wsNormal ;
        this->BorderStyle = bsSizeable ;
        this->Menu = this->MainMenu1 ;
        this->MenuItemControlFullScreen->Visible = true ;
        this->MenuItemControlFullScreenExit->Visible  = false ;
        Left = 300 ;
        Top = 100 ;
        Width = 1000 ;
        Height = 600 ;
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
        //send message
        // "LeftClick;x;y;\n"
        AnsiString sendStr = "LeftClick;"+AnsiString(x)+";"+AnsiString(y)+";\n" ;

	//send text
	AddToLog("mouse coming " + sendStr);
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
        // "DoubleClick;x;y;\n"
        AnsiString sendStr = "DoubleClick;"+AnsiString(x)+";"+AnsiString(y)+";\n";
        //send text
	AddToLog("mouse coming " + sendStr);
        this->ClientSocket1->Socket->SendText(sendStr);	
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MyWndProc(Messages::TMessage &Message)
{

       
       
      
       
         
    
}

void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
	cq = this->TrackBar1->Position ;	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
	if(this->WindowState == wsMaximized)
        {
        	if(Y < 20 )
        	{
        	       //	this->Menu = this->MainMenu1 ;
                       this->NorthPanel->Visible = true ;
	        }
        	else
	        {
        	       //	this->Menu = NULL ;
                        this->NorthPanel->Visible = false ;
	        }
        }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::NorthPanelClick(TObject *Sender)
{
	 //show panel
	this->LeftPanel->Visible = true ;
        this->CenterPanel->Visible = true ;
        //full window
        this->WindowState = wsNormal ;
        this->BorderStyle = bsSizeable ;
        this->Menu = this->MainMenu1 ;
        this->MenuItemControlFullScreen->Visible = true ;
        this->MenuItemControlFullScreenExit->Visible  = false ;
        this->NorthPanel->Visible = false ;
        Left = 300 ;
        Top = 100 ;
        Width = 1000 ;
        Height = 600 ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        //KeyDown;VK_A;\n
       AnsiString sendStr = "KeyDown;"+AnsiString(Key)+";\n";
       this->ClientSocket1->Socket->SendText(sendStr);
      AddToLog(sendStr);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
        log =  this->CheckBox1->Checked ;        
}
void __fastcall TForm1::AddToLog(AnsiString str)
{
        if(log == true)
        {
                this->Memo1->Lines->Add(str);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
        this->Memo1->Lines->Clear();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        if(recvFlag ==  true)
        {

                     AnsiString str = "DeliverImage;"+AnsiString(cq)+";\n";
        	     this->ClientSocket1->Socket->SendText(str);
                     recvFlag = false ;
                    

       }

}
//---------------------------------------------------------------------------

