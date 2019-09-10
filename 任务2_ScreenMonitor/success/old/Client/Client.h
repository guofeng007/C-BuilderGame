//---------------------------------------------------------------------------

#ifndef ClientH
#define ClientH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ScktComp.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TClientSocket *ClientSocket1;
	TImage *Image1;
	TSavePictureDialog *SavePictureDialog1;
	TMainMenu *MainMenu1;
	TPopupMenu *PopupMenu1;
	TMenuItem *MenuConnect;
	TMenuItem *MenuItemConnectSet;
	TMenuItem *MenuItemConnectConnect;
	TMenuItem *MenuItemConnectClose;
	TMenuItem *MenuItemConnectExit;
	TMenuItem *MenuImage;
	TMenuItem *MenuItemImageFullScreen;
	TMenuItem *MenuItemImageAutoScale;
	TMenuItem *MenuItemImageSave;
	TMenuItem *MenuItemImageNext;
	TMenuItem *PopupMenuConnect;
	TMenuItem *PopupMenuImage;
	TMenuItem *PopupMenuItemConnectSet;
	TMenuItem *PopupMenuItemConnectConnect;
	TMenuItem *PopupMenuItemConnectClose;
	TMenuItem *PopupMenuItemConnectExit;
	TMenuItem *PopupMenuItemFullScreen;
	TMenuItem *PopupMenuItemAutoScale;
	TMenuItem *PopupMenuItemSave;
	TMenuItem *PopupMenuItemNext;
        TTimer *Timer1;
        TStatusBar *StatusBar1;
	void __fastcall MenuItemImageFullScreenClick(TObject *Sender);
	void __fastcall MenuItemConnectSetClick(TObject *Sender);
	void __fastcall MenuItemConnectConnectClick(TObject *Sender);
	void __fastcall MenuItemConnectCloseClick(TObject *Sender);
	void __fastcall MenuItemConnectExitClick(TObject *Sender);
	void __fastcall MenuItemImageNextClick(TObject *Sender);
	void __fastcall ClientSocket1Read(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall ClientSocket1Connect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ClientSocket1Error(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
        void __fastcall ClientSocket1Disconnect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ClientSocket1Connecting(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall MenuItemImageAutoScaleClick(TObject *Sender);
        void __fastcall MenuItemImageSaveClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
        AnsiString serverIP;
        int serverPort ;
        int option ;
        int level ;
        int cq ;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
