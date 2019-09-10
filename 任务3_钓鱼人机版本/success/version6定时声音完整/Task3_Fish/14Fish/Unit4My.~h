//---------------------------------------------------------------------------

#ifndef Unit4MyH
#define Unit4MyH

#include <vcl.h>
#include "Unit2.h"

//---------------------------------------------------------------------------
class My : public TObject
{
        private:
             TObjectList *cards ;
             DynamicArray<TImage *> images ;
	public:
            My(Card *card1 ,Card *card2 ,Card *card3,TImage *image1 ,TImage *image2 ,TImage *image3);
           //~My
            void __fastcall Destroy();
            void __fastcall addCard(Card *c);
            Card* __fastcall getCard(int index);
            bool __fastcall setIsLive(int index,bool isLive);
            void __fastcall refresh();

            
};
#endif
