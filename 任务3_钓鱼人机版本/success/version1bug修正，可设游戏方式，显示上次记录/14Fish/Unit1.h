//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *MenuStart;
	TMenuItem *MenuHelp;
	TMenuItem *MenuExit;
	TMenuItem *MenuRestart;
	TPanel *TopPanel;
	TPanel *MiddlePanel;
	TPanel *ButtomPanel;
	TPanel *TopLeft;
	TPanel *TopMiddle;
	TPanel *TopRight;
	TPanel *MiddleRight;
	TPanel *MiddleLeft;
	TPanel *ButtomLeft;
	TPanel *ButtomMiddle;
	TImage *OpponentImage1;
	TImage *OpponentImage2;
	TImage *OpponentImage3;
	TImage *MyImage1;
	TImage *MyImage2;
	TImage *MyImage3;
	TImage *OpponentLast3;
	TImage *OpponentLast2;
	TImage *OpponentLast1;
	TImage *OpponentLast4;
	TPanel *Panel1;
	TImage *MyLast3;
	TImage *MyLast2;
	TImage *MyLast1;
	TImage *MyLast4;
	TImage *PoolImage1;
	TImage *PoolImage2;
	TImage *PoolImage3;
	TImage *PoolImage4;
	TImage *PoolImage5;
	TImage *PoolImage6;
	TImage *PoolImage7;
	TImage *PoolImage8;
	TLabel *Label1;
	TLabel *OpponentScoreLabel;
	TLabel *Label2;
	TLabel *MyScoreLabel;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *LabelCardsCount;
        TMenuItem *N1;
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall MenuStartClick(TObject *Sender);
	void __fastcall MenuExitClick(TObject *Sender);
	void __fastcall MenuHelpClick(TObject *Sender);
	void __fastcall MenuRestartClick(TObject *Sender);
	void __fastcall MyImage1Click(TObject *Sender);
	void __fastcall MyImage2Click(TObject *Sender);
	void __fastcall MyImage3Click(TObject *Sender);
	void __fastcall PoolImage1Click(TObject *Sender);
	void __fastcall PoolImage2Click(TObject *Sender);
	void __fastcall PoolImage3Click(TObject *Sender);
	void __fastcall PoolImage4Click(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
   void __fastcall MakePosition(TImage * image );
   void __fastcall MakeBack(TImage *image);
   //init card
   void __fastcall InitCards();
   void __fastcall TForm1::InitFish();
   void __fastcall DestroyCards();
   int  __fastcall GetOneCard();
   void __fastcall ReSendCard();
   void __fastcall CallOponent();
   void __fastcall PCResend(int i, int j);
   void __fastcall Init();
   int OpponnetScoreInt ;
   int MyScoreInt ;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
