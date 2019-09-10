//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button1Click(TObject *Sender)
{
        num = 1 ;
        try
        {
              num = this->Edit1->Text.ToInt();
              if(num <1)
              {
                ShowMessage("输入数字太小  1-8 请重新输入");
                return ;
              }
              if(num > 8)
              {
                ShowMessage("输入数字太大， 1-8 请重新输入");
                return ;
              }
              this->Close();
        }
        catch(...)
        {
                ShowMessage("请输入整数");
                return ;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button2Click(TObject *Sender)
{
        Application->Terminate();        
}
//---------------------------------------------------------------------------
