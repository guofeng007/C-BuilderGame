//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include<jpeg.hpp>
#pragma hdrstop
//---------------------------------------------------------------------------
//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you
//---------------------------------------------------------------------------
extern "C"
{
        void __export __stdcall   CaptureImage(int cq,TMemoryStream * imgstream);
}
#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
        return 1;
}
//---------------------------------------------------------------------------
void __stdcall CaptureImage(int cq,TMemoryStream * imgstream)
{
	LONG width ,height ;
        RECT capRect ;
        HDC DesktopDC ;

        GetWindowRect(GetDesktopWindow(),&capRect);

        DesktopDC = GetDC(GetDesktopWindow()); //memDC
        width = capRect.right - capRect.left;
        height = capRect.bottom-capRect.top ;
        Graphics::TBitmap *bBitmap ;//birmap

        try
        {
                bBitmap = new Graphics::TBitmap();
                bBitmap->Width = width ;
                bBitmap->Height = height ;
                //deep
                 bBitmap->PixelFormat = TPixelFormat(pf24bit);

                //copy
                BitBlt(bBitmap->Canvas->Handle,0,0,width,height,DesktopDC,capRect.left,capRect.top,SRCCOPY);
                // this->Image1->Picture->Bitmap = bBitmap ;
                //compress
                if(cq >=0)
                {
                	TJPEGImage *jpeg ;
                        try
                        {
                        	jpeg = new TJPEGImage() ;
                                jpeg->CompressionQuality = cq ;
                                jpeg->Assign(bBitmap);
                                jpeg->SaveToStream(imgstream);
		

                        } 
                        __finally
                        {
                        	delete jpeg;
                        }
                }
                else
                {
                      bBitmap->SaveToStream(imgstream);
                }
        } 
        __finally
        {
           delete bBitmap ;
        }
}