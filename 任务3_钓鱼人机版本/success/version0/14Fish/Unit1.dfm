object Form1: TForm1
  Left = 199
  Top = 143
  Width = 1141
  Height = 645
  Caption = '14'#28857#38035#40060#31243#24207
  Color = clAqua
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object TopPanel: TPanel
    Left = 0
    Top = 0
    Width = 1125
    Height = 193
    Align = alTop
    Color = clSkyBlue
    TabOrder = 0
    object Label3: TLabel
      Left = 616
      Top = 8
      Width = 99
      Height = 13
      Caption = #23545#25163#19978#36718#38035#40060'         '
    end
    object TopLeft: TPanel
      Left = 8
      Top = 8
      Width = 217
      Height = 185
      Color = clAqua
      TabOrder = 0
      object Label1: TLabel
        Left = 16
        Top = 64
        Width = 93
        Height = 13
        Caption = #23545#25163#24403#21069#24471#20998#65306'   '
      end
      object OpponentScoreLabel: TLabel
        Left = 120
        Top = 64
        Width = 6
        Height = 13
        Caption = '0'
      end
    end
    object TopMiddle: TPanel
      Left = 232
      Top = 8
      Width = 361
      Height = 161
      BorderStyle = bsSingle
      Color = clLime
      TabOrder = 1
      object OpponentImage1: TImage
        Left = 8
        Top = 8
        Width = 105
        Height = 137
        Stretch = True
      end
      object OpponentImage2: TImage
        Left = 120
        Top = 8
        Width = 105
        Height = 137
        Stretch = True
      end
      object OpponentImage3: TImage
        Left = 232
        Top = 8
        Width = 105
        Height = 137
        Stretch = True
      end
    end
    object TopRight: TPanel
      Left = 656
      Top = 24
      Width = 465
      Height = 161
      Color = clSkyBlue
      TabOrder = 2
      object OpponentLast3: TImage
        Left = 240
        Top = 8
        Width = 105
        Height = 137
        Stretch = True
      end
      object OpponentLast2: TImage
        Left = 128
        Top = 8
        Width = 105
        Height = 137
        Stretch = True
      end
      object OpponentLast1: TImage
        Left = 16
        Top = 8
        Width = 105
        Height = 137
        Stretch = True
      end
      object OpponentLast4: TImage
        Left = 352
        Top = 8
        Width = 105
        Height = 137
        Stretch = True
      end
    end
  end
  object MiddlePanel: TPanel
    Left = 0
    Top = 193
    Width = 1125
    Height = 193
    Align = alClient
    Color = clSkyBlue
    TabOrder = 1
    object Label5: TLabel
      Left = 0
      Top = 160
      Width = 93
      Height = 13
      Caption = #24403#21069#21097#20313#29260#25968':      '
    end
    object LabelCardsCount: TLabel
      Left = 96
      Top = 160
      Width = 21
      Height = 13
      AutoSize = False
      Caption = '52   '
    end
    object MiddleRight: TPanel
      Left = 216
      Top = 1
      Width = 908
      Height = 191
      Align = alRight
      BorderStyle = bsSingle
      Color = clGreen
      TabOrder = 0
      object PoolImage1: TImage
        Left = 8
        Top = 20
        Width = 100
        Height = 141
        Stretch = True
        OnClick = PoolImage1Click
      end
      object PoolImage2: TImage
        Left = 120
        Top = 20
        Width = 100
        Height = 141
        Stretch = True
        OnClick = PoolImage2Click
      end
      object PoolImage3: TImage
        Left = 232
        Top = 20
        Width = 100
        Height = 141
        Stretch = True
        OnClick = PoolImage3Click
      end
      object PoolImage4: TImage
        Left = 344
        Top = 20
        Width = 100
        Height = 141
        Stretch = True
        OnClick = PoolImage4Click
      end
      object PoolImage5: TImage
        Left = 448
        Top = 20
        Width = 100
        Height = 141
        Stretch = True
      end
      object PoolImage6: TImage
        Left = 560
        Top = 20
        Width = 100
        Height = 141
        Stretch = True
      end
      object PoolImage7: TImage
        Left = 672
        Top = 20
        Width = 100
        Height = 141
        Stretch = True
      end
      object PoolImage8: TImage
        Left = 784
        Top = 20
        Width = 100
        Height = 141
        Stretch = True
      end
    end
    object MiddleLeft: TPanel
      Left = 8
      Top = 24
      Width = 193
      Height = 121
      Caption = #40060'        '#27744
      Color = clAqua
      TabOrder = 1
    end
  end
  object ButtomPanel: TPanel
    Left = 0
    Top = 386
    Width = 1125
    Height = 201
    Align = alBottom
    Color = clSkyBlue
    TabOrder = 2
    object Label4: TLabel
      Left = 616
      Top = 8
      Width = 99
      Height = 13
      Caption = #29609#23478#19978#36718#38035#40060'         '
    end
    object ButtomLeft: TPanel
      Left = -8
      Top = 0
      Width = 217
      Height = 201
      Color = clAqua
      TabOrder = 0
      object Label2: TLabel
        Left = 16
        Top = 64
        Width = 96
        Height = 13
        Caption = #29609#23478#24403#21069#24471#20998':       '
      end
      object MyScoreLabel: TLabel
        Left = 120
        Top = 64
        Width = 9
        Height = 13
        Caption = '0 '
      end
    end
    object ButtomMiddle: TPanel
      Left = 224
      Top = 16
      Width = 361
      Height = 169
      BorderStyle = bsSingle
      Color = clLime
      TabOrder = 1
      object MyImage1: TImage
        Left = 16
        Top = 16
        Width = 105
        Height = 137
        Stretch = True
        OnClick = MyImage1Click
      end
      object MyImage2: TImage
        Left = 128
        Top = 16
        Width = 105
        Height = 137
        Stretch = True
        OnClick = MyImage2Click
      end
      object MyImage3: TImage
        Left = 240
        Top = 16
        Width = 105
        Height = 137
        Stretch = True
        OnClick = MyImage3Click
      end
    end
    object Panel1: TPanel
      Left = 640
      Top = 24
      Width = 465
      Height = 177
      Color = clSkyBlue
      TabOrder = 2
      object MyLast3: TImage
        Left = 240
        Top = 8
        Width = 105
        Height = 159
        Stretch = True
      end
      object MyLast2: TImage
        Left = 128
        Top = 8
        Width = 105
        Height = 159
        Stretch = True
      end
      object MyLast1: TImage
        Left = 16
        Top = 8
        Width = 105
        Height = 159
        Stretch = True
      end
      object MyLast4: TImage
        Left = 352
        Top = 8
        Width = 105
        Height = 159
        Stretch = True
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 8
    object MenuStart: TMenuItem
      Caption = #24320#22987
      OnClick = MenuStartClick
    end
    object MenuRestart: TMenuItem
      Caption = #37325#26032#28216#25103
      Enabled = False
      OnClick = MenuRestartClick
    end
    object MenuExit: TMenuItem
      Caption = #36864#20986
      OnClick = MenuExitClick
    end
    object MenuHelp: TMenuItem
      Caption = #24110#21161
      OnClick = MenuHelpClick
    end
  end
end
