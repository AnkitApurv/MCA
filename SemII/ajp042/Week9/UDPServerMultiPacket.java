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

	private void writeResponse() throws IOException, FileNotFoundException {
		//1st packet - is file available response true/false
		String isAvailable = "unavailable";
		File f = new File(".\\" + fileName);
		if(f.isFile() & f.canRead())
			isAvailable = "available";

		byte[] isAvailableBytes = isAvailable.getBytes();
		responsePacket = new DatagramPacket(isAvailableBytes, isAvailableBytes.length, clientIp, clientPort);
		System.out.println(" : writeResponse  : " + isAvailable);
		
		server.send(responsePacket);
		if(isAvailable.compareTo("unavailable") == 0)
			return; //isAvailable no, no need to proceed
		
		//2nd packet - if true, file size int(count of bytes), int packetSize, int countOfPackets
		const int sizeOfLong = 8; //64 bits
		const int sizeOfInt = 4; //32 bits
		
		byte[] packet2Payload = new byte[sizeOfLong + sizeOfInt + sizeOfInt];
		ByteBuffer packet2PayloadBuf = new ByteBuffer(packet2Payload);
		
		packet2PayloadBuf.putLong(0, f.length());	//java.nio.*;
		const int packetSize = 1024; //1 kilobyte payload
		packet2PayloadBuf.putInt(8, packetSize);
		int countOfPackets = (int)(f.length() / packetSize);
		packet2PayloadBuf.putInt(12, countOfPackets);
		
		for(long offset=0; offset<f.length(); offset+=packetSize)
		{
			responsePacket = new DatagramPacket(packet2Payload, offset, packet2Payload.length, clientIp, clientPort);
			server.send(responsePacket);
		}
		System.out.println(" : writeResponse  : " + f.length() + "\n");

		//3rd packet - hopefully, 1 unfragmented packet of file : prepare
		FileInputStream readF = new FileInputStream(f);
		byte[] fileBytes = new byte[f.length()];
		readF.read(fileBytes);
		readF.close();
		
		responsePacket = new DatagramPacket(fileBytes, fileBytes.length, clientIp, clientPort);
		System.out.println("client served\n\n");
		return;
	}
}