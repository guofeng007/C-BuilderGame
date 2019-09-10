//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "stdio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"  
int width = 0 ;
int height = 0 ;
AnsiString  embeddata = "";
int         embedSize = 0 ;
int         embedCount = 1 ; //AnsiString [] starts from 1
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	width  =this->Image2->Width ;
        height = this->Image2->Height;       
        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)

{
	byte r , rnext ;
	TColor colorLeft ,colorRight   ;
        /*   扫描像素
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
        {//防止越界

        
        //左边的图像
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


        //右边的图像
        colorRight = this->Image2->Canvas->Pixels[X][Y];
        r  = GetRValue(colorRight);
        colorRight = this->Image2->Canvas->Pixels[X+1][Y];
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

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree ; 
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if(this->OpenDialog1->Execute())
        {
        	AnsiString FileName = OpenDialog1->FileName ;
                int File =   FileOpen(FileName,fmOpenRead);
                //获取文件内容真正的大小
		int length =  GetCompressedFileSize(FileName.c_str(),NULL);
                byte *buf = (byte *)malloc(length);
                char *content = (char *)malloc(length);
                //read file to buf
                FileRead(File,buf,length);
                FileSeek(File,0,0);
                FileRead(File,content,length);
                FileClose(File);
                this->MemoLeftData->Text = AnsiString(content);
//store global data
                embeddata = BinaryToString(buf,length);
                embedSize = length * 8 ;
                free(content);
                free(buf);

               

        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{

//1.图像数组
       Byte *data ;  // data[] 处理一行数据
       this->Image2->Picture->Bitmap->PixelFormat = pf8bit ;
       Graphics::TBitmap * bitmap = this->Image2->Picture->Bitmap ;
//2.计算差值
        DynamicArray< DynamicArray <int> > h ;
        TObjectList  *positionXY = new TObjectList(true);
        TObjectList  *map  = new TObjectList(true);
        h.Length = height;
        for(int i = 0 ; i < height ; i++)
        {
        	h[i].Length = width /2 ;
                data = static_cast<Byte *> (this->Image2->Picture->Bitmap->ScanLine[i]) ;

        	for(int j = 0 ; j < width /2 ; j++)
                {
	                //compute the difference                
                      h[i][j] = data[2*j] - data[2*j+1]  ;
                      //averate
                      int average = (data[2*j] + data[2*j+1]) /2 ;
                      //judge Expandable
//3.把差值分类 统计可以差值的位置
                      if( ( h[i][j] < 2*(255-average) )&&( h[i][j] > 0) && ( h[i][j] < 2*average+1 )&& ( h[i][j] > 0 ) )
                      {
                      	   TPoint *p = new TPoint;
                           p->x = i ;
                           p->y = j ; //map the pair(a,b) a{x,y}
                          
//4.嵌入数据

			   if( embedCount <= embedSize )
                           {
                           //expand difference

                                h[i][j] = 2*h[i][j] ; //无论怎样都要左移，是否加1的问题后面看
                           	if(    embeddata.operator [](embedCount) == '1')
                                {
                      			h[i][j] = h[i][j]+ 1 ;
                                }
                                embedCount++ ;
                           //recaculate x y
                           data[2*j] = average + (h[i][j]+1)/2 ;
                           data[2*j+1] = average - h[i][j]/2 ;     
                            map->Add((TObject *)p);
                            TPoint *pair = new TPoint(data[2*j],data[2*j+1]);
                            positionXY->Add((TObject *)pair);

                           }
                           else
                           {
//5.存储map
			    if(this->SaveDialog1->Execute())
                            {

                                //保存map
                            	AnsiString FileName = this->SaveDialog1->FileName;
                                int handle = FileCreate(FileName);                              
                                for(int a = 0 ; a < map->Count ; a++)
                                {
                                     TPoint * p = (TPoint *)map->Items[a] ;
                                     FileWrite(handle,p,sizeof(TPoint));                                     

                                }
                                FileClose(handle);
                               // stop this->Image2->Canvas->Draw(0,0,bitmap) ;
                                //保存h[i][j];
                                AnsiString strH = "";
                                for(int a = 0 ;  a <= i ; a++)
                                {
                                	for(int b = 0 ; b <= j ; b++)
                                        {
                                           strH +=AnsiString(h[a][b])+";";
                                        }


                                }
                                 AnsiString dirFileName = ExtractFilePath(FileName) +"difference.txt";
                                 int difHandle = FileCreate(dirFileName);
                                 FileWrite(difHandle,strH.c_str(),strH.Length());
                                 FileClose(difHandle);
                                //保存修改坐标值
                                AnsiString valueFileName = ExtractFilePath(FileName) + "value.txt" ;
                                int valueHandle =  FileCreate(valueFileName);
                                AnsiString pairStr = "" ;
                                for(int x = 0 ;  x < positionXY->Count ; x++)
                                {

                                	TPoint *pair = (TPoint *)positionXY->Items[x] ;
                                         pairStr += AnsiString(pair->x) + "," + AnsiString(pair->y) + ";" ;
                                }
                                FileWrite(valueHandle,pairStr.c_str(),pairStr.Length());
                                FileClose(valueHandle) ;
                                return ;
                            }

                              
                           }

                      }
                }
        }



//6. 清理
delete map ;	
        





}
//---------------------------------------------------------------------------
AnsiString __fastcall TForm1::BinaryToString(byte * data ,int length)
{

	AnsiString binaryStr  = "" ;
          for(int i = 0 ;  i < length ; i++)
          {
          	byte temp = data[i] ;
          	for(int j = 0 ;  j < 8 ; j++ )
                {
                   if(temp&0x1 == 1)
                   {
                   	binaryStr +="1" ;
                   }
                   else
                   {
			binaryStr +="0" ;
                   }

                   temp >>=1 ;

                }
          }
          return binaryStr ;
}

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	if(SaveDialog1->Execute())
        {
        	AnsiString FileName = SaveDialog1->FileName ;
                this->Image2->Picture->Bitmap->SaveToFile(FileName);
        }
}
//---------------------------------------------------------------------------


