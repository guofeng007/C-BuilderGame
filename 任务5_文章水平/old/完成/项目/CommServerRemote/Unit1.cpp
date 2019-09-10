//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
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

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int remotePort =  0 ;
        try
        {
             remotePort = this->Edit2->Text.ToInt() ;
        }
        catch(...)
        {
        	ShowMessage("远程客户端端口错误，不合法");
                return ;
        }
        this->ServerSocket2->Port = remotePort ;
        if(this->ServerSocket2->Active == false )
        {
		this->ServerSocket2->Open();
                this->Label2->Caption = "远程端开启成功";
                this->Button2->Visible = false ;
                this->Button4->Visible = true ;
        }
        //verify state
         if(this->ServerSocket2->Active == true )
        {
	
                this->Label2->Caption = "远程端开启成功";
                this->Button2->Visible = false ;
                this->Button4->Visible = true ;
        }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	if(this->ServerSocket2->Active == true)
        {
		this->ServerSocket2->Open() ;
                this->Label2->Caption = "远程端已经关闭";
                this->Button2->Visible = true ;
                this->Button4->Visible = false ;
        }
        //verity state
        if(this->ServerSocket2->Active == false)
        {
		
                this->Label2->Caption = "远程端已经关闭";
                this->Button2->Visible = true ;
                this->Button4->Visible = false ;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
       int commPort =  0 ;
        try
        {
             commPort = this->Edit1->Text.ToInt() ;
        }
        catch(...)
        {
        	ShowMessage("硬件客户端端口错误，不合法");
                return ;
        }
        this->ServerSocket1->Port = commPort ;
        if(this->ServerSocket1->Active == false )
        {
		this->ServerSocket1->Open() ;
                this->Label1->Caption = "硬件客户端开启成功";
                this->Button1->Visible = false ;
                this->Button3->Visible = true ;
        }
        //verify state
        if(this->ServerSocket1->Active == true )
        {

                this->Label1->Caption = "硬件客户端开启成功";
                this->Button1->Visible = false ;
                this->Button3->Visible = true ;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        if(this->ServerSocket1->Active == true)
        {
		this->ServerSocket1->Close() ;
                this->Label1->Caption = "远程端已经关闭";
                this->Button1->Visible = true ;
                this->Button3->Visible = false ;
        }
        //verify state
         if(this->ServerSocket1->Active == true)
        {
		
                this->Label1->Caption = "远程端已经关闭";
                this->Button1->Visible = true ;
                this->Button3->Visible = false ;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket2ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
	AnsiString  remoteStr = Socket->ReceiveText();
     //只是转发

                int count =       ServerSocket1->Socket->ActiveConnections ;
        	for(int j = 0 ;  j < count ; j++)
        	{
	 	ServerSocket1->Socket->Connections[j]->SendText(remoteStr);
        	}


}
//---------------------------------------------------------------------------
TStringList * __fastcall TForm1::Parse(AnsiString str ,AnsiString delimeter)
{
        TStringList *list = new TStringList ;
	int pos = str.Pos(delimeter);
        if(pos<=0)
        {
		list->Add(str);//no delimeter so only this
                return list ;
        }
        while(pos >0)
        {
		AnsiString unit = str.SubString(1,pos-1);
                str = str.SubString(pos+1,str.Length()-pos);
                list->Add(unit);
                pos =  str.Pos(delimeter);

        }
        return list ;
}
void __fastcall TForm1::ServerSocket2ClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
		ErrorCode = 0 ;
        ShowMessage("socket error "+ErrorCode);	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
		ErrorCode = 0 ;
        ShowMessage("socket error "+ErrorCode);	
}
//---------------------------------------------------------------------------

