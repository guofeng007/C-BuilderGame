object Form1: TForm1
  Left = 192
  Top = 130
  BorderStyle = bsSingle
  Caption = 'Fish'#23458#25143#31471
  ClientHeight = 396
  ClientWidth = 714
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 714
    Height = 49
    Align = alTop
    TabOrder = 0
    object Panel7: TPanel
      Left = 1
      Top = 1
      Width = 64
      Height = 47
      Align = alLeft
      TabOrder = 0
      DesignSize = (
        64
        47)
      object Label2: TLabel
        Left = 6
        Top = 9
        Width = 48
        Height = 13
        Anchors = [akLeft, akTop, akRight, akBottom]
        Caption = #36873#25321#20018#21475
      end
    end
    object Panel8: TPanel
      Left = 65
      Top = 1
      Width = 121
      Height = 47
      Align = alLeft
      TabOrder = 1
      DesignSize = (
        121
        47)
      object ComboBox1: TComboBox
        Left = 20
        Top = 8
        Width = 57
        Height = 21
        Anchors = [akLeft, akTop, akRight, akBottom]
        ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        ItemHeight = 13
        TabOrder = 0
        Text = 'COM2'
        Items.Strings = (
          'COM1'
          'COM2'
          'COM3'
          'COM4'
          'COM5'
          'COM6'
          'COM7'
          'COM8'
          'COM9')
      end
    end
    object Panel9: TPanel
      Left = 186
      Top = 1
      Width = 95
      Height = 47
      Align = alLeft
      TabOrder = 2
      DesignSize = (
        95
        47)
      object Button1: TButton
        Left = 8
        Top = 8
        Width = 65
        Height = 31
        Anchors = [akLeft, akTop, akRight, akBottom]
        Caption = #25171#24320#20018#21475
        TabOrder = 0
        OnClick = Button1Click
      end
    end
    object Panel10: TPanel
      Left = 281
      Top = 1
      Width = 81
      Height = 47
      Align = alLeft
      TabOrder = 3
      DesignSize = (
        81
        47)
      object Label1: TLabel
        Left = 8
        Top = 6
        Width = 48
        Height = 13
        Anchors = [akLeft, akTop, akRight, akBottom]
        Caption = #20018#21475#29366#24577
      end
      object Label5: TLabel
        Left = -3
        Top = 24
        Width = 84
        Height = 13
        Caption = #36828#31243#26381#21153#31471#29366#24577
      end
    end
    object Panel11: TPanel
      Left = 362
      Top = 1
      Width = 87
      Height = 47
      Align = alLeft
      TabOrder = 4
      object Button2: TButton
        Left = 7
        Top = 8
        Width = 66
        Height = 25
        Caption = #20851#38381#20018#21475
        TabOrder = 0
        Visible = False
        OnClick = Button2Click
      end
    end
    object Panel12: TPanel
      Left = 449
      Top = 1
      Width = 264
      Height = 47
      Align = alClient
      TabOrder = 5
      object Button6: TButton
        Left = 0
        Top = 8
        Width = 106
        Height = 25
        Caption = #35774#32622#36828#31243#26381#21153#21442#25968
        TabOrder = 0
        OnClick = Button6Click
      end
      object Button7: TButton
        Left = 112
        Top = 8
        Width = 75
        Height = 25
        Caption = #36830#25509#26381#21153#31471
        TabOrder = 1
        OnClick = Button7Click
      end
      object Button8: TButton
        Left = 192
        Top = 8
        Width = 75
        Height = 25
        Caption = #20851#38381#36830#25509
        TabOrder = 2
        Visible = False
        OnClick = Button8Click
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 49
    Width = 714
    Height = 347
    Align = alClient
    TabOrder = 1
    object StatusBar1: TStatusBar
      Left = 1
      Top = 327
      Width = 712
      Height = 19
      Panels = <
        item
          Text = 'RXD'#25509#25910#23383#33410':0'
          Width = 200
        end
        item
          Text = 'TXD'#21457#36865#23383#33410':0'
          Width = 200
        end
        item
          Text = #26381#21153#31471#36830#25509#29366#24577
          Width = 50
        end>
      SimplePanel = False
    end
    object Panel3: TPanel
      Left = 1
      Top = 1
      Width = 360
      Height = 326
      Align = alClient
      TabOrder = 1
      object Panel4: TPanel
        Left = 1
        Top = 1
        Width = 358
        Height = 41
        Align = alTop
        TabOrder = 1
        object Label3: TLabel
          Left = 16
          Top = 12
          Width = 48
          Height = 13
          Caption = #25509#25910#25968#25454
        end
        object Button3: TButton
          Left = 80
          Top = 5
          Width = 75
          Height = 25
          Caption = #28165#31354#25509#25910#21306
          TabOrder = 0
          OnClick = Button3Click
        end
        object BitBtn1: TBitBtn
          Left = 160
          Top = 6
          Width = 68
          Height = 25
          Caption = #28165#31354#35745#25968#22120
          TabOrder = 1
          OnClick = BitBtn1Click
        end
      end
      object Memo1: TMemo
        Left = 1
        Top = 42
        Width = 358
        Height = 283
        Align = alClient
        ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object Panel5: TPanel
      Left = 361
      Top = 1
      Width = 352
      Height = 326
      Align = alRight
      TabOrder = 2
      object Memo2: TMemo
        Left = 1
        Top = 42
        Width = 350
        Height = 283
        Align = alClient
        ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        ScrollBars = ssVertical
        TabOrder = 0
      end
      object Panel6: TPanel
        Left = 1
        Top = 1
        Width = 350
        Height = 41
        Align = alTop
        TabOrder = 1
        object Label4: TLabel
          Left = 3
          Top = 13
          Width = 48
          Height = 13
          Caption = #21457#36865#25968#25454
        end
        object Button4: TButton
          Left = 64
          Top = 10
          Width = 57
          Height = 21
          Caption = #21457#36865
          TabOrder = 0
          OnClick = Button4Click
        end
        object Button5: TButton
          Left = 141
          Top = 7
          Width = 75
          Height = 25
          Caption = #28165#31354#21457#36865#21306
          TabOrder = 1
          OnClick = Button5Click
        end
        object BitBtn2: TBitBtn
          Left = 232
          Top = 8
          Width = 81
          Height = 25
          Caption = #28165#31354#35745#25968#22120
          TabOrder = 2
          OnClick = BitBtn2Click
        end
      end
    end
  end
  object MSComm1: TMSComm
    Left = 272
    Top = 56
    Width = 32
    Height = 32
    OnComm = MSComm1Comm
    ControlData = {
      2143341208000000ED030000ED03000001568A64000006000000010000040000
      00020000802500000000080000000000000000003F00000001000000}
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 0
    OnConnecting = ClientSocket1Connecting
    OnConnect = ClientSocket1Connect
    OnDisconnect = ClientSocket1Disconnect
    OnRead = ClientSocket1Read
    OnError = ClientSocket1Error
    Left = 248
    Top = 56
  end
end
