//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ScktComp.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TServerSocket *ServerSocket1;
	TServerSocket *ServerSocket2;
	TEdit *Edit1;
	TLabel *Label1;
	TEdit *Edit2;
	TLabel *Label2;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall ServerSocket2ClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall ServerSocket2ClientError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
	void __fastcall ServerSocket1ClientError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
        TStringList * __fastcall Parse(AnsiString str ,AnsiString delimeter);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
