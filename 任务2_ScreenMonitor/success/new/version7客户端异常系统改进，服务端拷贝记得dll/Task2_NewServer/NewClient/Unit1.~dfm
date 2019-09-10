object Form1: TForm1
  Left = 192
  Top = 130
  Width = 1083
  Height = 586
  Caption = #23631#24149#30417#25511#23458#25143#31471
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  Menu = MainMenu1
  OldCreateOrder = False
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 13
  object LeftPanel: TPanel
    Left = 0
    Top = 33
    Width = 169
    Height = 507
    Align = alLeft
    TabOrder = 0
    object Label1: TLabel
      Left = 4
      Top = 24
      Width = 58
      Height = 13
      Caption = #26381#21153#31471'IP    '
    end
    object Label2: TLabel
      Left = 8
      Top = 96
      Width = 75
      Height = 13
      Caption = #26381#21153#31471#31471#21475'     '
    end
    object Label3: TLabel
      Left = 16
      Top = 176
      Width = 60
      Height = 13
      Caption = #22270#20687#36136#37327'    '
      FocusControl = Button1
    end
    object Edit1: TEdit
      Left = 16
      Top = 48
      Width = 121
      Height = 21
      ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      TabOrder = 2
      Text = '192.168.255.162'
    end
    object Edit2: TEdit
      Left = 19
      Top = 128
      Width = 121
      Height = 21
      ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      TabOrder = 3
      Text = '900'
    end
    object TrackBar1: TTrackBar
      Left = 16
      Top = 200
      Width = 150
      Height = 45
      Max = 100
      Orientation = trHorizontal
      Frequency = 10
      Position = 80
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = TrackBar1Change
    end
    object Button1: TButton
      Left = 8
      Top = 272
      Width = 89
      Height = 25
      Caption = #36830#25509#26381#21153#31471'  '
      TabOrder = 1
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 8
      Top = 304
      Width = 89
      Height = 25
      Caption = #26029#24320#36830#25509
      TabOrder = 4
      Visible = False
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 8
      Top = 336
      Width = 89
      Height = 25
      Caption = #21551#21160#30417#25511
      TabOrder = 5
      Visible = False
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 8
      Top = 368
      Width = 89
      Height = 25
      Caption = #20851#38381#30417#25511
      TabOrder = 6
      Visible = False
      OnClick = Button4Click
    end
    object Panel1: TPanel
      Left = 1
      Top = 440
      Width = 167
      Height = 66
      Align = alBottom
      TabOrder = 7
      object Button5: TButton
        Left = 32
        Top = 33
        Width = 75
        Height = 25
        Caption = #28165#31354#30417#25511#35760#24405
        TabOrder = 0
        OnClick = Button5Click
      end
      object CheckBox1: TCheckBox
        Left = 32
        Top = 9
        Width = 97
        Height = 17
        Caption = #21551#21160#30417#25511#26085#24535
        TabOrder = 1
        OnClick = CheckBox1Click
      end
    end
  end
  object CenterPanel: TPanel
    Left = 169
    Top = 33
    Width = 184
    Height = 507
    Align = alLeft
    TabOrder = 1
    object Memo1: TMemo
      Left = 1
      Top = 1
      Width = 182
      Height = 505
      Align = alClient
      ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      Lines.Strings = (
        #24403#21069#29366#24577)
      ScrollBars = ssBoth
      TabOrder = 0
    end
  end
  object ScrollBox1: TScrollBox
    Left = 353
    Top = 33
    Width = 722
    Height = 507
    Align = alClient
    TabOrder = 2
    object Image1: TImage
      Left = 0
      Top = 0
      Width = 697
      Height = 513
      AutoSize = True
      IncrementalDisplay = True
      OnClick = Image1Click
      OnDblClick = Image1DblClick
      OnMouseMove = Image1MouseMove
      OnMouseUp = Image1MouseUp
    end
  end
  object NorthPanel: TPanel
    Left = 0
    Top = 0
    Width = 1075
    Height = 33
    Align = alTop
    Caption = #36864#20986#20840#23631
    TabOrder = 3
    Visible = False
    OnClick = NorthPanelClick
  end
  object ClientSocket1: TClientSocket
    Active = False
    Address = '192.168.255.162'
    ClientType = ctNonBlocking
    Port = 900
    OnConnect = ClientSocket1Connect
    OnDisconnect = ClientSocket1Disconnect
    OnRead = ClientSocket1Read
    OnError = ClientSocket1Error
    Left = 48
    Top = 424
  end
  object MainMenu1: TMainMenu
    Left = 88
    Top = 424
    object MenuItemControl: TMenuItem
      Caption = #25511#21046
      object MenuItemControlFullScreen: TMenuItem
        Caption = #20840#23631
        OnClick = MenuItemControlFullScreenClick
      end
      object MenuItemControlFullScreenExit: TMenuItem
        Caption = #36864#20986#20840#23631
        Visible = False
        OnClick = MenuItemControlFullScreenExitClick
      end
      object MenuItemControlExit: TMenuItem
        Caption = #36864#20986#31243#24207
        OnClick = MenuItemControlExitClick
      end
    end
  end
  object Timer1: TTimer
    Interval = 200
    OnTimer = Timer1Timer
    Left = 120
    Top = 304
  end
end
