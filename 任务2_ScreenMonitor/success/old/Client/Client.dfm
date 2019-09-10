object Form1: TForm1
  Left = 275
  Top = 139
  BorderStyle = bsSingle
  Caption = #23631#24149#30417#25511#23458#25143#31471
  ClientHeight = 420
  ClientWidth = 748
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 748
    Height = 401
    Align = alClient
    PopupMenu = PopupMenu1
    Stretch = True
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 401
    Width = 748
    Height = 19
    Panels = <>
    SimplePanel = False
  end
  object ClientSocket1: TClientSocket
    Active = False
    Address = '192.168.255.150'
    ClientType = ctNonBlocking
    Port = 900
    OnConnecting = ClientSocket1Connecting
    OnConnect = ClientSocket1Connect
    OnDisconnect = ClientSocket1Disconnect
    OnRead = ClientSocket1Read
    OnError = ClientSocket1Error
    Left = 8
    Top = 376
  end
  object SavePictureDialog1: TSavePictureDialog
    Left = 56
    Top = 376
  end
  object MainMenu1: TMainMenu
    Left = 104
    Top = 380
    object MenuConnect: TMenuItem
      Caption = #36830#25509'(&C)'
      object MenuItemConnectSet: TMenuItem
        Caption = #35774#32622#21442#25968'(&S)'
        OnClick = MenuItemConnectSetClick
      end
      object MenuItemConnectConnect: TMenuItem
        Caption = #24314#31435#36830#25509'(&O)'
        Enabled = False
        OnClick = MenuItemConnectConnectClick
      end
      object MenuItemConnectClose: TMenuItem
        Caption = #26029#24320#36830#25509'(&C)'
        Enabled = False
        OnClick = MenuItemConnectCloseClick
      end
      object MenuItemConnectExit: TMenuItem
        Caption = #36864#20986#31243#24207'(&E)'
        ShortCut = 16472
        OnClick = MenuItemConnectExitClick
      end
    end
    object MenuImage: TMenuItem
      Caption = #22270#20687'(&I)'
      object MenuItemImageFullScreen: TMenuItem
        Caption = #20840#23631'(&S)'
        OnClick = MenuItemImageFullScreenClick
      end
      object MenuItemImageAutoScale: TMenuItem
        Caption = #33258#21160#32553#25918
        OnClick = MenuItemImageAutoScaleClick
      end
      object MenuItemImageSave: TMenuItem
        Caption = #20445#23384#22270#20687
        OnClick = MenuItemImageSaveClick
      end
      object MenuItemImageNext: TMenuItem
        Caption = #19979#19968#24133#22270#20687
        OnClick = MenuItemImageNextClick
      end
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 160
    Top = 384
    object PopupMenuConnect: TMenuItem
      Caption = #36830#25509
      object PopupMenuItemConnectSet: TMenuItem
        Caption = #35774#32622#36830#25509
        OnClick = MenuItemConnectSetClick
      end
      object PopupMenuItemConnectConnect: TMenuItem
        Caption = #36830#25509
        OnClick = MenuItemConnectConnectClick
      end
      object PopupMenuItemConnectClose: TMenuItem
        Caption = #26029#24320
        OnClick = MenuItemConnectCloseClick
      end
      object PopupMenuItemConnectExit: TMenuItem
        Caption = #36864#20986#31243#24207
        OnClick = MenuItemConnectExitClick
      end
    end
    object PopupMenuImage: TMenuItem
      Caption = #22270#20687
      object PopupMenuItemFullScreen: TMenuItem
        Caption = #20840#23631
        OnClick = MenuItemImageFullScreenClick
      end
      object PopupMenuItemAutoScale: TMenuItem
        Caption = #33258#21160#32553#25918
        OnClick = MenuItemImageAutoScaleClick
      end
      object PopupMenuItemSave: TMenuItem
        Caption = #20445#23384#22270#20687
        OnClick = MenuItemImageSaveClick
      end
      object PopupMenuItemNext: TMenuItem
        Caption = #19979#19968#24133#22270#20687
        OnClick = MenuItemImageNextClick
      end
    end
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 232
    Top = 392
  end
end
