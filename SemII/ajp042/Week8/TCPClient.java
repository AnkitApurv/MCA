/*
@desc Networking (TCP) 
Client and server exchange messages between themselves continuously until some terminating condition is satisfied.
client

@name Ankit Apurv
@roll 180970042
@date 26/02/19
*/

import java.io.*;
import java.net.*;
import java.util.Scanner;

class TCPClientUI {
	public static void main(String ... args) {
		try {
			TCPClient me = new TCPClient();
			me.communicate();
		}
		catch(IOException e) { }
		return;
	}
}

class TCPClient {
	Socket contact;
	Scanner toSend;
	DataInputStream is;
	DataOutputStream os;
	String str;
	boolean notGoodbye;

	final InetAddress self = InetAddress.getLoopbackAddress();
	final int myPort = 4890;
	final int serverPort = 4850;

	TCPClient() throws IOException {
		notGoodbye = true;
		
		
		contact = new Socket(self, serverPort, self, myPort);	//connects automatically
		System.out.println("connected to server");
		toSend = new Scanner(System.in);
		is = new DataInputStream(new BufferedInputStream(contact.getInputStream()));
		os = new DataOutputStream(contact.getOutputStream());
		System.out.println("captured streams");
	}

	public void communicate() throws IOException {
		System.out.println("communicating");
		while(notGoodbye) {
			writeRequest();
			readResponse();
		}
		contact.close();
		toSend.close();
		return;
	}

	private void writeRequest() throws IOException {
		str = toSend.nextLine();
		os.writeUTF(str);
		System.out.println(" : writeRequest : " + str);
		return;
	}

	private void readResponse() throws IOException {
		str = is.readUTF();
		if(str.compareToIgnoreCase("goodbye") == 0)
			notGoodbye = false;
		System.out.println(" : readResponse : " + str + "\n");
		return;
	}
}