//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;


//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
         embedding = NULL ;
         decode  =NULL ;

}
//---------------------------------------------------------------------------


void __fastcall TForm2::N1Click(TObject *Sender)
{

	       //第一次
		if(embedding == NULL )
                {
                embedding = new TForm1(this);
                embedding->WindowState = wsMaximized	 ;
                embedding->Tag = 1 ;
                return ;
                }
		//寻找，找到就显示 返回
                for( int i = 0 ; i < this->MDIChildCount ; i++)
                {
                	if(embedding->Tag == this->MDIChildren[i]->Tag)
                        {
                        	embedding->WindowState = wsMaximized	 ;
                                embedding->Show();
                        	return ;
                        }
                }
                //找不到就新建
                embedding = new TForm1(this);
                embedding->Tag = 1 ;
                embedding->WindowState = wsMaximized	 ;
                return ;


       

}
//---------------------------------------------------------------------------
void __fastcall TForm2::N9Click(TObject *Sender)
{
	this->Close();	
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N7Click(TObject *Sender)
{
	ShowMessage("本程序用来验证可逆数据隐藏域恢复，并且测试相关参数");
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N2Click(TObject *Sender)
{
  		 if(decode == NULL )
                {
                decode = new TForm3(this);
                decode->Tag = 2 ;
                decode->WindowState = wsMaximized  ;
                return ;
                }
		//寻找，找到就显示 返回
                for( int i = 0 ; i < this->MDIChildCount ; i++)
                {
                	if(decode->Tag == this->MDIChildren[i]->Tag)
                        {
                        	decode->WindowState = wsMaximized;
                                decode->Show();
                        	return ;
                        }
                }
                //找不到就新建
                decode = new TForm3(this);
                decode->Tag = 2 ;
               decode->WindowState = wsMaximized	 ;
                return ;


}
//---------------------------------------------------------------------------
void __fastcall TForm2::N4Click(TObject *Sender)
{

	this->Cascade();
       
       
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N5Click(TObject *Sender)
{
	 this->TileMode    = tbHorizontal	 ;
         this->Tile();
        
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N6Click(TObject *Sender)
{
	 this->TileMode = tbVertical ;
         this->Tile();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N8Click(TObject *Sender)
{
	this->ArrangeIcons();	
}
//---------------------------------------------------------------------------

