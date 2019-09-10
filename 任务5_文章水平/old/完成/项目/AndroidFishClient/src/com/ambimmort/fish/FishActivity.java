package com.ambimmort.fish;

import java.io.IOException;
import java.io.OutputStream;
import java.net.Socket;
import java.net.UnknownHostException;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnTouchListener;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.Toast;

public class FishActivity extends Activity implements OnClickListener,OnTouchListener
	{
		/** Called when the activity is first created. */
		private Button btnFishIt = null ;
		private Button btnSetting = null ;
		private Spinner spinnerCmd = null ;
		private SendSocket send = null ; 
		private PieChartView pieChartView = null ;
		private String ip ="";
		private int port=0 ;		
		@Override
		public void onCreate(Bundle savedInstanceState)
			{
				super.onCreate(savedInstanceState);
				setContentView(R.layout.fish);
				//ui
				spinnerCmd = (Spinner)findViewById(R.id.spinnerCmd);
				btnFishIt = (Button)findViewById(R.id.buttonFishIt);
				pieChartView = (PieChartView)findViewById(R.id.pieCharView);
				btnSetting = (Button)findViewById(R.id.buttonSetting);
				
				String cmds[] = {"start","end","0","30","60","90","120","150","180"};
				ArrayAdapter arrAdapter = new ArrayAdapter(this, android.R.layout.simple_spinner_item,  cmds);
				arrAdapter.setDropDownViewResource(R.layout.dropdownview);
				spinnerCmd.setAdapter(arrAdapter);
				
				//action
				btnFishIt.setOnClickListener(this);
				pieChartView.setOnTouchListener(this);
				btnSetting.setOnClickListener(this);
				
				//judge before data
				String STORE_NAME="AmbimmortFish";
				SharedPreferences settings = getSharedPreferences(STORE_NAME,this.MODE_PRIVATE);
			    boolean result = settings.getBoolean("set", false);
			    if(result == false)
			    	{
			    		showTips("Server no set ! please setting it");
			    		//get setting
			    		Intent intent = new Intent();
						intent.setClass(this, SettingActivity.class);
						startActivity(intent);						
			    	}
			   
				
				
			}
		@Override
		public void onClick(View v)
			{
				if(v.getId() == R.id.buttonFishIt)
					{
					
						String STORE_NAME="AmbimmortFish";
						SharedPreferences settings = getSharedPreferences(STORE_NAME,this.MODE_PRIVATE);
					    boolean result = settings.getBoolean("set", false);
					    if(result == false)
					    	{
					    		showTips("Server no set ! please setting it");
					    		//get setting
					    		Intent intent = new Intent();
								intent.setClass(this, SettingActivity.class);
								startActivity(intent);
								
					    	}
					    //get data
					    ip = settings.getString("ip", "192.168.255.150");
					    port = settings.getInt("port", 2000);
					    
					    byte sel = (byte) this.spinnerCmd.getSelectedItemPosition();
					  
					    send = new SendSocket(ip,port,sel,(byte)1);
					    						   
					    send.start();
					  
					    return ;
					}

				if(v.getId() == R.id.buttonSetting)
					{
						Intent intent = new Intent();
						intent.setClass(this, SettingActivity.class);
						startActivity(intent);
						return ;
					}
				
			}
		public void showTips(String str)
			{
				Toast.makeText(this, str, Toast.LENGTH_LONG).show();
				
			}
		public class SendSocket extends Thread
		{
			private String ip ;
			private int port ;
			private byte cmd ;
			private byte mode ;
			private Socket socket = null ;
			private OutputStream os = null;
		
			/**
			 * 
			 * @param ip  server ip
			 * @param port server port
			 * @param cmd  10 degree when mode 1   byte degree when mode=2
			 * @param mode 1                            2
			 */
			public SendSocket(String ip, int port, byte cmd,byte mode)
				{
					super();
					this.ip = ip;
					this.port = port;
					this.cmd = cmd;
					this.mode = mode ;
					
				}
			public void run()
				{
					 try
							{
								socket = new Socket(ip,port);
								os = socket.getOutputStream();	
								byte[] bytes= getCMD();
								if(bytes.length>0)
								{
									os.write(bytes, 0, bytes.length);
									os.flush();
								}								
								os.close();
								socket.close();
								
							} catch (UnknownHostException e)
							{
								e.printStackTrace();
							} catch (IOException e)
							{
								e.printStackTrace();
							}
				
				
					
				}		
			
			public byte[] getCMD() 
			{
				byte [] bytes = "/cmd:data:i:;".getBytes(); 
				byte segData = (byte) 21 ;				
				if(mode == (byte)1)
				{	
					switch (cmd) 
					{
					case 0: bytes="/cmd:start:;".getBytes();				
						break;
					case 1:	bytes = "/cmd:end:;".getBytes();				
						break;
					case 2:	
					case 3:
					case 4:
					case 5:
					case 6:	
					case 7:	
					case 8:	bytes=("/cmd:data:"+(cmd-2)*segData+":;").getBytes() ;		
						break;					
					default:    bytes = "/cmd:end:;".getBytes();
						break;
					}
					return bytes ;
				}
				else
				if(mode == (byte)2)
				{
					bytes =("/cmd:data:"+cmd+":;").getBytes() ;			
					
				}
				else
				{
					return null ;  //no match
				}
				return bytes ;
				
			}
			
		}
		
		@Override
		public boolean onTouch(View v, MotionEvent event) {
			float x = event.getX();
			float y = event.getY();
			//start to compute the angle
			int width = pieChartView.getWidth();
			int height = pieChartView.getHeight();
			int centerX = width/2 ;
			int centerY = height/2 ;
			//anxis conver 0 0 -->  下                                --> 上
			double dtX = x-centerX ;
			double dtY = -(y-centerY) ;		
			double angle = Math.atan2(dtY, dtX);
			//arc to degree
			int degree =( (int) ((angle*180/Math.PI)+360) ) %360 ;  //(-pi,pi)   -->(0,pi,2pi)+2pi
			
			if(degree >0 && degree < 180)
			{
				//to 100 portion
				int fill = (int) (degree /3.6) ;
				//set graph
				 pieChartView.setAngle(fill);
				 //send cmd
				
						String STORE_NAME="AmbimmortFish";
						SharedPreferences settings = getSharedPreferences(STORE_NAME,this.MODE_PRIVATE);
					    boolean result = settings.getBoolean("set", false);
					    if(result == false)
					    	{
					    		showTips("Server no set ! please setting it");
					    		//get setting
					    		Intent intent = new Intent();
								intent.setClass(this, SettingActivity.class);
								startActivity(intent);
								
					    	}
					    //get data
					    ip = settings.getString("ip", "192.168.255.150");
					    port = settings.getInt("port", 2000);
					byte to127 = (byte) (degree*(127.0/180));   
					
				  send = new SendSocket(ip,port,to127,(byte)2);				   
				  send.start();
				   
				 
			}
			else
			{
				Toast.makeText(this, "sorry you can only choose 0-180degree", Toast.LENGTH_SHORT).show();
			}
			
			
			
			Toast.makeText(this, degree+"", Toast.LENGTH_LONG).show();
			return false;
		}
	}