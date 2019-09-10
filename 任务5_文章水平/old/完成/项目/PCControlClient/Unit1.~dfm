object Form1: TForm1
  Left = 540
  Top = 248
  Width = 571
  Height = 388
  Caption = 'FishClient'
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
    Width = 555
    Height = 49
    Align = alTop
    TabOrder = 0
    object Label3: TLabel
      Left = 16
      Top = 16
      Width = 34
      Height = 13
      Caption = #36828#31243'IP'
    end
    object Label4: TLabel
      Left = 152
      Top = 21
      Width = 48
      Height = 13
      Caption = #36828#31243#31471#21475
    end
    object Label5: TLabel
      Left = 272
      Top = 16
      Width = 72
      Height = 13
      Caption = #36828#31243#36830#25509#29366#24577
    end
    object Edit2: TEdit
      Left = 72
      Top = 16
      Width = 65
      Height = 21
      ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      TabOrder = 0
      Text = '127.0.0.1'
    end
    object Edit3: TEdit
      Left = 224
      Top = 16
      Width = 49
      Height = 21
      ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      TabOrder = 1
      Text = '2000'
    end
    object Button2: TButton
      Left = 376
      Top = 8
      Width = 75
      Height = 25
      Caption = #36830#25509#26381#21153#31471
      TabOrder = 2
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 464
      Top = 8
      Width = 75
      Height = 25
      Caption = #20851#38381#36830#25509
      TabOrder = 3
      Visible = False
      OnClick = Button3Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 49
    Width = 555
    Height = 301
    Align = alClient
    TabOrder = 1
    object Panel3: TPanel
      Left = 1
      Top = 1
      Width = 553
      Height = 41
      Align = alTop
      TabOrder = 0
      object Label1: TLabel
        Left = 40
        Top = 8
        Width = 96
        Height = 13
        Caption = #30452#25509#21457#36865#25511#21046#25351#20196
      end
      object ComboBox1: TComboBox
        Left = 176
        Top = 6
        Width = 145
        Height = 21
        ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        ItemHeight = 13
        TabOrder = 0
        Text = #21551#21160
        Items.Strings = (
          #21551#21160
          #20851#38381
          '0'#24230
          '30'#24230
          '60'#24230
          '90'#24230
          '120'#24230
          '150'#24230
          '180'#24230)
      end
      object Button1: TButton
        Left = 360
        Top = 8
        Width = 75
        Height = 25
        Caption = #21457#36865
        TabOrder = 1
        OnClick = Button1Click
      end
    end
    object Panel4: TPanel
      Left = 1
      Top = 42
      Width = 553
      Height = 258
      Align = alClient
      TabOrder = 1
      object Pie1: TPie
        Left = 40
        Top = 16
        Width = 200
        Height = 200
        Angles.StartAngle = 180
        Angles.EndAngle = 90
        Brush.Color = clBlue
        Brush.Style = bsCross
        OnMouseMove = Pie1MouseMove
      end
      object Label2: TLabel
        Left = 312
        Top = 32
        Width = 48
        Height = 13
        Caption = #21457#36865#38408#20540
      end
      object Edit1: TEdit
        Left = 416
        Top = 32
        Width = 49
        Height = 21
        ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        TabOrder = 0
        Text = '10'
        OnChange = Edit1Change
      end
    end
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 0
    OnDisconnect = ClientSocket1Disconnect
    OnError = ClientSocket1Error
    Left = 464
    Top = 152
  end
end
