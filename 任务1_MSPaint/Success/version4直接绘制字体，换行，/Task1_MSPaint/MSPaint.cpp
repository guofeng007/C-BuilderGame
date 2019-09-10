//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MSPaint.h"
#include "Unit2.h"
#include "Clipbrd.hpp"
#include "NewDialog.h"
#include<ctype.h>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CGRID"
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
bool typeText = false ;
int typeX = 0 ;
int typeY = 0 ;
TFont *typeFont ;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        DragAcceptFiles( this->Handle, true);
	CurrentFileExt = ".jpg";
        LoadCursor();
        FillBackground();
        FogSize = 15 ;
        ZoomSize = 3.0 ;
        ZoomOut = false ;
        HaveSelected = false ;
        typeFont = FontDialog1->Font;
        this->Image1->Picture->Bitmap->Modified = false ;//incase it save
        this->ScrollBox1->DoubleBuffered = true ; //mem double buffer
}
void __fastcall TForm1 ::AcceptFiles(TMessage& Msg)
{
    const int m_nMaxFileNameLen=255;
     int i, m_nCount;
    char m_sFileName[m_nMaxFileNameLen];
    //ZeroMemory(m_sFileName,m_nMaxFileNameLen+1);
    m_nCount=DragQueryFile((HANDLE)Msg.WParam, 0xffffffff, m_sFileName , m_nMaxFileNameLen);

    if(m_nCount>1)
    {
        ShowMessage("一次只能拖拽一个文件");
    }

     DragQueryFile((HANDLE )Msg.WParam, 0, m_sFileName , m_nMaxFileNameLen);
     AnsiString fileName = AnsiString(m_sFileName);
    AnsiString fileExt =      ExtractFileExt(fileName);
    if(fileExt != NULL)
    {
        if(!fileExt.IsEmpty())
        {
                if(fileExt==".jpg"||fileExt==".bmp")
                {
                CurrentFile = fileName ;
                this->Image1->Picture->LoadFromFile(CurrentFile) ;
                }
                else
                {
                        ShowMessage("图片格式不对，只能打开*.jpg ,*.bmp");
                }
        }
        else
        {
                ShowMessage("只能打开图片文件(jpg,bmp)，不能打开其他文件");
        }

    }
    else
    {
                ShowMessage("只能打开图片文件(jpg,bmp)，不能打开其他文件");
    }


    //ZeroMemory(m_sFileName,m_nMaxFileNameLen+1);
     /*
    for (i=0;i<m_nCount;i ++)

    {

        DragQueryFile((HANDLE )Msg.WParam, i, m_sFileName , m_nMaxFileNameLen);

        MessageBox( this->Handle,m_sFileName,"Drop File" ,MB_OK);

        //ZeroMemory(m_sFileName,m_nMaxFileNameLen+1);

    }
       */
    DragFinish ((HANDLE)Msg.WParam);

}

 void __fastcall TForm1::FillBackground()
 {
        this->Image1->Canvas->Brush->Color = this->BGShape->Brush->Color;
        this->Image1->Canvas->FloodFill(0,0,this->Image1->Canvas->Pixels[0][0],fsSurface);
        this->Image1->Picture->Bitmap->Modified  = false ;

 }
 void __fastcall TForm1::LoadCursor()
 {
 Screen->Cursors[crErase]  = LoadCursorFromFile("cursors/erase.cur");
 Screen->Cursors[crFill]  = LoadCursorFromFile("cursors/fill.cur");
 Screen->Cursors[crGetColor]  = LoadCursorFromFile("cursors/getcolor.cur");
 Screen->Cursors[crZoom]  = LoadCursorFromFile("cursors/magnify.cur");
 Screen->Cursors[crPencil]  = LoadCursorFromFile("cursors/pencil.cur");
 Screen->Cursors[crBrush]  = LoadCursorFromFile("cursors/brush.cur");
 Screen->Cursors[crFog]  = LoadCursorFromFile("cursors/fog.cur");
  
 }
 void __fastcall TForm1::DrawShape(TPoint Start ,TPoint End ,TPenMode PenMode)
 {
       //set mode
       this->Image1->Canvas->Pen->Mode = PenMode ;
       // fill
       this->Image1->Canvas->Brush->Style = bsClear ;

       switch(ToolState)
       {
       case dtLine :
                     this->Image1->Canvas->MoveTo(Start.x,Start.y);
                     this->Image1->Canvas->LineTo(End.x,End.y);
                     break ;
       case dtSelectRect : 
       case dtRectangle :
                     this->Image1->Canvas->Rectangle(Start.x,Start.y,End.x,End.y);
                     break ;
       case dtEllipse :
                     this->Image1->Canvas->Ellipse(Start.x,Start.y,End.x,End.y);
                     break ;
       case dtRoundRect :
                      this->Image1->Canvas->RoundRect(Start.x,Start.y,End.x,End.y,
                                                     (Start.x-End.x)/2,(Start.y-End.y)/2);
                     break ;
       default :  break ;
      }
      this->Image1->Canvas->Pen->Mode = pmCopy ;



 }
 void __fastcall TForm1::EraseSelect()
 {
            if(HaveSelected)
            {
                // xor to elimale the select  
                this->Image1->Canvas->Pen->Style = psDot ;
                this->Image1->Canvas->Pen->Width = 1 ;
                DrawShape(Start,End,pmNotXor);
                // restore pen

                this->Image1->Canvas->Pen->Style = psSolid ;
                this->Image1->Canvas->Pen->Width = this->CSpinEdit1->Value;
                HaveSelected = false ;
            }
 }
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
        // exit edit
        ToolState = dtNoEdit ;
         typeText = false ;
        this->Image1->Cursor = TCursor(crDefault);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{        // select rect
        ToolState = dtSelectRect ;
        typeText = false ;
        this->Image1->Cursor = TCursor(crSelectPos);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{      // erase
        EraseSelect();
        ToolState = dtErase;
        typeText = false ;
        this->Image1->Cursor = TCursor(crErase);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{       // fill
        EraseSelect();
        ToolState = dtFill;
        typeText = false ;
        this->Image1->Cursor = TCursor(crFill);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton5Click(TObject *Sender)
{      //get color
        EraseSelect();
        ToolState = dtGetColor;
        typeText = false ;
        this->Image1->Cursor = TCursor(crGetColor);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton6Click(TObject *Sender)
{        //zoom
        EraseSelect();
        ToolState = dtZoom;
        typeText = false ;
        this->Image1->Cursor = TCursor(crZoom);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton7Click(TObject *Sender)
{
        //pencil
        EraseSelect();
        ToolState = dtPencil;
        typeText = false ;
        this->Image1->Cursor = TCursor(crPencil);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton8Click(TObject *Sender)
{          //brush
         EraseSelect();
        ToolState = dtBrush;
        typeText = false ;
        this->Image1->Cursor = TCursor(crBrush);
        //set default width
        this->CSpinEdit1->Value = 13 ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton9Click(TObject *Sender)
{        //fog
         EraseSelect();
        ToolState = dtFog;
        typeText = false ;
        this->Image1->Cursor = TCursor(crFog);        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton10Click(TObject *Sender)
{        //text out
         EraseSelect();
        ToolState = dtText;
        typeText = true ;
        this->Image1->Cursor = TCursor(crSelectPos);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton11Click(TObject *Sender)
{
        //line
         EraseSelect();
        ToolState = dtLine;
        typeText = false ;
        this->Image1->Cursor = TCursor(crSelectPos);        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton12Click(TObject *Sender)
{
        // no
        typeText = false ;   
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton13Click(TObject *Sender)
{       //rectangle
         EraseSelect();
        ToolState = dtRectangle;
        typeText = false ;
        this->Image1->Cursor = TCursor(crSelectPos);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton14Click(TObject *Sender)
{
        //no
        typeText = false ;      
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton15Click(TObject *Sender)
{
        //ellipse
         EraseSelect();
        ToolState = dtEllipse;
        typeText = false ;
        this->Image1->Cursor = TCursor(crSelectPos);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton16Click(TObject *Sender)
{
        //round rect
        EraseSelect();
        ToolState = dtRoundRect;
        typeText = false ;
        this->Image1->Cursor = TCursor(crSelectPos);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CColorGrid1Change(TObject *Sender)
{
        this->FGShape->Brush->Color = this->CColorGrid1->ForegroundColor;
        this->BGShape->Brush->Color = this->CColorGrid1->BackgroundColor;
        // shape borger inverse
         this->FGShape->Pen->Color = TColor(
         RGB(
         0xff-BYTE(this->FGShape->Brush->Color),
         0xff-BYTE(this->FGShape->Brush->Color>>8),
         0xff-BYTE(this->FGShape->Brush->Color>>16)
         )
         );

         this->BGShape->Pen->Color = TColor(
         RGB(
         0xff-BYTE(this->BGShape->Brush->Color),
         0xff-BYTE(this->BGShape->Brush->Color>>8),
         0xff-BYTE(this->BGShape->Brush->Color>>16)
         )
         );

}
//---------------------------------------------------------------------------

void __fastcall TForm1::CSpinEdit1KeyPress(TObject *Sender, char &Key)
{
        if(Key !=8 )  //backspace
        {
                if((Key<'0')||(Key>'9')||(Key=='0')&&(this->CSpinEdit1->Text==""))
                {
                        Key = 0 ;
                        MessageBeep(MB_OK);
                }
               
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CSpinEdit1Change(TObject *Sender)
{
        // avoid enter error
        if(this->CSpinEdit1->Text == "" || this->CSpinEdit1->Text.ToInt() <=0)
        {
                this->CSpinEdit1->Text = IntToStr(1);
        }
        else
        if(this->CSpinEdit1->Text.ToInt() > 100)
        {
                this->CSpinEdit1->Text = IntToStr(100);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//fill
        if(ToolState == dtFill)
        {
                if(Button == mbLeft)
                {        //left click foreground fill
                        this->Image1->Canvas->Brush->Color = this->FGShape->Brush->Color;
                }
                else
                {      //right click background fill
                       this->Image1->Canvas->Brush->Color = this->BGShape->Brush->Color;
                }
              this->Image1->Canvas->FloodFill(X,Y,this->Image1->Canvas->Pixels[X][Y],fsSurface);
          return ;
        }
// zoom
         if(ToolState == dtZoom)
        {
                if(Button == mbLeft&&ZoomOut == false)
                {        //left click zoom in  big
                        //redraw bitmap and then draw back
                        Graphics::TBitmap *TmpBitmap ;
                        TmpBitmap = new Graphics::TBitmap();
                        TmpBitmap->Width = this->Image1->Picture->Width*ZoomSize ;
                        TmpBitmap->Height =this->Image1->Picture->Height*ZoomSize ;
                        TmpBitmap->Canvas->StretchDraw(TRect(0,0,TmpBitmap->Width,TmpBitmap->Height),this->Image1->Picture->Graphic);

                        this->Image1->Picture->Graphic = TmpBitmap ;
                        delete TmpBitmap;
                        ZoomOut = true ;
                }
                else
                if(Button == mbRight&&ZoomOut == true)
                {      //right click zoom in
                        //redraw bitmap and then draw back
                        Graphics::TBitmap *TmpBitmap ;
                        TmpBitmap = new Graphics::TBitmap();
                        TmpBitmap->Width = this->Image1->Picture->Width/ZoomSize ;
                        TmpBitmap->Height =    this->Image1->Picture->Height/ZoomSize ;
                        TmpBitmap->Canvas->StretchDraw(TRect(0,0,TmpBitmap->Width,TmpBitmap->Height),this->Image1->Picture->Graphic);

                        this->Image1->Picture->Graphic = TmpBitmap ;
                        delete TmpBitmap;
                        ZoomOut = false ;
                }
              // toolstate noedit
              this->SpeedButton1->Click();
              this->SpeedButton1->Down = true ;
          return ;
        }
//getcolor
         if(ToolState == dtGetColor)
        {
            if(Button == mbLeft)
                {        //left click foreground
                        this->FGShape->Brush->Color=this->Image1->Canvas->Pixels[X][Y];
                }
                else
                {      //right click background fill
                         this->BGShape->Brush->Color = this->Image1->Canvas->Pixels[X][Y];
                }
          // toolstate noedit
              this->SpeedButton1->Click();
              this->SpeedButton1->Down = true ;
          return ;
        }


        if(Button != mbLeft)
        {
                return ; //return if no state
        }
        //draw something
        switch(ToolState)
        {
                case dtNoEdit: break ;
                case dtSelectRect:
                        EraseSelect();
                        this->Image1->Canvas->Brush->Style = bsClear ;
                        this->Image1->Canvas->Pen->Style = psDot ;
                        this->Image1->Canvas->Pen->Color = this->FGShape->Brush->Color;
                        this->Image1->Canvas->Pen->Width = 1 ;
                        Start = Point(X,Y);
                        End = Start;
                        break ;
                case dtErase:
                       //background color redraw current
                       this->Image1->Canvas->Pen->Color = this->BGShape->Brush->Color;
                       this->Image1->Canvas->Pen->Width = 13; //erase width
                       this->Image1->Canvas->MoveTo(X,Y);
                       break ;
                case dtPencil:
                        //foreground to draw
                        this->Image1->Canvas->Pen->Width = 1 ;
                        this->Image1->Canvas->Pen->Color = this->FGShape->Brush->Color;
                        this->Image1->Canvas->MoveTo(X,Y);
                        break ;
                case dtBrush:
                        //get color brush
                         this->Image1->Canvas->Pen->Color = this->FGShape->Brush->Color ;
                         this->Image1->Canvas->Pen->Width = this->CSpinEdit1->Value;
                         this->Image1->Canvas->MoveTo(X,Y);
                         break ;
                case dtFog:
                         randomize();
                         for(int i=0 ;i < FogSize*FogSize/5;)
                         {
                                //x,y circle
                                int delX = random(FogSize*2);
                                int delY = random(FogSize*2);
                                  i++ ;
                                int r =   (delX-FogSize)*(delX-FogSize)+(delY-FogSize)*(delY-FogSize);
                                int r2 =    FogSize*FogSize ;

                                         int xis= X+delX-FogSize;
                                         int yis= Y+delY-FogSize;
                                        this->Image1->Canvas->Pixels[xis][yis]=this->FGShape->Brush->Color;

                               
                                //something wrong with code 
                              
                         }
                         break ;
                case dtText:
                         typeX = X ;
                         typeY = Y ;

                /*
                         Form2->FontDialog1->Font = this->Image1->Canvas->Font;
                         Form2->ShowModal();
                        // 0 no operation   1 ok  2 cancel
                         if(Form2->result == 1)
                         {
                          this->Image1->Canvas->Font = Form2->FontDialog1->Font;
                          this->Image1->Canvas->TextOutA(X,Y,Form2->EditFont->Text);

                         }

                  */

                         break ;
                case dtLine:
                case dtRectangle:
                case dtEllipse:     
                case dtRoundRect:
                        this->Image1->Canvas->MoveTo(X,Y);
                        Start  =Point(X,Y);
                        End = Start ;
                        break ;
                default: break ;
                        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        TVarRec tempvar[2] = {X,Y};
        this->StatusBar1->Panels->Items[1]->Text = Format("X,Y:(%d,%d)",tempvar,2);

        //if left no down return
        if( !Shift.Contains(ssLeft))
        {
          return ;
        }
        switch(ToolState)
        {
                case dtNoEdit:break ;
                case dtSelectRect :
                         //erase old
                        DrawShape(Start,End,pmNotXor);
                        //record end
                        End = Point(X,Y);
                        //draw new
                        DrawShape(Start,End,pmNotXor);
                        break ;
                case dtErase:
                        this->Image1->Canvas->LineTo(X,Y);
                        break ;
                case dtPencil:
                        this->Image1->Canvas->LineTo(X,Y);
                        break ;
                case dtBrush:
                        this->Image1->Canvas->LineTo(X,Y);
                        break ;
                case dtFog:
                        break ;
                case dtLine:
                case dtRectangle:
                case dtEllipse:
                case dtRoundRect:
                        this->Image1->Canvas->Pen->Color = this->FGShape->Brush->Color;
                        this->Image1->Canvas->Pen->Width = this->CSpinEdit1->Value ;
                        //erase old
                        DrawShape(Start,End,pmNotXor);
                        End = Point(X,Y);
                        //draw new
                        DrawShape(Start,End ,pmNotXor);
                        break ;
                default:break ;


        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
	//current to pase
        CurrentPoint = Point(X,Y);
        if(Button != mbLeft)
        {
        //no left return
          return ;
        }
        switch(ToolState)
        {
                case dtNoEdit: break ;
                case dtSelectRect:
                        DrawShape(Start,Point(X,Y),pmCopy);
                        //restore pen
                        this->Image1->Canvas->Pen->Width = this->CSpinEdit1->Value;
                        this->Image1->Canvas->Pen->Style = psSolid;
                        End = Point(X,Y);
                        SelectRect = TRect(Start,End);
                        HaveSelected = true ;
                        break ;
                case dtErase:
                        this->Image1->Canvas->Pen->Width =   this->CSpinEdit1->Value;
                        break ;
                case dtLine:
                case dtRectangle:
                case dtEllipse:
                case dtRoundRect:
                       this->Image1->Canvas->Pen->Color = this->FGShape->Brush->Color;
                       this->Image1->Canvas->Pen->Width =     this->CSpinEdit1->Value;
                       DrawShape(Start,Point(X,Y),pmCopy);
                       break ;
                default:break ;
                        

        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemEditCutClick(TObject *Sender)
{
        if(!HaveSelected)
        {
           //return if no selected
                return  ;
        }
        this->MenuItemEditCopy->Click();

        this->MenuItemEditDelete->Click();

        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemEditCopyClick(TObject *Sender)
{
         if(!HaveSelected)
        {
           //return if no selected
                return  ;
        }
       Graphics::TBitmap *TmpBitmap =new Graphics::TBitmap();
       TmpBitmap->Width = SelectRect.Width();
       TmpBitmap->Height = SelectRect.Height();
       //copy to tmpbitmap
       TmpBitmap->Canvas->CopyRect(TRect(0,0,TmpBitmap->Width,TmpBitmap->Height),this->Image1->Canvas,SelectRect);
       // copy to clipboard
       Clipboard()->Assign(TmpBitmap);
       delete TmpBitmap;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemEditDeleteClick(TObject *Sender)
{
      if(!HaveSelected)
        {
           //return if no selected
                return  ;
        }
        //erase rect
        EraseSelect();

        //earse to background rect
        this->Image1->Canvas->Brush->Style = bsSolid;
        this->Image1->Canvas->Brush->Color = this->BGShape->Brush->Color;
        this->Image1->Canvas->Pen->Style = psClear ;
        //cause rect didn't draw right button so add 1
        this->Image1->Canvas->Rectangle(SelectRect.left,SelectRect.top,SelectRect.right+1,SelectRect.Bottom+1);

        //restore pen and brush
        this->Image1->Canvas->Brush->Style = bsClear;
        this->Image1->Canvas->Brush->Color = this->FGShape->Brush->Color;
        this->Image1->Canvas->Pen->Style = psSolid ;
        
        

}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemEditPasteClick(TObject *Sender)
{
       Graphics::TBitmap *Bitmap ;

       if(Clipboard()->HasFormat(CF_BITMAP))
       {
             Bitmap = new   Graphics::TBitmap();
             try
             {
                  Bitmap->Assign(Clipboard()) ;
                  this->Image1->Canvas->Draw(CurrentPoint.x,CurrentPoint.y,Bitmap);//location ??
             }
             catch(...)
             {
                  delete Bitmap ;
             }
             delete Bitmap ;

       }
       
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemEditSelectAllClick(TObject *Sender)
{
     //erase
     EraseSelect();
     //set point and draw
     Start = Point(0,0);
     End = Point(this->Image1->Width,this->Image1->Height);
     ToolState = dtSelectRect; //to draw
     DrawShape(Start,End,pmNotXor);

   //restore
   this->Image1->Canvas->Pen->Width = this->CSpinEdit1->Value;
   this->Image1->Canvas->Pen->Style = psSolid;
   SelectRect = TRect(Start,End);
   HaveSelected = true ;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::MenuItemFileNewClick(TObject *Sender)
{
	Graphics::TBitmap  *Bitmap = new   Graphics::TBitmap();
	Form3->ShowModal();
        if(Form3->result == 1)
        {
             Bitmap->Width = Form3->width ;
             Bitmap->Height = Form3->height;
             this->Image1->Picture->Graphic = Bitmap ;
             // in case save exit occurs
             this->Image1->Picture->Bitmap->Modified = false ;
             CurrentFile = "";
             Form3->result = 0 ;//reset
        }	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemFileOpenClick(TObject *Sender)
{
	if(this->OpenPictureDialog1->Execute())
        {
        	CurrentFile = this->OpenPictureDialog1->FileName ;
                this->Image1->Picture->LoadFromFile(CurrentFile) ;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemFileSaveClick(TObject *Sender)
{
    if(CurrentFile != "")
     {    //convert

        if(select == 1)
          {
           	this->Image1->Picture->SaveToFile(CurrentFile);
	  }
          else
          {
          		TJPEGImage *j = new TJPEGImage();
                        j->Assign(this->Image1->Picture->Bitmap);
                        j->CompressionQuality = 60 ;// compress rate do't too high
                        j->SaveToFile(CurrentFile);
                        delete j ;
          }
         this->Image1->Picture->Bitmap->Modified  = false ;
     } 
     else
          {
               //this->MenuItemFileSaveAs->Click();
               MenuItemFileSaveAsClick(Sender);
	  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemFileSaveAsClick(TObject *Sender)
{
       if(this->SavePictureDialog1->Execute())
        {
              	CurrentFile = this->SavePictureDialog1->FileName;
                this->MenuItemFileSave->Click();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemFilePageSettingClick(TObject *Sender)
{
	this->PrinterSetupDialog1->Execute();	
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SavePictureDialog1TypeChange(TObject *Sender)
{
	select = this->SavePictureDialog1->FilterIndex ;
        if(select == 1)
        {
        	CurrentFileExt = ".jgp";
        }
        if(select == 2)
        {
        	CurrentFileExt = ".bmp";
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemFilePrintClick(TObject *Sender)
{
/*
	unsigned int BitmapInfoSize,BitmapImageSize ;
        long DIBWidth,DIBHeight ;
        PChar BitmapImage ;
        Widnows::PBitmapInfo BitmapInfo ;
        Graphics::TBitmap *Bitmap ;

        Printer()->BeginDoc();

        Bitmap = new Graphics::TBitmap();
        Bitmap->Assign(this->Image1->Picture);
        GetDIBSizes(Bitmap->Handle,BitmapInfoSize,BitmapImageSize);
        BitmapInfo = (PBitmapInfo) new char[BitmapInfoSize];
        BitmapImage = (PChar) new char[BitmapImageSize];
        GetDIB(Bitmap->Handle,0,BitmapInfo,BitmapImage);
        DIBWidth = BitmapInfo->bmiHeader.biWidth ;
        DIBHeight = BitmapInfo->bmiHeader.biHeight ;
        //scretch
        StretchDIBits(Printer()->Canvas->Handle,0,0,DIBWidth,DIBHeight,0,0,DIBWidth,DIBHeight,BitmapImage,BitmapInfo,DIB_RGB_COLORS,SRCCOPY);
        delete [] BitmapImage ;
        delete [] BitmapInfo ;
        delete Bitmap ;
        Printer()->EndDoc();  */
       this->PrintDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::X1Click(TObject *Sender)
{
	this->Close();	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemImageScaleClick(TObject *Sender)
{
	Graphics::TBitmap *Bitmap ;
        //init
        Form3->Caption="缩放图片";
        Form3->Label1->Caption = "水平%" ;
        Form3->Label2->Caption = "垂直%" ;
        Form3->Edit1->Text = "100";
        Form3->Edit2->Text = "100" ;

        Form3->ShowModal();

        if(Form3->result == 1)
        {
           int width = Form3->width ;
           int height = Form3->height ;
           if(width <0 || width >500 || height < 0|| height >500)
           {
           	ShowMessage("请输入 1--500的整数");
                return ;
           }
          Bitmap = new Graphics::TBitmap();
          Bitmap->Width = this->Image1->Picture->Width*width/100 ;
          Bitmap->Height = this->Image1->Picture->Height*height/100 ;
          Bitmap->Canvas->StretchDraw(TRect(0,0,Bitmap->Width,Bitmap->Height),this->Image1->Picture->Graphic);

          this->Image1->Picture->Graphic = Bitmap ;
          delete Bitmap ;
          //reset the form in the mem 
        Form3->Caption="新建文件";
        Form3->Label1->Caption = "宽度" ;
        Form3->Label2->Caption = "高度" ;

        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemImageInverseClick(TObject *Sender)
{
     for( int i = 0 ;  i< this->Image1->Width ;i++)
     {
     	for( int j = 0 ; j < this->Image1->Height ; j++)
        	{
                	this->Image1->Canvas->Pixels[i][j] = TColor(RGB(
                        0xff-BYTE(this->Image1->Canvas->Pixels[i][j]),
         		0xff-BYTE(this->Image1->Canvas->Pixels[i][j]>>8),
         		0xff-BYTE(this->Image1->Canvas->Pixels[i][j]>>16))) ;
                }
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if(this->Image1->Picture->Bitmap->Modified)
        {
        	int Choose = MessageDlg("是否保存对图像的修改",mtConfirmation,TMsgDlgButtons()<<mbYes<<mbCancel<<mbAbort,0);
                if(Choose == mrYes)
                {
                this->MenuItemFileSaveClick(Sender);
                   //child cancel
                   if(this->Image1->Picture->Bitmap->Modified)
                   {
                     CanClose = false;
                   }
                }
                else
                   if(Choose == mrAbort)
                {
                	CanClose = true ;
                }
                else
                {
                	CanClose = false ;
                }
        }	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemImageClearClick(TObject *Sender)
{
	this->MenuItemEditSelectAll->Click();
        this->MenuItemEditDelete->Click();	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemViewToolBoxClick(TObject *Sender)
{
	this->MenuItemViewToolBox->Checked = !this->MenuItemViewToolBox->Checked;
        if(!this->MenuItemViewToolBox->Checked)
        {
        	this->CoolBar1->Hide();
        }
        else
        {
                this->CoolBar1->Show();
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::MenuItemViewColorBoxClick(TObject *Sender)
{
        this->MenuItemViewColorBox->Checked = ! this->MenuItemViewColorBox->Checked ;
        if( !this->MenuItemViewColorBox->Checked)
        {
          this->CColorGrid1->Hide()    ;
        }
        else
        {
                this->CColorGrid1->Show();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuItemViewStatusBarClick(TObject *Sender)
{
         this->MenuItemViewStatusBar->Checked = ! this->MenuItemViewStatusBar->Checked;
        if( !this->MenuItemViewStatusBar->Checked)
        {
          this->StatusBar1->Hide();
        }
        else
        {
                this->StatusBar1->Show();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(typeText == true)
        {
                char letter = Key ;
                if(isprint(letter))
                {
                     this->Image1->Canvas->Font = typeFont ;
                     //judge whether text line
                     if(typeX > this->Image1->Width)
                     {
                     typeX = 0 ;
                     typeY += typeFont->Size*1.5;
                     }
                     //add x
                     this->Image1->Canvas->TextOutA(typeX,typeY,letter);
                     typeX+=typeFont->Size;

                }
              //this->Image1->Canvas->Font = Form2->FontDialog1->Font;


        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        if(this->FontDialog1->Execute())
        {
        typeFont = this->FontDialog1->Font ;
        }

}
//---------------------------------------------------------------------------

