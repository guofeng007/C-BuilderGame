//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "pies"
#pragma resource "*.dfm"
TForm1 *Form1;
int centerX ;
int centerY ;
int oldDegree = 0 ;
int threshHold = 10 ;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	centerX = this->Pie1->Width/2 ;
        centerY = this->Pie1->Height/2 ;
        this->Pie1->Angles->StartAngle = 0 ;
        this->Pie1->Angles->EndAngle = 1 ;
        this->ComboBox1->ItemIndex = 0 ; 
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Pie1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
	int dtX = X-centerX ;
        int dtY =-( Y - centerY );
     	double angle =  ArcTan2(dtY,dtX);
        int degree = ((int)(angle/PI*180+360))%360 ;
        if(degree >=180)
        {
        degree = 175;
        }
        if(degree <5)
        {
            degree = 10 ;
        }

        this->Pie1->Angles->EndAngle = degree ;

        if(abs(degree-oldDegree) > threshHold)
        {
	//remember new degree
               	oldDegree = degree ;

                if(this->ClientSocket1->Active == true)
                {
                	 //revise to 0-127
       		 float per = 127/180.0 ;
       		 degree = degree*per  ;
                 AnsiString sendCmd = "";
                 sendCmd="/cmd:data:"+AnsiString(degree)+":;";
                 this->ClientSocket1->Socket->SendText(sendCmd);
                }
                 else
                {
                	ShowMessage("请先连接服务器");
                }

        }


      // ShowMessage(AnsiString(degree));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Change(TObject *Sender)
{
	try
        {
       	threshHold = this->Edit1->Text.ToInt();
        }
        catch(...)
        {
        	ShowMessage("设置阈值不合法，请输入整数1-170");
        }



}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    try
        {
      	this->ClientSocket1->Address = this->Edit2->Text;
        this->ClientSocket1->Port = this->Edit3->Text.ToInt() ;
        }
        catch(...)
        {
        	ShowMessage("IP地址或者端口不合法，请重新设置");
        }
        if(this->ClientSocket1->Active == false)
        {
        	this->ClientSocket1->Open();
                this->Label5->Caption = "服务端已连接";
                this->Button2->Visible = false ;
                this->Button3->Visible = true ;
        }
        if(this->ClientSocket1->Active == true)
        {
        
                this->Label5->Caption = "服务端已连接";
                this->Button2->Visible = false ;
                this->Button3->Visible = true ;
        }		
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	if(this->ClientSocket1->Active == true)
        {
        	this->ClientSocket1->Close() ;
                this->Button2->Visible = true ;
                this->Button3->Visible = false ;
	       	this->Label5->Caption = "服务端断开";
        }
	if(this->ClientSocket1->Active == false)
        {

                this->Button2->Visible = true ;
                this->Button3->Visible = false ;
	       	this->Label5->Caption = "服务端断开";
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int sel = this->ComboBox1->ItemIndex ;
        AnsiString sendCmd ="";
        switch (sel)
        {
          case 0:
          sendCmd="/cmd:start:;";
          break;
          case 1:
          sendCmd="/cmd:end:;";
          break;
          case 2:
          sendCmd = "/cmd:data:5:;";
          break;
          case 3:
          sendCmd = "/cmd:data:20:;";
          break;
          case 4:
          sendCmd = "/cmd:data:40:;";
          break;
          case 5:
          sendCmd = "/cmd:data:60:;";
          break;
          case 6:
          sendCmd = "/cmd:data:80:;";
          break;
          case 7:
          sendCmd = "/cmd:data:100:;";
          break;
          case 8:
          sendCmd = "/cmd:data:120:;";
          break;
          default: ;
          break ;
        }
        
        if(sendCmd !="")
        {
        	if(this->ClientSocket1->Active == true)
                {
                	this->ClientSocket1->Socket->SendText(sendCmd);
                }
                else
                {
                	ShowMessage("请先连接服务器");
                }

        }


}
//---------------------------------------------------------------------------
//cmd:start:;
//cmd:end:;
//data:0:;
//data:10:;
//data:180:;
//data:var:;
void __fastcall TForm1::ClientSocket1Disconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
      
                this->Button2->Visible = true ;
                this->Button3->Visible = false ;
	       	this->Label5->Caption = "服务端断开";		
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
	ErrorCode = 0 ;
        ShowMessage("socket error "+ErrorCode);
}
//---------------------------------------------------------------------------

