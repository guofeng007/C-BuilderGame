//---------------------------------------------------------------------------


#pragma hdrstop

#include "Unit2.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
__fastcall Card::Card()
{
	this->isLive = false ;
}

__fastcall Card::Card(int cardLevel , int cardNo)
 {
 	this->cardLevel = cardLevel ;
        this->cardNo = cardNo ;
	this->cardPath =  MakePath();
        this->isLive = true ;
        this->image = new Graphics::TBitmap();
        this->image->LoadFromFile(cardPath);

 }
 AnsiString Card::MakePath()
 {
      	AnsiString first = AnsiString(cardLevel);
        AnsiString second = "";
        AnsiString path = "";
        if(cardNo < 10 )
        {
        	second +="0";
        }
        second +=AnsiString(cardNo);
        path = "images/"+first+second+".bmp";
        return path ;
 }
 __fastcall Card::~Card()
   {
	delete this->image ;
   }

