object Form1: TForm1
  Left = 362
  Top = 278
  Width = 343
  Height = 230
  Caption = #26381#21153#31471
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 32
    Top = 64
    Width = 281
    Height = 89
    Stretch = True
  end
  object Button1: TButton
    Left = 64
    Top = 32
    Width = 75
    Height = 25
    Caption = #21551#21160#26381#21153#31471
    TabOrder = 0
    OnClick = Button1Click
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 173
    Width = 327
    Height = 19
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object Button2: TButton
    Left = 160
    Top = 32
    Width = 75
    Height = 25
    Caption = #20572#27490#26381#21153
    TabOrder = 2
    OnClick = Button2Click
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
    Left = 16
  end
  object PopupMenu1: TPopupMenu
    Left = 56
    object PopupStart: TMenuItem
      Caption = #21551#21160#26381#21153
      OnClick = Button1Click
    end
    object PopupStop: TMenuItem
      Caption = #20572#27490#26381#21153
      OnClick = Button2Click
    end
    object PopupHideShow: TMenuItem
      Caption = #26174#31034'/'#38544#34255#30028#38754
      Checked = True
      Default = True
      OnClick = PopupHideShowClick
    end
    object PopupExit: TMenuItem
      Caption = #36864#20986
      OnClick = PopupExitClick
    end
  end
  object TrayIcon1: TTrayIcon
    Visible = True
    PopupMenu = PopupMenu1
    Hide = True
    RestoreOn = imDoubleClick
    PopupMenuOn = imRightClickUp
    Left = 256
    Top = 160
  end
end
