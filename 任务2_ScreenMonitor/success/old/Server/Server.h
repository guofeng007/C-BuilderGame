//---------------------------------------------------------------------------

#ifndef ServerH
#define ServerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ScktComp.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "trayicon.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TServerSocket *ServerSocket1;
	TButton *Button1;
	TStatusBar *StatusBar1;
	TImage *Image1;
	TButton *Button2;
	TPopupMenu *PopupMenu1;
	TMenuItem *PopupStart;
	TMenuItem *PopupStop;
	TMenuItem *PopupExit;
	TTrayIcon *TrayIcon1;
	TMenuItem *PopupHideShow;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ServerSocket1ClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall ServerSocket1Accept(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall ServerSocket1ClientConnect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall ServerSocket1ClientDisconnect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall ServerSocket1ClientError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall PopupExitClick(TObject *Sender);
	void __fastcall PopupHideShowClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
       __fastcall void Status(AnsiString str) ;
        __fastcall void CaptureImage(int options ,int level ,int cq,TMemoryStream * imgstream);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
