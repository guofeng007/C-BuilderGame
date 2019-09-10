object Form1: TForm1
  Left = 192
  Top = 130
  Width = 385
  Height = 247
  Caption = 'Form1'
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
    Left = 184
    Top = 23
    Width = 169
    Height = 13
    AutoSize = False
    Caption = #30828#20214#23458#25143#31471#26381#21153#31471#21475
  end
  object Label2: TLabel
    Left = 13
    Top = 23
    Width = 148
    Height = 13
    AutoSize = False
    Caption = #36828#31243#23458#25143#31471#26381#21153#31471#21475
  end
  object Edit1: TEdit
    Left = 187
    Top = 48
    Width = 120
    Height = 21
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 0
    Text = '1000'
  end
  object Edit2: TEdit
    Left = 49
    Top = 48
    Width = 120
    Height = 21
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 1
    Text = '2000'
  end
  object Button1: TButton
    Left = 188
    Top = 80
    Width = 138
    Height = 25
    Caption = #24320#21551#30828#20214#31471#21475#26381#21153
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 40
    Top = 80
    Width = 137
    Height = 25
    Caption = #24320#21551#36828#31243#31471#21475#26381#21153
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 190
    Top = 152
    Width = 134
    Height = 25
    Caption = #20851#38381#30828#20214#31471#21475#26381#21153
    TabOrder = 4
    Visible = False
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 48
    Top = 151
    Width = 130
    Height = 25
    Caption = #20851#38381#36828#31243#31471#21475#26381#21153
    TabOrder = 5
    Visible = False
    OnClick = Button4Click
  end
  object ServerSocket1: TServerSocket
    Active = False
    Port = 1000
    ServerType = stNonBlocking
    OnClientError = ServerSocket1ClientError
    Left = 216
    Top = 112
  end
  object ServerSocket2: TServerSocket
    Active = False
    Port = 2000
    ServerType = stNonBlocking
    OnClientRead = ServerSocket2ClientRead
    OnClientError = ServerSocket2ClientError
    Left = 72
    Top = 112
  end
end
