//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MSCommLib_OCX.h"
#include <OleCtrls.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <ScktComp.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TStatusBar *StatusBar1;
        TPanel *Panel3;
        TMemo *Memo1;
        TPanel *Panel4;
        TLabel *Label3;
        TButton *Button3;
        TPanel *Panel5;
        TMemo *Memo2;
        TPanel *Panel6;
        TLabel *Label4;
        TButton *Button4;
        TButton *Button5;
        TPanel *Panel7;
        TLabel *Label2;
        TPanel *Panel8;
        TComboBox *ComboBox1;
        TPanel *Panel9;
        TButton *Button1;
        TPanel *Panel10;
        TLabel *Label1;
        TPanel *Panel11;
        TButton *Button2;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
	TPanel *Panel12;
	TButton *Button6;
	TButton *Button7;
	TClientSocket *ClientSocket1;
	TMSComm *MSComm1;
	TButton *Button8;
	TLabel *Label5;
        void __fastcall MSComm1Comm(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall ClientSocket1Connect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall ClientSocket1Connecting(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall ClientSocket1Disconnect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall ClientSocket1Read(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall ClientSocket1Error(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        TStringList * __fastcall Parse(AnsiString str ,AnsiString delimeter);
        void __fastcall ExplainToComm(AnsiString str);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
