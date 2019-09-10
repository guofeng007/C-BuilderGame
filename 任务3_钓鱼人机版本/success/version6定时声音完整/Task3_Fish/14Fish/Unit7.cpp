//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm7::Button1Click(TObject *Sender)
{
        GameTime = 5 ;
        try
        {
                GameTime = this->Edit1->Text.ToInt();
                if(GameTime<5)
                {
                        ShowMessage("出牌时间太小5-100秒") ;
                        return ;
                }
                if(GameTime >100)
                {
                        ShowMessage("出牌时间太大5-100秒");
                        return ;
                }
                this->Close();
        }
        catch(...)
        {
                ShowMessage("输入的不是整数请输入5-100");
        }
}
//---------------------------------------------------------------------------
 