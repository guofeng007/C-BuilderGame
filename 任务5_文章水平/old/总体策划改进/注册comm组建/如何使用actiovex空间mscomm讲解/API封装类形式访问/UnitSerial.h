//------------------------UnitSerial.h-------------------------------

#ifndef UnitSerialH
#define UnitSerialH
//---------------------------------------------------------------------------
#include 


#define FC_DTRDSR 0x01
#define FC_RTSCTS 0x02
#define FC_XONXOFF 0x04
#define ASCII_BEL 0x07
#define ASCII_BS 0x08
#define ASCII_LF 0x0A
#define ASCII_CR 0x0D
#define ASCII_XON 0x11
#define BOOL bool
typedef unsigned int UI;

class CSerial
{
public:
    CSerial();
    ~CSerial();
    BOOL Open(UI nPort = 2,UI nBaud = 9600,UI nParity=NOPARITY,UI nByteSize=8,UI nStopBits=1);
    BOOL Close( void );
    int ReadData( unsigned char *, int );
    int SendData( const unsigned char *, int );
    bool ClearInBuff();
    bool ClearOutBuff();
    int ReadDataWaiting( void );
    BOOL IsOpened( void ){ return( m_bOpened ); }
    HANDLE m_hCom;
protected:
    BOOL WriteCommByte( unsigned char );

    OVERLAPPED m_OverlappedRead, m_OverlappedWrite;
    BOOL m_bOpened;
};

#endif