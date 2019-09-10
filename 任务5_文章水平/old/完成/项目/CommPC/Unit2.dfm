object Form2: TForm2
  Left = 409
  Top = 260
  BorderStyle = bsNone
  Caption = #35774#32622#36828#31243#21442#25968
  ClientHeight = 139
  ClientWidth = 288
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
    Left = 16
    Top = 24
    Width = 34
    Height = 13
    Caption = #36828#31243'IP'
  end
  object Label2: TLabel
    Left = 16
    Top = 48
    Width = 48
    Height = 13
    Caption = #36828#31243#31471#21475
  end
  object Edit1: TEdit
    Left = 80
    Top = 24
    Width = 121
    Height = 21
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 0
    Text = '127.0.0.1'
  end
  object Edit2: TEdit
    Left = 80
    Top = 48
    Width = 121
    Height = 21
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 1
    Text = '1000'
  end
  object Button1: TButton
    Left = 48
    Top = 88
    Width = 75
    Height = 25
    Caption = #30830#23450
    ModalResult = 1
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 136
    Top = 88
    Width = 75
    Height = 25
    Caption = #21462#28040
    ModalResult = 2
    TabOrder = 3
    OnClick = Button2Click
  end
end
