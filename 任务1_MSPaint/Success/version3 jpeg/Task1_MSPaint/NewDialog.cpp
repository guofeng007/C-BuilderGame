//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "NewDialog.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	result = 0 ;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	this->result = 1 ;
        try
        {
             width = this->Edit1->Text.ToInt();
             height = this->Edit2->Text.ToInt();
             this->Close();
        }
        catch(...)
        {
        	ShowMessage("请输入整数(非空)");
                return ;
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
       this->result = 2 ;
        this->Close();
}
//---------------------------------------------------------------------------
