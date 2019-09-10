//---------------------------------------------------------------------------

#ifndef MSPaintH
#define MSPaintH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <jpeg.hpp>
#include "CGRID.h"
#include "CSPIN.h"
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *MenuFile;
        TMenuItem *MenuEdit;
        TMenuItem *MenuView;
        TMenuItem *MenuImage;
        TMenuItem *MenuColor;
        TMenuItem *MenuHelp;
        TMenuItem *MenuItemFileNew;
        TMenuItem *MenuItemFileOpen;
        TMenuItem *MenuItemFileSave;
        TMenuItem *MenuItemFileSaveAs;
        TMenuItem *MenuItemFilePrint;
        TMenuItem *X1;
        TMenuItem *MenuItemEditCut;
        TMenuItem *MenuItemEditCopy;
        TMenuItem *MenuItemEditPaste;
        TMenuItem *MenuItemEditDelete;
        TMenuItem *MenuItemEditSelectAll;
        TMenuItem *MenuItemViewToolBox;
        TMenuItem *C2;
        TMenuItem *MenuItemViewStatusBar;
        TMenuItem *MenuItemImageScale;
        TMenuItem *MenuItemImageProperty;
        TMenuItem *MenuItemHelpTheme;
        TPanel *Panel3;
        TCoolBar *CoolBar1;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton9;
        TSpeedButton *SpeedButton10;
        TSpeedButton *SpeedButton11;
        TSpeedButton *SpeedButton12;
        TSpeedButton *SpeedButton13;
        TSpeedButton *SpeedButton14;
        TSpeedButton *SpeedButton15;
        TSpeedButton *SpeedButton16;
        TScrollBox *ScrollBox1;
        TImage *Image1;
        TPanel *Panel1;
        TShape *Shape1;
        TShape *Shape2;
        TPanel *Panel2;
        TImage *Image2;
        TCSpinEdit *CSpinEdit1;
        TStatusBar *StatusBar1;
        TOpenPictureDialog *OpenPictureDialog1;
        TSavePictureDialog *SavePictureDialog1;
        TColorDialog *ColorDialog1;
        TPrintDialog *PrintDialog1;
        TPrinterSetupDialog *PrinterSetupDialog1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
