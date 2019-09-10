//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap *bitmapPosition  ; //全局占位图片
Graphics::TBitmap *bitmapBack ;
Card  *cards[53] ;  //total cards     //数据结构使用队列 无用的卡放到最后，，这样就不在搜索了，每次从头开始找一定范围内的随即
Card  *myFish[3] ;
Card  *opponentFish[3];
Card  *poolFish[8];
int MyChoose ; //0 1 2 每次选择之后的
bool MyImage1State = false ;
bool MyImage2State = false ;
bool MyImage3State = false ;
int  WINSCORE = 14 ;
int count = 52  ;
int GameLevel= 1 ;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	this->MyScoreInt = 0 ;
        this->OpponnetScoreInt = 0 ;
	bitmapPosition = new Graphics::TBitmap() ;
        bitmapBack      = new Graphics::TBitmap() ;
        bitmapPosition->LoadFromFile("images/position.bmp");
        bitmapBack->LoadFromFile("images/back.bmp");
        Init();

       

}
void __fastcall TForm1::Init()
{
	 //fish pool place holder
	MakePosition(this->PoolImage1);
        MakePosition(this->PoolImage2);
        MakePosition(this->PoolImage3);
        MakePosition(this->PoolImage4);
        MakePosition(this->PoolImage5);
        MakePosition(this->PoolImage6);
        MakePosition(this->PoolImage7);
        MakePosition(this->PoolImage8);


        //opponentlast place holder
        MakePosition(this->OpponentLast1);
        MakePosition(this->OpponentLast2);
        MakePosition(this->OpponentLast3);
        MakePosition(this->OpponentLast4);
        //opponent placeholder
        MakePosition(this->OpponentImage1);
        MakePosition(this->OpponentImage2);
        MakePosition(this->OpponentImage3);


        //mylast place holder
        MakePosition(this->MyLast1);
        MakePosition(this->MyLast2);
        MakePosition(this->MyLast3);
        MakePosition(this->MyLast4);
        //mylast holder
        MakePosition(this->MyImage1);
        MakePosition(this->MyImage2);
        MakePosition(this->MyImage3);

        InitCards();
        InitFish();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MakePosition(TImage * image )
{
        image->Picture->Bitmap = bitmapPosition ;
}
void __fastcall TForm1::MakeBack(TImage *image)
{
	 image->Picture->Bitmap = bitmapBack ;  
}
void __fastcall TForm1::InitCards()
{
         for(int i = 0  ; i < 52  ; i++ )
         {
         	cards[i] = new Card(4-i/13, i%13+1);
         }
         cards[52] = new Card();  //false card
        
}
void __fastcall TForm1::InitFish()
{
	for(int i = 0 ;  i < 3 ; i++)
        {
        	myFish[i] = NULL ;
                opponentFish[i] = NULL ;

        }
        for(int j = 0 ; j < 8  ; j++)
        {
        	poolFish[j] = NULL ;
        }
}
void __fastcall TForm1::DestroyCards()
{
       for(int i = 0  ; i < 53  ; i++ )
         {
		delete 	cards[i];
         }
         
}


void __fastcall TForm1::FormDestroy(TObject *Sender)
{
	  delete bitmapPosition ;
          delete bitmapBack ;	
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MenuStartClick(TObject *Sender)
{
	this->MenuStart->Enabled = false ;
        this->MenuRestart->Enabled = true ;
	//Opponent back
	MakeBack(this->OpponentImage1);
	MakeBack(this->OpponentImage2);
	MakeBack(this->OpponentImage3);

        
        //choose 8 fish
         //1
         int pool = GetOneCard();
         poolFish[0] = cards[pool];
         this->PoolImage1->Picture->Bitmap = cards[pool]->image ;
         //2
         pool = GetOneCard();
         poolFish[1] = cards[pool];
         this->PoolImage2->Picture->Bitmap = cards[pool]->image ;
          //3
         pool = GetOneCard();
         poolFish[2] = cards[pool];
         this->PoolImage3->Picture->Bitmap = cards[pool]->image ;
           //4
         pool = GetOneCard();
         poolFish[3] = cards[pool];
         this->PoolImage4->Picture->Bitmap = cards[pool]->image ;

         //5
         pool = GetOneCard();
         poolFish[4] = cards[pool];
         this->PoolImage5->Picture->Bitmap = cards[pool]->image ;

         //6
         pool = GetOneCard();
         poolFish[5] = cards[pool];
         this->PoolImage6->Picture->Bitmap = cards[pool]->image ;

         //7
         pool = GetOneCard();
         poolFish[6] = cards[pool];
         this->PoolImage7->Picture->Bitmap = cards[pool]->image ;

         //8
         pool = GetOneCard();
         poolFish[7] = cards[pool];
         this->PoolImage8->Picture->Bitmap = cards[pool]->image ;

        //send my 3
        //1
        int my = GetOneCard();
        myFish[0] = cards[my];
        this->MyImage1->Picture->Bitmap = cards[my]->image ;
        //2
        my = GetOneCard();
        myFish[1] = cards[my];
        this->MyImage2->Picture->Bitmap = cards[my]->image ;
        //3
        my = GetOneCard();
        myFish[2] = cards[my];
        this->MyImage3->Picture->Bitmap = cards[my]->image ;


        //send opponent 3
        //1
        int opponent = GetOneCard();
        opponentFish[0] = cards[opponent];
        this->OpponentImage1->Picture->Bitmap = cards[opponent]->image;
        //2
        opponent = GetOneCard();
        opponentFish[1] = cards[opponent];
        this->OpponentImage2->Picture->Bitmap = cards[opponent]->image;
        //3
        opponent = GetOneCard();
        opponentFish[2] = cards[opponent];
        this->OpponentImage3->Picture->Bitmap = cards[opponent]->image;


}
int   __fastcall TForm1::GetOneCard()
{
        //使用时间种子初始化随机值
        randomize();
	int place = random(count) ;
        cards[count] = cards[place] ;
        this->LabelCardsCount->Caption = count - 1 ;
        if(count == 1)
        {
        	if(this->MyScoreInt > this->OpponnetScoreInt)
                {
			ShowMessage("你赢了");
                }
                else
                if(this->MyScoreInt == this->OpponnetScoreInt)
                {
                       ShowMessage("打成平手");
                }
                else
                {
                	ShowMessage("电脑赢了");
                }

                // 游戏在这里结束
                this->MenuRestart->Click();

                return 0 ;
        }
	return   count-- ;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::MenuExitClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::MenuHelpClick(TObject *Sender)
{
        Form3 = new TForm3(this);
        Form3->ShowModal() ;
        delete Form3 ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuRestartClick(TObject *Sender)
{
	this->MenuStart->Enabled = true ;
        this->MenuRestart->Enabled = false ;
        
        count = 52 ;
	this->LabelCardsCount->Caption = 52 ;


        this->MyScoreInt = 0 ;
        this->MyScoreLabel->Caption = 0 ;
        this->OpponnetScoreInt = 0 ;
        this->OpponentScoreLabel->Caption = 0 ;


	Init();
        this->MenuStart->Click();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::MyImage1Click(TObject *Sender)
{
         if(MyImage1State == false )
         {
         	//choose
         	this->MyImage1->Top -= 10 ;
                MyImage1State = true ;

         }
         else
         {
         	//no choose
               	this->MyImage1->Top += 10 ;
                MyImage1State = false ;
         }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::MyImage2Click(TObject *Sender)
{
	 if(MyImage2State == false )
         {
         	//choose
         	this->MyImage2->Top -= 10 ;
                MyImage2State = true ;

         }
         else
         {
         	//no choose
               	this->MyImage2->Top += 10 ;
                MyImage2State = false ;
         }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MyImage3Click(TObject *Sender)
{
	 if(MyImage3State == false )
         {
         	//choose
         	this->MyImage3->Top -= 10 ;
                MyImage3State = true ;

         }
         else
         {
         	//no choose
               	this->MyImage3->Top += 10 ;
                MyImage3State = false ;
         }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PoolImage1Click(TObject *Sender)
{
	//1 poolFish1
        int sum = 0 ;
        int score = 0  ;
        if(poolFish[0] != NULL)
        {
        	if(MyImage1State == true)
                {
                      sum +=myFish[0]->cardNo ;
                      score += myFish[0]->cardLevel ;
                }

        	if(MyImage2State == true)
                {
                      sum +=myFish[1]->cardNo  ;
                      score += myFish[1]->cardLevel ;
                }

        	if(MyImage3State == true)
                {
                      sum +=myFish[2]->cardNo   ;
                      score += myFish[2]->cardLevel ;
                }
                sum += poolFish[0]->cardNo ;
                score += poolFish[0]->cardLevel ;

                //钓鱼成功
               if( sum == WINSCORE)
               {
               //计算分数
        	 this->MyScoreInt += score ;
                 this->MyScoreLabel->Caption =   this->MyScoreInt  ;
                  //显示上次的牌
                 if(MyImage1State == true )
                 {
                        this->MyLast1->Picture->Bitmap = this->MyImage1->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast1->Picture->Bitmap  =  bitmapPosition ;
                 }
                 if(MyImage2State == true )
                 {
                        this->MyLast2->Picture->Bitmap = this->MyImage2->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast2->Picture->Bitmap  =  bitmapPosition ;
                 }
                 if(MyImage3State == true )
                 {
                        this->MyLast3->Picture->Bitmap = this->MyImage3->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast3->Picture->Bitmap  =  bitmapPosition ;
                 }

                 this->MyLast4->Picture->Bitmap = poolFish[0]->image ;




                 //鱼池发一牌
                 int pos = GetOneCard();
                 poolFish[0] = cards[pos];
                 this->PoolImage1->Picture->Bitmap = poolFish[0]->image ;




               //发牌
                   ReSendCard();

               }
               //钓鱼失败
               else
               {
               	      ReSendCard();	// 什么也不做，发牌 	// 什么也不做，让玩家从新选择
               }
            this->CallOponent();
        }
}
//---------------------------------------------------------------------------
//发一张牌
void __fastcall TForm1::ReSendCard()
{
//一次检测每个图片是否选择 是否需要更新
	int pos = 0 ;
	if(MyImage1State == true)
        {
	 	pos = this->GetOneCard();
                MyImage1State = false ;
                this->MyImage1->Top +=10 ;
                myFish[0] = cards[pos] ;
                this->MyImage1->Picture->Bitmap = cards[pos]->image ;
        }

        if(MyImage2State == true)
        {
	 	pos = this->GetOneCard();
                MyImage2State = false ;
                this->MyImage2->Top +=10 ;
                myFish[1] = cards[pos] ;
                this->MyImage2->Picture->Bitmap = cards[pos]->image ;
        }
        if(MyImage3State == true)
        {
	 	pos = this->GetOneCard();
                MyImage3State = false ;
                this->MyImage3->Top +=10 ;
                myFish[2] = cards[pos] ;
                this->MyImage3->Picture->Bitmap = cards[pos]->image ;
        }
}


void __fastcall TForm1::PoolImage2Click(TObject *Sender)
{
	//pool2
        int sum = 0 ;
        int score = 0  ;
        if(poolFish[1] != NULL)
        {
        	if(MyImage1State == true)
                {
                      sum +=myFish[0]->cardNo ;
                      score += myFish[0]->cardLevel ;
                }

        	if(MyImage2State == true)
                {
                      sum +=myFish[1]->cardNo  ;
                      score += myFish[1]->cardLevel ;
                }

        	if(MyImage3State == true)
                {
                      sum +=myFish[2]->cardNo   ;
                      score += myFish[2]->cardLevel ;
                }
                sum += poolFish[1]->cardNo ;
                score += poolFish[1]->cardLevel ;

                //钓鱼成功
               if( sum == WINSCORE)
               {
               //计算分数
        	 this->MyScoreInt += score ;
                 this->MyScoreLabel->Caption =   this->MyScoreInt  ;
                 //显示上一次玩家牌
                 if(MyImage1State == true )
                 {
                        this->MyLast1->Picture->Bitmap = this->MyImage1->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast1->Picture->Bitmap  =  bitmapPosition ;
                 }
                 if(MyImage2State == true )
                 {
                        this->MyLast2->Picture->Bitmap = this->MyImage2->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast2->Picture->Bitmap  =  bitmapPosition ;
                 }
                 if(MyImage3State == true )
                 {
                        this->MyLast3->Picture->Bitmap = this->MyImage3->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast3->Picture->Bitmap  =  bitmapPosition ;
                 }
                 this->MyLast4->Picture->Bitmap = poolFish[1]->image ;
                 //鱼池发一牌
                 int pos = GetOneCard();
                 poolFish[1] = cards[pos];
                 this->PoolImage2->Picture->Bitmap = poolFish[1]->image ;
               //发牌
                   ReSendCard();

               }
               //钓鱼失败
               else
               {
               	       ReSendCard();	// 什么也不做，发牌 	// 什么也不做，让玩家从新选择
               }
              this->CallOponent();               

        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PoolImage3Click(TObject *Sender)
{
	//pool3
        int sum = 0 ;
        int score = 0  ;
        if(poolFish[2] != NULL)
        {
        	if(MyImage1State == true)
                {
                      sum +=myFish[0]->cardNo ;
                      score += myFish[0]->cardLevel ;
                }

        	if(MyImage2State == true)
                {
                      sum +=myFish[1]->cardNo  ;
                      score += myFish[1]->cardLevel ;
                }

        	if(MyImage3State == true)
                {
                      sum +=myFish[2]->cardNo   ;
                      score += myFish[2]->cardLevel ;
                }
                sum += poolFish[2]->cardNo ;
                score += poolFish[2]->cardLevel ;

                //钓鱼成功
               if( sum == WINSCORE)
               {
               //计算分数
        	 this->MyScoreInt += score ;
                 this->MyScoreLabel->Caption =   this->MyScoreInt  ;
                //显示玩家上一轮分数
                  if(MyImage1State == true )
                 {
                        this->MyLast1->Picture->Bitmap = this->MyImage1->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast1->Picture->Bitmap  =  bitmapPosition ;
                 }
                 if(MyImage2State == true )
                 {
                        this->MyLast2->Picture->Bitmap = this->MyImage2->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast2->Picture->Bitmap  =  bitmapPosition ;
                 }
                 if(MyImage3State == true )
                 {
                        this->MyLast3->Picture->Bitmap = this->MyImage3->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast3->Picture->Bitmap  =  bitmapPosition ;
                 }

                 this->MyLast4->Picture->Bitmap = poolFish[2]->image ;
                 //鱼池发一牌
                 int pos = GetOneCard();
                 poolFish[2] = cards[pos];
                 this->PoolImage3->Picture->Bitmap = poolFish[2]->image ;
               //发牌
                   ReSendCard();

               }
               //钓鱼失败
               else
               {
               	      ReSendCard();	// 什么也不做，发牌 	// 什么也不做，让玩家从新选择
               }
              this->CallOponent();               

        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PoolImage4Click(TObject *Sender)
{
	//pool4
        int sum = 0 ;
        int score = 0  ;
        if(poolFish[3] != NULL)
        {
        	if(MyImage1State == true)
                {
                      sum +=myFish[0]->cardNo ;
                      score += myFish[0]->cardLevel ;
                }

        	if(MyImage2State == true)
                {
                      sum +=myFish[1]->cardNo  ;
                      score += myFish[1]->cardLevel ;
                }

        	if(MyImage3State == true)
                {
                      sum +=myFish[2]->cardNo   ;
                      score += myFish[2]->cardLevel ;
                }
                sum += poolFish[3]->cardNo ;
                score += poolFish[3]->cardLevel ;

                //钓鱼成功
               if( sum == WINSCORE)
               {
               //计算分数
        	 this->MyScoreInt += score ;
                 this->MyScoreLabel->Caption =   this->MyScoreInt  ;
                       //
                     
                  if(MyImage1State == true )
                 {
                        this->MyLast1->Picture->Bitmap = this->MyImage1->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast1->Picture->Bitmap  =  bitmapPosition ;
                 }
                 if(MyImage2State == true )
                 {
                        this->MyLast2->Picture->Bitmap = this->MyImage2->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast2->Picture->Bitmap  =  bitmapPosition ;
                 }
                 if(MyImage3State == true )
                 {
                        this->MyLast3->Picture->Bitmap = this->MyImage3->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast3->Picture->Bitmap  =  bitmapPosition ;
                 }
                 this->MyLast4->Picture->Bitmap = poolFish[3]->image ;
                 //鱼池发一牌
                 int pos = GetOneCard();
                 poolFish[3] = cards[pos];
                 this->PoolImage4->Picture->Bitmap = poolFish[3]->image ;
               //发牌
                   ReSendCard();

                   //通知电脑开始处理了
               }
               //钓鱼失败
               else
               {
               	      ReSendCard();	// 什么也不做，发牌 
               }
              this->CallOponent();
        }

}
//电脑所有的逻辑存放在这里
void __fastcall TForm1::CallOponent()
{
    if(GameLevel == 1)
    {
    //一张 0张
       for(int i = 0 ;  i < 3 ; i++ )
        //opponent 1 2 3
        {
        	for(int j = 0 ;  j < 8 ; j++)
                // pool 1 2 3 4 
                {

                       if( opponentFish[i]->cardNo + poolFish[j]->cardNo == WINSCORE )
                       {
                       //清除之前显示
                       //前三张
                       this->OpponentLast1->Picture->Bitmap = bitmapPosition ;
                       this->OpponentLast2->Picture->Bitmap = bitmapPosition ;
                       this->OpponentLast3->Picture->Bitmap = bitmapPosition ;
                       switch (i)
                       {
                         case 0: this->OpponentLast1->Picture->Bitmap =opponentFish[i]->image  ;
                         break;
                         case 1: this->OpponentLast2->Picture->Bitmap =opponentFish[i]->image;
                         break;
                         case 2: this->OpponentLast3->Picture->Bitmap =opponentFish[i]->image;
                         break;
                         default: ; break ;
                       }

                        //最后一张
                       
                       this->OpponentLast4->Picture->Bitmap = poolFish[j]->image ;
                              int score  = 0 ;
                              score = opponentFish[i]->cardLevel+poolFish[j]->cardLevel ;
                              this->OpponnetScoreInt += score ;
                              this->OpponentScoreLabel->Caption = this->OpponnetScoreInt ;
                              PCResend(i,j);

                              //success
                              return ;
                       }

                }
        }
        //fail at last
        //resend  recard 默认丢掉第一个位置
        PCResend(0,0);
     }
     else
     if(GameLevel ==2)
     {
        //两张  一张 0张              
        //两张

        	for(int j = 0 ;  j < 8 ; j++)
                // pool 1 2 3 4 
                {
                       //0 1
                       if( (opponentFish[0]->cardNo+opponentFish[1]->cardNo + poolFish[j]->cardNo) == WINSCORE )
                       {
                       //清除之前显示
                       //前三张
                       this->OpponentLast1->Picture->Bitmap = bitmapPosition ;
                       this->OpponentLast2->Picture->Bitmap = bitmapPosition ;
                       this->OpponentLast3->Picture->Bitmap = bitmapPosition ;


                       this->OpponentLast1->Picture->Bitmap =opponentFish[0]->image  ; 
                       this->OpponentLast2->Picture->Bitmap =opponentFish[1]->image;


                        //最后一张
                       
                       this->OpponentLast4->Picture->Bitmap = poolFish[j]->image ;
                              int score  = 0 ;
                              score = opponentFish[0]->cardLevel+opponentFish[1]->cardLevel+poolFish[j]->cardLevel ;
                              this->OpponnetScoreInt += score ;
                              this->OpponentScoreLabel->Caption = this->OpponnetScoreInt ;
                              PCResend(0,j);
                              PCResend(0,8);
                              //success
                              return ;
                       }
                       //0 2
                        if( (opponentFish[0]->cardNo+opponentFish[2]->cardNo + poolFish[j]->cardNo) == WINSCORE )
                       {
                       //清除之前显示
                       //前三张
                       this->OpponentLast1->Picture->Bitmap = bitmapPosition ;
                       this->OpponentLast2->Picture->Bitmap = bitmapPosition ;
                       this->OpponentLast3->Picture->Bitmap = bitmapPosition ;


                       this->OpponentLast1->Picture->Bitmap =opponentFish[0]->image  ; 
                       this->OpponentLast3->Picture->Bitmap =opponentFish[2]->image;


                        //最后一张
                       
                       this->OpponentLast4->Picture->Bitmap = poolFish[j]->image ;
                              int score  = 0 ;
                              score = opponentFish[0]->cardLevel+opponentFish[2]->cardLevel+poolFish[j]->cardLevel ;
                              this->OpponnetScoreInt += score ;
                              this->OpponentScoreLabel->Caption = this->OpponnetScoreInt ;
                              PCResend(0,j);
                              PCResend(2,8);
                              //success
                              return ;
                       }
                       // 1 2
                        if( (opponentFish[1]->cardNo+opponentFish[2]->cardNo + poolFish[j]->cardNo) == WINSCORE )
                       {
                       //清除之前显示
                       //前三张
                       this->OpponentLast1->Picture->Bitmap = bitmapPosition ;
                       this->OpponentLast2->Picture->Bitmap = bitmapPosition ;
                       this->OpponentLast3->Picture->Bitmap = bitmapPosition ;


                       this->OpponentLast2->Picture->Bitmap =opponentFish[1]->image  ;
                       this->OpponentLast3->Picture->Bitmap =opponentFish[2]->image;


                        //最后一张
                       
                       this->OpponentLast4->Picture->Bitmap = poolFish[j]->image ;
                              int score  = 0 ;
                              score = opponentFish[1]->cardLevel+opponentFish[2]->cardLevel+poolFish[j]->cardLevel ;
                              this->OpponnetScoreInt += score ;
                              this->OpponentScoreLabel->Caption = this->OpponnetScoreInt ;
                              PCResend(1,j);
                              PCResend(2,8);
                              //success
                              return ;
                       }

                }
       

        //一张
        for(int i = 0 ;  i < 3 ; i++ )
        //opponent 1 2 3
        {
        	for(int j = 0 ;  j < 8 ; j++)
                // pool 1 2 3 4 
                {

                       if( opponentFish[i]->cardNo + poolFish[j]->cardNo == WINSCORE )
                       {
                       //清除之前显示
                       //前三张
                       this->OpponentLast1->Picture->Bitmap = bitmapPosition ;
                       this->OpponentLast2->Picture->Bitmap = bitmapPosition ;
                       this->OpponentLast3->Picture->Bitmap = bitmapPosition ;
                       switch (i)
                       {
                         case 0: this->OpponentLast1->Picture->Bitmap =opponentFish[i]->image  ;
                         break;
                         case 1: this->OpponentLast2->Picture->Bitmap =opponentFish[i]->image;
                         break;
                         case 2: this->OpponentLast3->Picture->Bitmap =opponentFish[i]->image;
                         break;
                         default: ; break ;
                       }

                        //最后一张
                       
                       this->OpponentLast4->Picture->Bitmap = poolFish[j]->image ;
                              int score  = 0 ;
                              score = opponentFish[i]->cardLevel+poolFish[j]->cardLevel ;
                              this->OpponnetScoreInt += score ;
                              this->OpponentScoreLabel->Caption = this->OpponnetScoreInt ;
                              //对手发两张牌 鱼池第二次不发 
                              PCResend(0,j);
                               PCResend(1,j);

                              //success
                              return ;
                       }

                }
        }
      
        //resend  recard 默认丢掉第一个位置
        PCResend(0,0);

     }
     else
     if(GameLevel == 3)
     {
        //一张或者两张或者三张
        //两张
                //三张
              	for(int j = 0 ;  j < 8 ; j++)
                {
                 if( (opponentFish[0]->cardNo+opponentFish[1]->cardNo+opponentFish[2]->cardNo + poolFish[j]->cardNo) == WINSCORE )
                       {
                       

                       this->OpponentLast1->Picture->Bitmap =opponentFish[0]->image  ; 
                       this->OpponentLast2->Picture->Bitmap =opponentFish[1]->image;
                        this->OpponentLast3->Picture->Bitmap = opponentFish[2]->image;


                        //最后一张

                       this->OpponentLast4->Picture->Bitmap = poolFish[j]->image ;
                              int score  = 0 ;
                              score = opponentFish[0]->cardLevel+opponentFish[1]->cardLevel+opponentFish[2]->cardLevel+poolFish[j]->cardLevel ;
                              this->OpponnetScoreInt += score ;
                              this->OpponentScoreLabel->Caption = this->OpponnetScoreInt ;
                              PCResend(0,j);
                              PCResend(1,8);
                              PCResend(2,8);                              
                              //success
                              return ;
                       }
                 }


        	for(int j = 0 ;  j < 8 ; j++)
                // pool 1 2 3 4 
                {
                       //0 1
                       if( (opponentFish[0]->cardNo+opponentFish[1]->cardNo + poolFish[j]->cardNo) == WINSCORE )
                       {
                       //清除之前显示
                       //前三张
                       this->OpponentLast1->Picture->Bitmap = bitmapPosition ;
                       this->OpponentLast2->Picture->Bitmap = bitmapPosition ;
                       this->OpponentLast3->Picture->Bitmap = bitmapPosition ;


                       this->OpponentLast1->Picture->Bitmap =opponentFish[0]->image  ; 
                       this->OpponentLast2->Picture->Bitmap =opponentFish[1]->image;


                        //最后一张

                       this->OpponentLast4->Picture->Bitmap = poolFish[j]->image ;
                              int score  = 0 ;
                              score = opponentFish[0]->cardLevel+opponentFish[1]->cardLevel+poolFish[j]->cardLevel ;
                              this->OpponnetScoreInt += score ;
                              this->OpponentScoreLabel->Caption = this->OpponnetScoreInt ;
                              PCResend(0,j);
                              PCResend(1,8);
                              //success
                              return ;
                       }
                       //0 2
                        if( (opponentFish[0]->cardNo+opponentFish[2]->cardNo + poolFish[j]->cardNo) == WINSCORE )
                       {
                       //清除之前显示
                       //前三张
                       this->OpponentLast1->Picture->Bitmap = bitmapPosition ;
                       this->OpponentLast2->Picture->Bitmap = bitmapPosition ;
                       this->OpponentLast3->Picture->Bitmap = bitmapPosition ;


                       this->OpponentLast1->Picture->Bitmap =opponentFish[0]->image  ; 
                       this->OpponentLast3->Picture->Bitmap =opponentFish[2]->image;


                        //最后一张
                       
                       this->OpponentLast4->Picture->Bitmap = poolFish[j]->image ;
                              int score  = 0 ;
                              score = opponentFish[0]->cardLevel+opponentFish[2]->cardLevel+poolFish[j]->cardLevel ;
                              this->OpponnetScoreInt += score ;
                              this->OpponentScoreLabel->Caption = this->OpponnetScoreInt ;
                              PCResend(0,j);
                              PCResend(2,8);
                              //success
                              return ;
                       }
                       // 1 2
                        if( (opponentFish[1]->cardNo+opponentFish[2]->cardNo + poolFish[j]->cardNo) == WINSCORE )
                       {
                       //清除之前显示
                       //前三张
                       this->OpponentLast1->Picture->Bitmap = bitmapPosition ;
                       this->OpponentLast2->Picture->Bitmap = bitmapPosition ;
                       this->OpponentLast3->Picture->Bitmap = bitmapPosition ;


                       this->OpponentLast2->Picture->Bitmap =opponentFish[1]->image  ;
                       this->OpponentLast3->Picture->Bitmap =opponentFish[2]->image;


                        //最后一张
                       
                       this->OpponentLast4->Picture->Bitmap = poolFish[j]->image ;
                              int score  = 0 ;
                              score = opponentFish[1]->cardLevel+opponentFish[2]->cardLevel+poolFish[j]->cardLevel ;
                              this->OpponnetScoreInt += score ;
                              this->OpponentScoreLabel->Caption = this->OpponnetScoreInt ;
                              PCResend(1,j);
                              PCResend(2,8);
                              //success
                              return ;
                       }

                }
       

        //一张
        for(int i = 0 ;  i < 3 ; i++ )
        //opponent 1 2 3
        {
        	for(int j = 0 ;  j < 8 ; j++)
                // pool 1 2 3 4 
                {

                       if( opponentFish[i]->cardNo + poolFish[j]->cardNo == WINSCORE )
                       {
                       //清除之前显示
                       //前三张
                       this->OpponentLast1->Picture->Bitmap = bitmapPosition ;
                       this->OpponentLast2->Picture->Bitmap = bitmapPosition ;
                       this->OpponentLast3->Picture->Bitmap = bitmapPosition ;
                       switch (i)
                       {
                         case 0: this->OpponentLast1->Picture->Bitmap =opponentFish[i]->image  ;
                         break;
                         case 1: this->OpponentLast2->Picture->Bitmap =opponentFish[i]->image;
                         break;
                         case 2: this->OpponentLast3->Picture->Bitmap =opponentFish[i]->image;
                         break;
                         default: ; break ;
                       }

                        //最后一张
                       
                       this->OpponentLast4->Picture->Bitmap = poolFish[j]->image ;
                              int score  = 0 ;
                              score = opponentFish[i]->cardLevel+poolFish[j]->cardLevel ;
                              this->OpponnetScoreInt += score ;
                              this->OpponentScoreLabel->Caption = this->OpponnetScoreInt ;
                              //对手发两张牌 鱼池第二次不发 
                              PCResend(0,j);
                               PCResend(1,j);

                              //success
                              return ;
                       }

                }
        }
      
        //resend  recard 默认丢掉第一个位置
        PCResend(0,0);
     }

}
//电脑重新发牌
void __fastcall TForm1::PCResend(int i , int j)
{    //对手发牌
      int pos  =GetOneCard();
      opponentFish[i] = cards[pos];
      switch (i)
      {
        case 0:this->OpponentImage1->Picture->Bitmap = opponentFish[i]->image  ;
        break;
        case 1:this->OpponentImage2->Picture->Bitmap = opponentFish[i]->image ;
        break;
        case 2:this->OpponentImage3->Picture->Bitmap = opponentFish[i]->image ;
        break;
        default: ;
      }

      //鱼池发牌
      if(j > 7)
      {
      return ;
      }
      pos = GetOneCard();
      poolFish[j] = cards[pos];
      switch (j)
      {

        case 0:this->PoolImage1->Picture->Bitmap = poolFish[j]->image  ;
        break;
        case 1:this->PoolImage2->Picture->Bitmap = poolFish[j]->image ;
        break;
        case 2:this->PoolImage3->Picture->Bitmap = poolFish[j]->image ;
        break;
        case 3:this->PoolImage4->Picture->Bitmap = poolFish[j]->image ;
        break;
        case 4:this->PoolImage5->Picture->Bitmap = poolFish[j]->image  ;
        break;
        case 5:this->PoolImage6->Picture->Bitmap = poolFish[j]->image ;
        break;
        case 6:this->PoolImage7->Picture->Bitmap = poolFish[j]->image ;
        break;
        case 7:this->PoolImage8->Picture->Bitmap = poolFish[j]->image ;
        break;
        default: ;
      }


}

//---------------------------------------------------------------------------

void __fastcall TForm1::N1Click(TObject *Sender)
{

        Form4 = new TForm4(this);
        if(Form4->ShowModal())
        {
                        WINSCORE = Form4->point ;
        }
        delete Form4 ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PoolImage5Click(TObject *Sender)
{
        	//pool5
        int sum = 0 ;
        int score = 0  ;
        if(poolFish[4] != NULL)
        {
        	if(MyImage1State == true)
                {
                      sum +=myFish[0]->cardNo ;
                      score += myFish[0]->cardLevel ;
                }

        	if(MyImage2State == true)
                {
                      sum +=myFish[1]->cardNo  ;
                      score += myFish[1]->cardLevel ;
                }

        	if(MyImage3State == true)
                {
                      sum +=myFish[2]->cardNo   ;
                      score += myFish[2]->cardLevel ;
                }
                sum += poolFish[4]->cardNo ;
                score += poolFish[4]->cardLevel ;

                //钓鱼成功
               if( sum == WINSCORE)
               {
               //计算分数
        	 this->MyScoreInt += score ;
                 this->MyScoreLabel->Caption =   this->MyScoreInt  ;
                       //
                     
                  if(MyImage1State == true )
                 {
                        this->MyLast1->Picture->Bitmap = this->MyImage1->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast1->Picture->Bitmap  =  bitmapPosition ;
                 }
                 if(MyImage2State == true )
                 {
                        this->MyLast2->Picture->Bitmap = this->MyImage2->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast2->Picture->Bitmap  =  bitmapPosition ;
                 }
                 if(MyImage3State == true )
                 {
                        this->MyLast3->Picture->Bitmap = this->MyImage3->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast3->Picture->Bitmap  =  bitmapPosition ;
                 }
                 this->MyLast4->Picture->Bitmap = poolFish[4]->image ;
                 //鱼池发一牌
                 int pos = GetOneCard();
                 poolFish[4] = cards[pos];
                 this->PoolImage5->Picture->Bitmap = poolFish[4]->image ;
               //发牌
                   ReSendCard();

                   //通知电脑开始处理了
               }
               //钓鱼失败
               else
               {
               	      ReSendCard();	// 什么也不做，发牌 
               }
              this->CallOponent();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PoolImage6Click(TObject *Sender)
{
        	//pool6
        int sum = 0 ;
        int score = 0  ;
        if(poolFish[5] != NULL)
        {
        	if(MyImage1State == true)
                {
                      sum +=myFish[0]->cardNo ;
                      score += myFish[0]->cardLevel ;
                }

        	if(MyImage2State == true)
                {
                      sum +=myFish[1]->cardNo  ;
                      score += myFish[1]->cardLevel ;
                }

        	if(MyImage3State == true)
                {
                      sum +=myFish[2]->cardNo   ;
                      score += myFish[2]->cardLevel ;
                }
                sum += poolFish[5]->cardNo ;
                score += poolFish[5]->cardLevel ;

                //钓鱼成功
               if( sum == WINSCORE)
               {
               //计算分数
        	 this->MyScoreInt += score ;
                 this->MyScoreLabel->Caption =   this->MyScoreInt  ;
                       //
                     
                  if(MyImage1State == true )
                 {
                        this->MyLast1->Picture->Bitmap = this->MyImage1->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast1->Picture->Bitmap  =  bitmapPosition ;
                 }
                 if(MyImage2State == true )
                 {
                        this->MyLast2->Picture->Bitmap = this->MyImage2->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast2->Picture->Bitmap  =  bitmapPosition ;
                 }
                 if(MyImage3State == true )
                 {
                        this->MyLast3->Picture->Bitmap = this->MyImage3->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast3->Picture->Bitmap  =  bitmapPosition ;
                 }
                 this->MyLast4->Picture->Bitmap = poolFish[5]->image ;
                 //鱼池发一牌
                 int pos = GetOneCard();
                 poolFish[5] = cards[pos];
                 this->PoolImage6->Picture->Bitmap = poolFish[5]->image ;
               //发牌
                   ReSendCard();

                   //通知电脑开始处理了
               }
               //钓鱼失败
               else
               {
               	      ReSendCard();	// 什么也不做，发牌 
               }
              this->CallOponent();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PoolImage7Click(TObject *Sender)
{
        	//pool7
        int sum = 0 ;
        int score = 0  ;
        if(poolFish[6] != NULL)
        {
        	if(MyImage1State == true)
                {
                      sum +=myFish[0]->cardNo ;
                      score += myFish[0]->cardLevel ;
                }

        	if(MyImage2State == true)
                {
                      sum +=myFish[1]->cardNo  ;
                      score += myFish[1]->cardLevel ;
                }

        	if(MyImage3State == true)
                {
                      sum +=myFish[2]->cardNo   ;
                      score += myFish[2]->cardLevel ;
                }
                sum += poolFish[6]->cardNo ;
                score += poolFish[6]->cardLevel ;

                //钓鱼成功
               if( sum == WINSCORE)
               {
               //计算分数
        	 this->MyScoreInt += score ;
                 this->MyScoreLabel->Caption =   this->MyScoreInt  ;
                       //
                     
                  if(MyImage1State == true )
                 {
                        this->MyLast1->Picture->Bitmap = this->MyImage1->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast1->Picture->Bitmap  =  bitmapPosition ;
                 }
                 if(MyImage2State == true )
                 {
                        this->MyLast2->Picture->Bitmap = this->MyImage2->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast2->Picture->Bitmap  =  bitmapPosition ;
                 }
                 if(MyImage3State == true )
                 {
                        this->MyLast3->Picture->Bitmap = this->MyImage3->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast3->Picture->Bitmap  =  bitmapPosition ;
                 }
                 this->MyLast4->Picture->Bitmap = poolFish[6]->image ;
                 //鱼池发一牌
                 int pos = GetOneCard();
                 poolFish[6] = cards[pos];
                 this->PoolImage7->Picture->Bitmap = poolFish[6]->image ;
               //发牌
                   ReSendCard();

                   //通知电脑开始处理了
               }
               //钓鱼失败
               else
               {
               	      ReSendCard();	// 什么也不做，发牌 
               }
              this->CallOponent();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PoolImage8Click(TObject *Sender)
{
        	//pool4
        int sum = 0 ;
        int score = 0  ;
        if(poolFish[7] != NULL)
        {
        	if(MyImage1State == true)
                {
                      sum +=myFish[0]->cardNo ;
                      score += myFish[0]->cardLevel ;
                }

        	if(MyImage2State == true)
                {
                      sum +=myFish[1]->cardNo  ;
                      score += myFish[1]->cardLevel ;
                }

        	if(MyImage3State == true)
                {
                      sum +=myFish[2]->cardNo   ;
                      score += myFish[2]->cardLevel ;
                }
                sum += poolFish[7]->cardNo ;
                score += poolFish[7]->cardLevel ;

                //钓鱼成功
               if( sum == WINSCORE)
               {
               //计算分数
        	 this->MyScoreInt += score ;
                 this->MyScoreLabel->Caption =   this->MyScoreInt  ;
                       //
                     
                  if(MyImage1State == true )
                 {
                        this->MyLast1->Picture->Bitmap = this->MyImage1->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast1->Picture->Bitmap  =  bitmapPosition ;
                 }
                 if(MyImage2State == true )
                 {
                        this->MyLast2->Picture->Bitmap = this->MyImage2->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast2->Picture->Bitmap  =  bitmapPosition ;
                 }
                 if(MyImage3State == true )
                 {
                        this->MyLast3->Picture->Bitmap = this->MyImage3->Picture->Bitmap;
                 }
                 else
                 {
                        this->MyLast3->Picture->Bitmap  =  bitmapPosition ;
                 }
                 this->MyLast4->Picture->Bitmap = poolFish[7]->image ;
                 //鱼池发一牌
                 int pos = GetOneCard();
                 poolFish[7] = cards[pos];
                 this->PoolImage8->Picture->Bitmap = poolFish[7]->image ;
               //发牌
                   ReSendCard();

                   //通知电脑开始处理了
               }
               //钓鱼失败
               else
               {
               	      ReSendCard();	// 什么也不做，发牌 
               }
              this->CallOponent();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
        Form5 = new TForm5(this);
        if(Form5->ShowModal())
        {
                GameLevel = Form5->GameLevel ;
        }
        delete Form5 ;
}
//---------------------------------------------------------------------------

