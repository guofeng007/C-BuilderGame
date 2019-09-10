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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        TServerSocket *ServerSocket1;
        TPanel *Panel1;
        TEdit *Edit1;
        TLabel *Label1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TMemo *Memo2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall ServerSocket1Accept(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ServerSocket1ClientConnect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ServerSocket1ClientDisconnect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ServerSocket1ClientError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
        void __fastcall ServerSocket1ClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
         void __fastcall AppendText(AnsiString str);
         void __fastcall ParseString(String recvString,TCustomWinSocket *Socket);
         void __fastcall CaptureImage(int cq,TMemoryStream * imgstream);
         TStringList * __fastcall SplitString(AnsiString str ,AnsiString delimeter);
         void  __fastcall Start(TMessage &msg);
        BEGIN_MESSAGE_MAP
        VCL_MESSAGE_HANDLER(WM_HOTKEY,TMessage,Start)
        END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
