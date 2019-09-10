//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *LeftPanel;
	TPanel *RightPanel;
	TImage *Image1;
	TLabel *Label1;
	TLabel *Label2;
	TImage *Image2;
	TPanel *LeftButtom;
	TPanel *RightButtom;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TLabel *Label3;
	TEdit *EditLeftXY;
	TLabel *Label4;
	TEdit *EditLeftValue;
	TLabel *Label5;
	TEdit *EditLeftDifference;
	TLabel *Label6;
	TEdit *EditRightXY;
	TLabel *Label7;
	TEdit *EditRightValue;
	TEdit *EditRightDifference;
	TLabel *Label8;
	TButton *Button1;
	TButton *Button2;
	TMemo *MemoLeftData;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TButton *Button3;
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
         AnsiString __fastcall BinaryToString(byte *data ,int length);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 