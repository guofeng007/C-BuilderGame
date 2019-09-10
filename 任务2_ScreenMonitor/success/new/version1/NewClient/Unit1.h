//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ScktComp.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *LeftPanel;
	TLabel *Label1;
	TEdit *Edit1;
	TLabel *Label2;
	TEdit *Edit2;
	TLabel *Label3;
	TTrackBar *TrackBar1;
	TButton *Button1;
	TButton *Button2;
	TClientSocket *ClientSocket1;
	TButton *Button3;
	TPanel *CenterPanel;
	TMemo *Memo1;
	TButton *Button4;
	TScrollBox *ScrollBox1;
	TImage *Image1;
	TMainMenu *MainMenu1;
	TMenuItem *MenuItemControl;
	TMenuItem *MenuItemControlFullScreen;
	TMenuItem *MenuItemControlExit;
	TMenuItem *MenuItemControlFullScreenExit;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall ClientSocket1Connect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall ClientSocket1Disconnect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall ClientSocket1Error(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall ClientSocket1Read(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall MenuItemControlExitClick(TObject *Sender);
	void __fastcall MenuItemControlFullScreenClick(TObject *Sender);
	void __fastcall MenuItemControlFullScreenExitClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
         void __fastcall AppendText(AnsiString str);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
