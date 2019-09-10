//---------------------------------------------------------------------------

#ifndef SetParamH
#define SetParamH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TTrackBar *TrackBarDeep;
	TTrackBar *TrackBarQuallity;
	TComboBox *ComboBoxServer;
	TButton *ButtonOk;
	TButton *ButtonCancel;
	TEdit *EditPort;
	TLabel *Label4;
	void __fastcall ButtonOkClick(TObject *Sender);
	void __fastcall ButtonCancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
        int result ;
        AnsiString serverIP ;
        int serverPort ;
        int level ;
        int cq ;
       
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
