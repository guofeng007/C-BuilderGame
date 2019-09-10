//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
#include "Graphics.hpp"
//---------------------------------------------------------------------------
class Card : public TObject
{
	public:
	int cardLevel ; //4 3 2 1  blade heart parade suqare
        int cardNo    ; //A 2 3  10 J Q K
        bool isLive ;      
        AnsiString cardPath ;
       	Graphics::TBitmap *image ; //map card files 401  410 411 412 413
        AnsiString MakePath();
         __fastcall Card();
        __fastcall Card(int cardLevel , int cardNo);
        void __fastcall Destroy();      
};
 
#endif
 