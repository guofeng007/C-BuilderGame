//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TPanel *LeftPanel;
	TImage *Image1;
	TLabel *Label1;
	TPanel *LeftButtom;
	TPanel *Panel1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *EditLeftXY;
	TEdit *EditLeftValue;
	TEdit *EditLeftDifference;
	TPanel *Panel2;
	TButton *Button1;
	TPanel *RightPanel;
	TLabel *Label2;
	TImage *Image2;
	TPanel *RightButtom;
	TPanel *Panel3;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TEdit *EditRightXY;
	TEdit *EditRightValue;
	TEdit *EditRightDifference;
	TPanel *Panel4;
	TButton *Button2;
	TButton *Button3;
	TOpenPictureDialog *OpenPictureDialog1;
	TOpenDialog *OpenDialog1;
	TImage *Image3;
	TLabel *Label9;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
        AnsiString __fastcall ParseString(AnsiString str);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
 