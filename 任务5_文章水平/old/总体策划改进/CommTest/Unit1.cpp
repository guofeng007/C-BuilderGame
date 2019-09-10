//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MSCommLib_OCX"
#pragma resource "*.dfm"
TForm1 *Form1;
int RXDCount = 0 ;
int TXDCount = 0 ;
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
                ShowMessage("Serial Port can't be opened! owned by other app");
        }
        //check state

         if(this->MSComm1->PortOpen ==  true )
                {
                //reset data
                RXDCount = 0 ;
                TXDCount = 0 ;
                this->Label1->Caption="Port open ";
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
                 ShowMessage("Serial Port can't be Closed! check" );
        }
        //chekc state
         if(this->MSComm1->PortOpen ==  false )
                {
                this->Label1->Caption="Port closed ";
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
