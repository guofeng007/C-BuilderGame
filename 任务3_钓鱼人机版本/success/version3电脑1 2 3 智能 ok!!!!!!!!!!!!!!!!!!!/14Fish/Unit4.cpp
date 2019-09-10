//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
        point = 14 ;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
        AnsiString str  =this->Edit1->Text ;
       
        try
        {

                point = str.ToInt();
                if(point < 2 )
                {
                        ShowMessage("您输入的点数太小,2-52,请重新输入");
                        return ;
                }
                if(point >52)
                {
                        ShowMessage("您输入的点数太大,2-52,请重新输入");
                        return ;
                }
                this->Close();
        }
        catch(...)
        {
                ShowMessage("输入的不是整数，请重新输入");
        }
}
//---------------------------------------------------------------------------
 