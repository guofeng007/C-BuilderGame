//---------------------------------------------------------------------------


#pragma hdrstop

#include "Unit4My.h"


//---------------------------------------------------------------------------
My::My(Card *card1 ,Card *card2 ,Card *card3,TImage *image1 ,TImage *image2 ,TImage *image3)
{
        cards = new TObjectList(true);
        cards->Capacity = 3 ;
        cards->Add(card1);
        cards->Add(card2);
        cards->Add(card3);
        images.Length = 3;
        images[0] = image1 ;
        images[1] = image2 ;
        images[2] = image3 ;
}
void __fastcall My::Destroy()
{
        delete cards ;
}
void __fastcall My::addCard(Card *card)
{

        //care full ;
        
        for(int i = 0 ;  i < cards->Count ; i++ )
        {
                Card *c = (Card *) this->cards->operator [](i);
                if(c->isLive == false )
                {

                        this->cards->Remove(c); 
                        this->cards->Insert(i,card);


                        refresh();
                     return ;
                }
        }
        //if no replace the first one
         this->cards->Remove(0); 
         this->cards->Insert(0,card);
         refresh();
}
Card* __fastcall My::getCard(int index)
{
        if(index < this->cards->Count)
        {
                return (Card *)this->cards->operator [](index);
        }
        else
        {
                return NULL ;
        }
}
void __fastcall My::refresh()
{
        Card *c  ;
        c =(Card *) this->cards->operator [](0) ;
        images[0]->Picture->Bitmap = c->image ;
        c =(Card *) this->cards->operator [](1) ;
        images[1]->Picture->Bitmap = c->image ;
        c =(Card *) this->cards->operator [](2) ;
        images[2]->Picture->Bitmap = c->image ;
}
bool __fastcall My::setIsLive(int index ,bool isLive)
{
        if(index < this->cards->Count)
        {

                Card *c = (Card *)this->cards->operator [](index);
                c->isLive = isLive ;
                 
                return true ;
        }
        else
        {
                return false ;
        }


}


#pragma package(smart_init)
