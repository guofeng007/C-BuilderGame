//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
        this->result =0 ;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BtnSelectFontClick(TObject *Sender)
{
        this->FontDialog1->Execute();        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
          this->result = 1 ;
        this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
        this->result = 2 ;
        this->Close();
}
//---------------------------------------------------------------------------
