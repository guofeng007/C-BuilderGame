//---------------UnitSerial.cpp------------------------------------------------


#pragma hdrstop

#include "UnitSerial.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#define BOOL bool
CSerial::CSerial()
{
    memset( &m_OverlappedRead, 0, sizeof( OVERLAPPED ) );
    memset( &m_OverlappedWrite, 0, sizeof( OVERLAPPED ) );
    m_hCom = NULL;
    m_bOpened = FALSE;
}

CSerial::~CSerial() 
{
    Close();
}

BOOL CSerial::Open(UI nPort,UI nBaud,UI nParity,UI nByteSize,UI nStopBits)
{

    if( m_bOpened )
    {
    ShowMessage("Already opened!");
    return( TRUE );

    }

    char szPort[15]={0};

    DCB dcb;
    wsprintf( szPort, "COM%d", nPort );
    m_hCom = CreateFile( szPort,GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,
    FILE_ATTRIBUTE_NORMAL|FILE_FLAG_OVERLAPPED,NULL);

    if( m_hCom == INVALID_HANDLE_VALUE ) return( false );

    memset(&m_OverlappedRead,0,sizeof(OVERLAPPED));
    memset(&m_OverlappedWrite,0,sizeof(OVERLAPPED));

    COMMTIMEOUTS CommTimeOuts;
    CommTimeOuts.ReadIntervalTimeout = 0xFFFFFFFF;
    CommTimeOuts.ReadTotalTimeoutMultiplier = 0;
    CommTimeOuts.ReadTotalTimeoutConstant = 0;
    CommTimeOuts.WriteTotalTimeoutMultiplier = 0;
    CommTimeOuts.WriteTotalTimeoutConstant = 5000;
    SetCommTimeouts( m_hCom,&CommTimeOuts );

//    wsprintf( szComParams, "COM%d:%d,n,8,1", nPort, nBaud );
    
    m_OverlappedRead.hEvent = CreateEvent( NULL, TRUE, FALSE, NULL );
    m_OverlappedWrite.hEvent = CreateEvent( NULL, TRUE, FALSE, NULL );

    GetCommState(m_hCom,&dcb );
    dcb.DCBlength = sizeof( DCB );
    dcb.BaudRate = (unsigned long)nBaud;
    dcb.Parity = nParity;
    dcb.ByteSize = nByteSize;
    dcb.StopBits = nStopBits;

    if(!SetCommState(m_hCom,&dcb)||!SetupComm(m_hCom,1024,1024 )||
    m_OverlappedRead.hEvent == NULL||m_OverlappedWrite.hEvent == NULL)
    {

 if(m_OverlappedRead.hEvent!= NULL) CloseHandle(m_OverlappedRead.hEvent);
 if(m_OverlappedWrite.hEvent!= NULL) CloseHandle(m_OverlappedWrite.hEvent);
 CloseHandle( m_hCom );
 return( FALSE );
    }

    m_bOpened = TRUE;
    return( m_bOpened );
}

BOOL CSerial::Close( void ) 
{
    if(!m_bOpened||m_hCom == NULL ) return(TRUE );
    if(m_OverlappedRead.hEvent!= NULL ) CloseHandle(m_OverlappedRead.hEvent );
    if( m_OverlappedWrite.hEvent!= NULL ) CloseHandle(m_OverlappedWrite.hEvent );
    CloseHandle(m_hCom );
    m_bOpened = FALSE;
    m_hCom = NULL;
    return( TRUE );
}

BOOL CSerial::WriteCommByte( unsigned char ucByte )   //发送单个字节
{
    BOOL bWriteStat;
    DWORD dwBytesWritten;

    bWriteStat = WriteFile( m_hCom, (LPSTR) &ucByte, 1, &dwBytesWritten, &m_OverlappedWrite );
    if(!bWriteStat&&( GetLastError() == ERROR_IO_PENDING ) )
    {
 if(WaitForSingleObject( m_OverlappedWrite.hEvent, 1000 ) ) dwBytesWritten = 0;
 else{
 GetOverlappedResult( m_hCom, &m_OverlappedWrite, &dwBytesWritten, FALSE );
 m_OverlappedWrite.Offset += dwBytesWritten;
        }
    }
    return( TRUE );
}

int CSerial::SendData( const unsigned char *buffer, int size ) //发送批量数据

{
    if(!m_bOpened||m_hCom == NULL) return( 0 );

    DWORD dwBytesWritten = 0;
    int i;

    for( i=0;i    {
      WriteCommByte(buffer[i]);
      dwBytesWritten++;
    }

    return((int)dwBytesWritten);
}

int CSerial::ReadDataWaiting(void)                   // 待读的字节数
{
    if(!m_bOpened||m_hCom == INVALID_HANDLE_VALUE ) return( 0 );

    DWORD dwErrorFlags;
    COMSTAT ComStat;
    ClearCommError(m_hCom,&dwErrorFlags, &ComStat );
    return((int)ComStat.cbInQue);
}

int CSerial::ReadData( unsigned char *buffer, int limit )    // 读出数据
{
    if(!m_bOpened ||m_hCom == NULL ) return( 0 );
    BOOL bReadStatus;
    DWORD dwBytesRead, dwErrorFlags;
    COMSTAT ComStat;

    ClearCommError( m_hCom,&dwErrorFlags, &ComStat );
    if(!ComStat.cbInQue) return( 0 );

    dwBytesRead = (DWORD) ComStat.cbInQue;

    if(limit<(int)dwBytesRead) dwBytesRead = (DWORD) limit;
    bReadStatus = ReadFile(m_hCom, buffer, dwBytesRead, &dwBytesRead, &m_OverlappedRead );
    if(!bReadStatus)
    {
 if(GetLastError() == ERROR_IO_PENDING )
 {
 WaitForSingleObject( m_OverlappedRead.hEvent, 2000 );
 return( (int) dwBytesRead );
 }
    return(0);
    }
return((int)dwBytesRead);
}

bool CSerial::ClearInBuff()
{
        return (PurgeComm(m_hCom,PURGE_RXCLEAR));
}

bool CSerial::ClearOutBuff()
{
        return (PurgeComm(m_hCom,PURGE_TXCLEAR));
}


