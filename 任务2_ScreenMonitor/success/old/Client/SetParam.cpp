//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SetParam.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
  result = 0 ;
  serverIP = "192.168.255.150";
  serverPort = 900 ;
  level= 1;
  cq = 10 ;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonOkClick(TObject *Sender)
{
	//iplist
            TStringList *iplist = new TStringList();
            iplist->AddStrings(this->ComboBoxServer->Items);
            int index ;
            if(!iplist->Find(this->ComboBoxServer->Text,index))
            {
            	iplist->Append(this->ComboBoxServer->Text); //add
                this->ComboBoxServer->Clear();
                this->ComboBoxServer->Items->AddStrings(iplist);
            }
            delete iplist ;
            
	serverIP = this->ComboBoxServer->Text;
        serverPort = this->EditPort->Text.ToInt();
        level = this->TrackBarDeep->Position ;
        cq = this->TrackBarQuallity->Position*10 ;
        result = 1;

        this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonCancelClick(TObject *Sender)
{
	result = 2 ;
        this->Close();	
}
//---------------------------------------------------------------------------

