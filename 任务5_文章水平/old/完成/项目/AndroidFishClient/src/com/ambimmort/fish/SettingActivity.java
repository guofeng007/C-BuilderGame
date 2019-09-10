/*
 ******************************************************************************
 * Parts of this code sample are licensed under Apache License, Version 2.0   *
 * Copyright (c) 2009, Android Open Handset Alliance. All rights reserved.    *
 *                                                                            *                                                                         *
 * Except as noted, this code sample is offered under a modified BSD license. *
 * Copyright (C) 2010, Motorola Mobility, Inc. All rights reserved.           *
 *                                                                            *
 * For more details, see MOTODEV_Studio_for_Android_LicenseNotices.pdf        * 
 * in your installation folder.                                               *
 ******************************************************************************
 */

package com.ambimmort.fish;

import android.app.Activity;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;

public class SettingActivity extends Activity implements OnClickListener
	{

		private int dialogId = 1;
		private Button btnYes = null ;
		private EditText textIp = null ;
		private EditText textPort =null ;

		/** Called when the activity is first created. */
		@Override
		public void onCreate(Bundle savedInstanceState)
			{
				super.onCreate(savedInstanceState);
				setContentView(R.layout.setting);

				btnYes = (Button) findViewById(R.id.btnSettingYes);
				btnYes.setOnClickListener(this);
				
				textIp = (EditText) findViewById(R.id.editTextServerIp);
				textPort = (EditText) findViewById(R.id.editTextServerPort);

			}

		public void onClick(View arg0)
			{
				//get ui data
				String ip = this.textIp.getText().toString().trim();
				int port = 0 ;
				try
					{
						port = Integer.parseInt(this.textPort.getText().toString().trim());
					}
				catch(Exception e)
					{
						e.printStackTrace() ;
						return ;
					}
				//store file
				//set true false init
				//ip   192.168.255.150 
				//port 60000
				String STORE_NAME="AmbimmortFish";
				SharedPreferences settings = getSharedPreferences(STORE_NAME,this.MODE_PRIVATE);
				SharedPreferences.Editor editor = settings.edit();
				editor.putBoolean("set", true);
				editor.putString("ip", ip);
				editor.putInt("port", port);
				editor.commit();
				//return before
				finish();
				
			}
	}