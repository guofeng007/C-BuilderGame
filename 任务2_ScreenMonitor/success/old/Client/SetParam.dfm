object Form2: TForm2
  Left = 617
  Top = 277
  Width = 396
  Height = 262
  Caption = #36830#25509#21442#25968#35774#32622
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
    Left = 13
    Top = 32
    Width = 58
    Height = 13
    Caption = #26381#21153#31471'IP'
  end
  object Label2: TLabel
    Left = 14
    Top = 68
    Width = 70
    Height = 13
    Caption = #22270#20687#33394#28145
  end
  object Label3: TLabel
    Left = 13
    Top = 104
    Width = 72
    Height = 13
    Caption = #22270#20687#21697#36136
  end
  object Label4: TLabel
    Left = 230
    Top = 30
    Width = 34
    Height = 13
    Caption = #31471#21475
  end
  object TrackBarDeep: TTrackBar
    Left = 128
    Top = 56
    Width = 150
    Height = 45
    Max = 8
    Min = 1
    Orientation = trHorizontal
    Frequency = 1
    Position = 3
    SelEnd = 0
    SelStart = 0
    TabOrder = 0
    TickMarks = tmBottomRight
    TickStyle = tsAuto
  end
  object TrackBarQuallity: TTrackBar
    Left = 128
    Top = 96
    Width = 150
    Height = 45
    Min = 1
    Orientation = trHorizontal
    Frequency = 1
    Position = 5
    SelEnd = 0
    SelStart = 0
    TabOrder = 1
    TickMarks = tmBottomRight
    TickStyle = tsAuto
  end
  object ComboBoxServer: TComboBox
    Left = 75
    Top = 24
    Width = 145
    Height = 21
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    ItemHeight = 13
    TabOrder = 2
    Text = '192.168.255.150'
    Items.Strings = (
      '192.168.255.150')
  end
  object ButtonOk: TButton
    Left = 56
    Top = 160
    Width = 75
    Height = 25
    Caption = #30830#23450
    TabOrder = 3
    OnClick = ButtonOkClick
  end
  object ButtonCancel: TButton
    Left = 176
    Top = 160
    Width = 75
    Height = 25
    Caption = #21462#28040
    TabOrder = 4
    OnClick = ButtonCancelClick
  end
  object EditPort: TEdit
    Left = 280
    Top = 24
    Width = 73
    Height = 21
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 5
    Text = '900'
  end
end
