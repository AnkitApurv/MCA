/*
@desc Networking (UDP) 
Client requests for a file by supplying its name to the server. 
Server checks for the existence of that file. If it exists, it sends the file to the client, 
otherwise sends an error message.
server

@name Ankit Apurv
@roll 180970042
@date 09/03/19
*/

import java.io.*;
import java.nio.ByteBuffer;
import java.net.*;
import java.util.Scanner;

class UDPServerUI {
	public static void main(String ... args) throws IOException, InterruptedException {
		final int serverPort = 4850;
		InetAddress self = InetAddress.getLoopbackAddress();
		DatagramSocket server = new DatagramSocket(serverPort, self);
		byte[] fileName = new byte[256];
		DatagramPacket clientPing = new DatagramPacket(fileName, fileName.length);
		while(true) {
			server.receive(clientPing);
			UDPServer t = new UDPServer(server, clientPing);
			t.start();
			t.join();
		}
		//server.close(); //never actually reached, server is always available
		//return;
	}
}

class UDPServer extends Thread {
	DatagramSocket server;

	DatagramPacket fileNamePacket;
	String fileName;

	DatagramPacket responsePacket;

	InetAddress clientIp;
	int clientPort;

	UDPServer(DatagramSocket s, DatagramPacket clientPing) throws IOException {
		server = s;
		fileNamePacket = clientPing;
		clientIp = fileNamePacket.getAddress();
		clientPort = fileNamePacket.getPort();
		System.out.println(" : Request instantiated : ");
	}
	
	public void run() {
		try {
			readRequest();
			performTask();
			writeResponse();
		}
		catch(IOException e) { }
		return;
	}

	private void readRequest() throws IOException {
		fileName = new String(fileNamePacket.getData());
		fileName = fileName.trim();
		System.out.println(" : readRequest : " + fileName);
		return;
	}

	private void writeResponse() throws IOException {
		//3rd packet - hopefully, 1 unfragmented packet of file : send
		//if unavaliable it's 2nd packet saying unavailable
		server.send(responsePacket);
		System.out.println("client served\n\n");
		return;
	}

	private void performTask() throws IOException, FileNotFoundException {
		//1st packet - is file available response true/false
		String isAvailable = "unavailable";
		File f = new File(".\\" + fileName);
		if(f.isFile() & f.canRead())
			isAvailable = "available";

		byte[] isAvailableBytes = isAvailable.getBytes();
		responsePacket = new DatagramPacket(isAvailableBytes, isAvailableBytes.length, clientIp, clientPort);
		System.out.println(" : writeResponse  : " + isAvailable);
		if(isAvailable.compareTo("unavailable") == 0)
			return; //isAvailable no, final response
		else
			server.send(responsePacket); //isAvailable yes, respnd yes, proceed to send file

		//2nd packet - if true, file size int(count of bytes)
		byte[] fileSizeBytes = ByteBuffer.allocate(4).putInt((int)f.length()).array();	//java.nio.*;
		responsePacket = new DatagramPacket(fileSizeBytes, fileSizeBytes.length, clientIp, clientPort);
		server.send(responsePacket);
		System.out.println(" : writeResponse  : " + f.length() + "\n");

		//3rd packet - hopefully, 1 unfragmented packet of file : prepare
		FileInputStream readF = new FileInputStream(f);
		byte[] fileBytes = new byte[(int)f.length()];
		readF.read(fileBytes);
		readF.close();
		responsePacket = new DatagramPacket(fileBytes, fileBytes.length, clientIp, clientPort);

		return;
	}
}