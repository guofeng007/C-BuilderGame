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
enum TDrawingTool {dtNoEdit,dtSelectRect,dtErase,dtFill,dtGetColor,dtZoom,dtPencil,
                   dtBrush,dtFog,dtText,dtLine,dtRectangle,dtEllipse,dtRoundRect};
int FogSize  ; //fog size
double ZoomSize   ;// zoom size
bool  ZoomOut  ;//out or in
TRect SelectRect ; //rect
bool HaveSelected ; // is select region
TPoint CurrentPoint ;
AnsiString CurrentFile ;
AnsiString CurrentFileExt ;
const int crSelectPos = crCross ,crErase = 5 ,crFill = 6 ,crGetColor = 7 ,crZoom = 8,
        crPencil = 9 ,crBrush = 10 ,crFog = 11 ;
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
        TMenuItem *MenuItemFileCamera;
        TMenuItem *MenuItemFilePreview;
        TMenuItem *MenuItemFilePageSetting;
        TMenuItem *MenuItemFilePrint;
        TMenuItem *MenuItemFileSend;
        TMenuItem *MenuItemFileBGB;
        TMenuItem *MenuItemFileBGK;
        TMenuItem *MenuItemFileRecent;
        TMenuItem *X1;
        TMenuItem *MenuItemEditUndo;
        TMenuItem *MenuItemEditRedo;
        TMenuItem *MenuItemEditCut;
        TMenuItem *MenuItemEditCopy;
        TMenuItem *MenuItemEditPaste;
        TMenuItem *MenuItemEditDelete;
        TMenuItem *MenuItemEditSelectAll;
        TMenuItem *MenuItemEditCopyTo;
        TMenuItem *MenuItemEditPasteSource;
        TMenuItem *MenuItemViewToolBox;
	TMenuItem *MenuItemViewColorBox;
        TMenuItem *MenuItemViewStatusBar;
        TMenuItem *MenuItemViewToolbar;
        TMenuItem *MenuItemViewScale;
        TMenuItem *MenuItemViewSee;
        TMenuItem *MenuItemImageRotate;
        TMenuItem *MenuItemImageScale;
        TMenuItem *MenuItemImageInverse;
        TMenuItem *MenuItemImageProperty;
        TMenuItem *MenuItemImageClear;
        TMenuItem *MenuItemImageOpaque;
        TMenuItem *MenuItemColorEditColor;
        TMenuItem *MenuItemHelpTheme;
        TMenuItem *MenuItemHelpMsPaint;
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
        TShape *FGShape;
        TShape *BGShape;
        TCColorGrid *CColorGrid1;
        TPanel *Panel2;
        TImage *Image2;
        TCSpinEdit *CSpinEdit1;
        TOpenPictureDialog *OpenPictureDialog1;
        TSavePictureDialog *SavePictureDialog1;
        TColorDialog *ColorDialog1;
        TPrintDialog *PrintDialog1;
        TPrinterSetupDialog *PrinterSetupDialog1;
        TMenuItem *MenuItemFileExit;
        TMenuItem *EditSpace1;
        TMenuItem *EditSpace2;
        TMenuItem *ViewSpace1;
        TMenuItem *N4;
        TMenuItem *N5;
	TStatusBar *StatusBar1;
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall SpeedButton3Click(TObject *Sender);
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall SpeedButton5Click(TObject *Sender);
        void __fastcall SpeedButton6Click(TObject *Sender);
        void __fastcall SpeedButton7Click(TObject *Sender);
        void __fastcall SpeedButton8Click(TObject *Sender);
        void __fastcall SpeedButton9Click(TObject *Sender);
        void __fastcall SpeedButton10Click(TObject *Sender);
        void __fastcall SpeedButton11Click(TObject *Sender);
        void __fastcall SpeedButton12Click(TObject *Sender);
        void __fastcall SpeedButton13Click(TObject *Sender);
        void __fastcall SpeedButton14Click(TObject *Sender);
        void __fastcall SpeedButton15Click(TObject *Sender);
        void __fastcall SpeedButton16Click(TObject *Sender);
        void __fastcall CColorGrid1Change(TObject *Sender);
        void __fastcall CSpinEdit1KeyPress(TObject *Sender, char &Key);
        void __fastcall CSpinEdit1Change(TObject *Sender);
        void __fastcall Image1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall MenuItemEditCutClick(TObject *Sender);
        void __fastcall MenuItemEditCopyClick(TObject *Sender);
        void __fastcall MenuItemEditDeleteClick(TObject *Sender);
        void __fastcall MenuItemEditPasteClick(TObject *Sender);
        void __fastcall MenuItemEditSelectAllClick(TObject *Sender);
	void __fastcall MenuItemFileNewClick(TObject *Sender);
	void __fastcall MenuItemFileOpenClick(TObject *Sender);
	void __fastcall MenuItemFileSaveClick(TObject *Sender);
	void __fastcall MenuItemFileSaveAsClick(TObject *Sender);
	void __fastcall MenuItemFilePageSettingClick(TObject *Sender);
	void __fastcall SavePictureDialog1TypeChange(TObject *Sender);
	void __fastcall MenuItemFilePrintClick(TObject *Sender);
	void __fastcall X1Click(TObject *Sender);
	void __fastcall MenuItemImageScaleClick(TObject *Sender);
	void __fastcall MenuItemImageInverseClick(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall MenuItemImageClearClick(TObject *Sender);
	void __fastcall MenuItemViewToolBoxClick(TObject *Sender);
	void __fastcall MenuItemViewColorBoxClick(TObject *Sender);
	void __fastcall MenuItemViewStatusBarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        TDrawingTool ToolState ;
        TPoint       Start ;
        TPoint       End ;
        void __fastcall DrawShape(TPoint TopLeft ,TPoint BottomRight ,TPenMode PenMode);
        void __fastcall EraseSelect();
        void __fastcall LoadCursor();
        void __fastcall TForm1::FillBackground();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
