object Form2: TForm2
  Left = 192
  Top = 130
  Width = 421
  Height = 202
  Caption = #35831#36755#20837#25991#23383
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 88
    Top = 16
    Width = 60
    Height = 13
    Caption = #35831#36755#20837#25991#23383
  end
  object EditFont: TEdit
    Left = 88
    Top = 40
    Width = 233
    Height = 21
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 0
  end
  object BtnSelectFont: TButton
    Left = 240
    Top = 80
    Width = 75
    Height = 25
    Caption = #35831#36873#25321#23383#20307
    TabOrder = 1
    OnClick = BtnSelectFontClick
  end
  object Button1: TButton
    Left = 184
    Top = 120
    Width = 75
    Height = 25
    Caption = #30830#23450
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 288
    Top = 120
    Width = 75
    Height = 25
    Caption = #21462#28040
    TabOrder = 3
    OnClick = Button2Click
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Left = 136
    Top = 72
  end
end
