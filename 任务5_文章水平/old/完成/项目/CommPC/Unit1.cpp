//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MSCommLib_OCX"
#pragma resource "*.dfm"
TForm1 *Form1;
int RXDCount = 0 ;
int TXDCount = 0 ;
AnsiString remoteIP = "";
AnsiString remotePort="";
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        this->ComboBox1->ItemIndex = 1 ;

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        short sel = this->ComboBox1->ItemIndex + 1 ;

        this->MSComm1->CommPort = sel;
        try
        {
           if(this->MSComm1->PortOpen ==  false)
                {
                this->MSComm1->PortOpen =  true ;
                }

        }
        catch(...)
        {
                ShowMessage("串口不存在或者被其他程序占用请解除重试");
        }
        //check state

         if(this->MSComm1->PortOpen ==  true )
                {
                //reset data
                RXDCount = 0 ;
                TXDCount = 0 ;
                this->Label1->Caption="串口已打开 ";
                this->Button2->Visible = true ;
                this->Button1->Visible = false  ;
                }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        try
        {
             if(this->MSComm1->PortOpen ==  true )
                {
                this->MSComm1->PortOpen =  false ;
                }

        }
        catch(Exception &e)
        {
                 ShowMessage("串口关闭失败" );
        }
        //chekc state
         if(this->MSComm1->PortOpen ==  false )
                {
                this->Label1->Caption="串口已关闭 ";
                this->Button1->Visible = true ;
                this->Button2->Visible = false ;
                }



}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        this->Memo1->Lines->Clear();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
        this->Memo2->Lines->Clear();          
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
        if(this->Memo2->Lines->Count>0)
        {
                AnsiString str = this->Memo2->Text;
                OleVariant s = str ;
                this->MSComm1->Output = s ;
                TXDCount +=str.Length();
                this->StatusBar1->Panels->Items[1]->Text ="TXD发送字节:"+AnsiString(TXDCount);
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::MSComm1Comm(TObject *Sender)
{

       switch (this->MSComm1->CommEvent)
       {
         case 1: ;
         break;
         case 2:

              
                if(this->MSComm1->InBufferCount>0)
                {
                        OleVariant s = this->MSComm1->Input;
                        AnsiString str = s.AsType(varString);
                        this->Memo1->Text =this->Memo1->Text+str ;
                        RXDCount +=str.Length();
                        this->StatusBar1->Panels->Items[0]->Text ="RXD接收字节:"+AnsiString(RXDCount);

                }
          ;
         break;
         default: ;
       }


}
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
        RXDCount = 0 ;
         this->StatusBar1->Panels->Items[0]->Text ="RXD接收字节:"+AnsiString(RXDCount);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
        TXDCount = 0 ;
        this->StatusBar1->Panels->Items[1]->Text ="TXD发送字节:"+AnsiString(TXDCount);       
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{

	Form2 = new TForm2(this);
          Form2->ShowModal() ;
        TModalResult mr = Form2->result ;
        if(mr == 1 )
        {
		remoteIP = Form2->Edit1->Text ;
                remotePort = Form2->Edit2->Text ;

        }
        else
        {
        	ShowMessage("您尚未设置IP 端口，请在连接前重新设置");
        }
        delete Form2 ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	try
        {
      	this->ClientSocket1->Address = remoteIP;
        this->ClientSocket1->Port = remotePort.ToInt() ;
        }
        catch(...)
        {
        	ShowMessage("IP地址或者端口不合法，请重新设置");
        }
        if(this->ClientSocket1->Active == false)
        {
        	this->ClientSocket1->Open() ;
                this->Label5->Caption = "服务端已连接";
                this->Button7->Visible = false ;
                this->Button8->Visible = true ;
        }
        if(this->ClientSocket1->Active == true)
        {

                this->Label5->Caption = "服务端已连接";
                this->Button7->Visible = false ;
                this->Button8->Visible = true ;
        }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
           if(this->ClientSocket1->Active == true)
        {
        	this->ClientSocket1->Close() ;
                this->Button7->Visible = true ;
                this->Button8->Visible = false ;
	       	this->Label5->Caption = "服务端断开";
        }
        if(this->ClientSocket1->Active == false)
        {
        	
                this->Button7->Visible = true ;
                this->Button8->Visible = false ;
	       	this->Label5->Caption = "服务端断开";
        }
        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
	this->StatusBar1->Panels->Items[2]->Text = "服务端连接已经建立";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Connecting(TObject *Sender,
      TCustomWinSocket *Socket)
{
	this->StatusBar1->Panels->Items[2]->Text = "服务端连接正在建立中";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Disconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
         this->StatusBar1->Panels->Items[2]->Text = "服务端连接已经断开";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
	this->StatusBar1->Panels->Items[2]->Text = "收到数据...";
        AnsiString str  = Socket->ReceiveText() ;


        
         this->Memo1->Text =this->Memo1->Text+"\n"+str ;
         RXDCount +=str.Length();
         this->StatusBar1->Panels->Items[0]->Text ="RXD接收字节:"+AnsiString(RXDCount);


        TStringList *list = Parse(str,";");
        for( int i = 0 ;  i < list->Count ; i++)
        {
	 	AnsiString tempStr = 	list->Strings[i] ;
                ExplainToComm(tempStr) ;
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
void __fastcall TForm1::ExplainToComm(AnsiString str)
{

	int pos = str.Pos(":");
        if(pos <=1)
        {
           return ;
        }
        OleVariant var  ;
        AnsiString cmd="/cmd:";
        AnsiString header  = str.SubString(1,pos-1);
        str = str.SubString(pos+1,str.Length()-pos);
	if(header =="/cmd")
        {
           pos = str.Pos(":");
           AnsiString header1 = str.SubString(1,pos-1);
           str = str.SubString(pos+1,str.Length()-pos);
           if(header1=="start")
           {
           	cmd="/cmd:start";
                var = cmd ;

           }
           else
           if(header1=="end")
           {
           	cmd="/cmd:end";
                var = cmd ;

           }
           else
           if(header1=="data")
           {
                pos = str.Pos(":");
           	str = str.SubString(1,pos-1);
           	char data[2] ;
                data[0]= str.ToInt() ;
                data[1]='\0'; 
                cmd="/cmd:data" ;
		char *dest =  cmd.c_str();
                char *add=data ;
                strcat(dest,add);
                AnsiString finalCmd = AnsiString(dest);
                var = finalCmd ;

             
           }
           else
           {
           	return ;
           }


    
      this->MSComm1->Output  = var ;

        }
        else
        {
        	return ;
        }
	char *text ;
        

}

void __fastcall TForm1::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
		ErrorCode = 0 ;
        ShowMessage("socket error "+ErrorCode);	
}
//---------------------------------------------------------------------------

