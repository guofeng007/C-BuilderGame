//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
bool bpicture = false ;
bool bmap = false ;
TObjectList *map ;
#define BMP this->Image2->Canvas->Pixels

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	map = new TObjectList(true);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree ;	
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
	if(this->OpenPictureDialog1->Execute())
        {
            AnsiString FileName = this->OpenPictureDialog1->FileName ;
            this->Image1->Picture->LoadFromFile(FileName);
            this->Image2->Picture->LoadFromFile(FileName);
            bpicture = true ;	
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button3Click(TObject *Sender)
{
	if(OpenDialog1->Execute())
        {
        	AnsiString FileName = this->OpenDialog1->FileName ;
                int handle = FileOpen(FileName,fmOpenRead);
                try
                {
       		int length =  GetCompressedFileSize(FileName.c_str(),NULL);
                int unit = sizeof(TPoint);

                for(int i = 0 ; i < length /unit ; i++)
                {
                	TPoint *p = new TPoint ;
                	FileRead(handle,p,unit);
                        map->Add((TObject *)p);
                }
                FileClose(handle);
                bmap = true ; 
                
                }
                catch(...)
                {

                	ShowMessage("��λͼȱʧ");
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	if(bpicture == false)
        {
        	ShowMessage("��ѡ��ͼ������");
                return ;
        }
        if(bmap == false )
        {
        	ShowMessage("û��ѡ��λͼ���߶�λͼ����ȷ");
                return ;
        }

        //��ʼ��ȡͼ���Ҹ��ұ�
        int width = this->Image1->Width ;
        int height = this->Image1->Height ;

        //����ͼƬ��ʽ��������ȡ����
         this->Image2->Picture->Bitmap->PixelFormat = pf8bit ;
        //��ʼ��ȡ
        AnsiString  result = "" ;
        for(int i = 0 ;  i < map->Count ; i++)
        {
        	TPoint *p = (TPoint *)map->Items[i];
                int x = p->x ;
                int y = p->y ;
//1.���㵱ǰ��ֵ
		int a = GetBValue(BMP[x][2*y]) ;
                int b =GetBValue( BMP[x][2*y+1]);
                int h = a - b ;
                int average = ( a + b )/2 ;
//2.��ȡ����                
                if( h&0x1 ==1 )
                {
                	result +="1";
                }
                else
                {
			result +="0";
                }
//3.��ֵ��ԭ
		h = h/2 ;

                int p1 =  average + (h+1) / 2 ;
                int p2 =  average - h /2  ;
                TColor c1 = TColor(p1,p1,p1);
                TColor c2 = TColor(p2,p2,p2);
                BMP[x][2*y] =  c1 ;
                BMP[x][2*y+1] =   c2 ;

        }
//4.������ʾ
	ShowMessage(result);
        ShowMessage(ParseString(result));

}
AnsiString __fastcall TForm3::ParseString(AnsiString str)
{
	int length = str.Length();
        int msize = (length/8+1)*sizeof(char) ;
        char *buf  = (char *)malloc(msize) ;
        buf[length/8+1] = '\0' ;
	for(int i = 0  ; i < length /8 ; i++)
        {

        	buf[i] = 0 ;
        	for(int j = 1 ;  j <= 8 ; j++)
                {
                // ��λ ��ʼ
                 char t = str.operator [](i*8+j) ;
               		if(t == '1' )
                	{
                        	int b = 1 <<(j-1) ;
                		buf[i] = buf[i]  + b ;
                	}
                }
        }
        // xxx

        return AnsiString(buf);

}
//---------------------------------------------------------------------------
void __fastcall TForm3::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
		byte r , rnext ;
	TColor colorLeft ,colorRight   ;
        /*   ɨ������
        for(int i = 0 ;  i < width ; i++)
        {
        	for(int j = 0 ;  j < height ; j++)
                {
                	color = this->Image1->Canvas->Pixels[i][j];
                        r  = GetRValue(color);
                        g  = GetGValue(color);
                        b  = GetBValue(color);
                        this->EditLeftValue->Text = AnsiString(r)+":"+AnsiString(g)+":"+AnsiString(b);
                }

        } */
        if( X  < Width )
        {//��ֹԽ��

        
        //��ߵ�ͼ��
      	colorLeft = this->Image1->Canvas->Pixels[X][Y];
        r  = GetRValue(colorLeft);
        colorLeft = this->Image1->Canvas->Pixels[X+1][Y];
        rnext = GetRValue(colorLeft);
        //XY
        this->EditLeftXY->Text    = AnsiString(X)+":"+AnsiString(Y);
        //Value
        this->EditLeftValue->Text = AnsiString(r);
        //Difference
        this->EditLeftDifference->Text = AnsiString(r)+"-"+AnsiString(rnext)+"="+AnsiString(r-rnext);


        //�ұߵ�ͼ��
        colorRight = this->Image3->Canvas->Pixels[X][Y];
        r  = GetRValue(colorRight);
        colorRight = this->Image3->Canvas->Pixels[X+1][Y];
        rnext = GetRValue(colorRight);
        //XY
        this->EditRightXY->Text    = AnsiString(X)+":"+AnsiString(Y);
        //Value
        this->EditRightValue->Text = AnsiString(r);
        //Difference
        this->EditRightDifference->Text = AnsiString(r)+"-"+AnsiString(rnext)+"="+AnsiString(r-rnext);
        }
	
}
//---------------------------------------------------------------------------

