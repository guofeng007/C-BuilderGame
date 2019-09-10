object Form1: TForm1
  Left = 216
  Top = 107
  Width = 747
  Height = 548
  Caption = #26381#21153#31471
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 257
    Top = 0
    Width = 482
    Height = 521
    Align = alClient
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 257
    Height = 521
    Align = alLeft
    TabOrder = 1
    object Label1: TLabel
      Left = 17
      Top = 48
      Width = 60
      Height = 13
      Caption = #26381#21153#22120#31471#21475
    end
    object Edit1: TEdit
      Left = 122
      Top = 40
      Width = 121
      Height = 21
      ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      TabOrder = 0
      Text = '900'
    end
    object Button1: TButton
      Left = 16
      Top = 144
      Width = 91
      Height = 25
      Caption = #21551#21160#26381#21153#22120
      TabOrder = 1
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 120
      Top = 144
      Width = 113
      Height = 25
      Caption = #20851#38381#26381#21153#22120
      TabOrder = 2
      Visible = False
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 16
      Top = 224
      Width = 75
      Height = 25
      Caption = #38544#34255#20027#31383#20307
      TabOrder = 3
      OnClick = Button3Click
    end
    object Memo2: TMemo
      Left = 0
      Top = 280
      Width = 185
      Height = 89
      Lines.Strings = (
        'Ctrl+S '#26174#31034#20027#31383#20307
        'Ctrl+H '#38544#34255#20027#31383#20307)
      TabOrder = 4
    end
  end
  object ServerSocket1: TServerSocket
    Active = False
    Port = 900
    ServerType = stNonBlocking
    OnAccept = ServerSocket1Accept
    OnClientConnect = ServerSocket1ClientConnect
    OnClientDisconnect = ServerSocket1ClientDisconnect
    OnClientRead = ServerSocket1ClientRead
    OnClientError = ServerSocket1ClientError
    Top = 488
  end
end
