//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ScktComp.hpp>
#include <ExtCtrls.hpp>
#include <Chart.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include "pies.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TLabel *Label1;
	TComboBox *ComboBox1;
	TButton *Button1;
	TPie *Pie1;
	TEdit *Edit1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit2;
	TLabel *Label4;
	TEdit *Edit3;
	TButton *Button2;
	TLabel *Label5;
	TButton *Button3;
	TClientSocket *ClientSocket1;
	void __fastcall Pie1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ClientSocket1Disconnect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall ClientSocket1Error(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
