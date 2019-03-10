/*
@desc Networking (TCP) 
Client and server exchange messages between themselves continuously until some terminating condition is satisfied.
server

@name Ankit Apurv
@roll 180970042
@date 26/02/19
*/

import java.io.*;
import java.net.*;
import java.util.Scanner;

class TCPServerUI {
	public static void main(String ... args) throws IOException, InterruptedException {
		//InetAddress self = InetAddress.getLocalHost();
		//Socket client = new Port(self, clientPortNumber);
		final int serverPort = 4850;
		final int backlog = 10;
		InetAddress self = InetAddress.getLoopbackAddress();
		ServerSocket listener = new ServerSocket(serverPort, backlog, self);

		//ThreadGroup clientPool = new ThreadGroup("clientPool");
		while(true) {
			Socket clientPing = listener.accept();
			//int clientCount = clientPool.activeCount();
			//String threadName = "Client " + (clientCount + 1);
			//TCPServer t = new TCPServer(clientPool, threadName, clientPing);
			TCPServer t = new TCPServer(clientPing);
			t.start();
			t.join();
		}
		//listener.close(); //never actually reached, server is always available
		//return;
	}
}

class TCPServer extends Thread {
	Socket mySocket;
	DataInputStream is;
	DataOutputStream os;
	String str;
	boolean notGoodbye;
	
	//Scanner s = new Scanner(System.in);
	//TCPServer(ThreadGroup clientPool, String threadName, Socket clientPing) {
	TCPServer(Socket clientPing) throws IOException {
		//super(clientPool, threadName);
		mySocket = clientPing;
		System.out.println(mySocket.toString() + " logging on");
		//is = new BufferedInputStream(new DataInputStream(mySocket.getInputStream()));
		is = new DataInputStream(new BufferedInputStream(mySocket.getInputStream()));
		os = new DataOutputStream(mySocket.getOutputStream());
		notGoodbye = true;
	}
	
	public void run() {
		try {
			while(notGoodbye) {
				readRequest();
				performTask();
				writeResponse();
			}
			System.out.println(mySocket.toString() + " logging off");
			mySocket.close();
		}
		catch(IOException e) { }
		return;
	}

	private void readRequest() throws IOException {
		str = is.readUTF();
		if(str.compareToIgnoreCase("goodbye") == 0)
			notGoodbye = false;
		System.out.println(" : readRequest : " + str);
		return;
	}

	private void writeResponse() throws IOException {
		os.writeUTF(str);
		System.out.println(" : writeResponse  : " + str + "\n");
		return;
	}

	private void performTask() {
		str = str.toUpperCase();
		return;
	}
}