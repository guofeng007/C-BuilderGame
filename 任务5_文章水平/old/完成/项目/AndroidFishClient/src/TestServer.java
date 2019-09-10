import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.net.UnknownHostException;


public class TestServer
	{

		/**
		 * @param args
		 * @throws IOException 
		 * @throws UnknownHostException 
		 */
		public static void main(String[] args) throws UnknownHostException, IOException
			{
				
						Socket	socket = new Socket("192.168.255.160",6000);
						
						
						OutputStream	os = socket.getOutputStream();
						InputStream is = socket.getInputStream();
						os.write("hello".getBytes());
						os.flush();
						int result = is.read();	
						
						socket.close();

			}

	}
