/*
@desc Networking (UDP) 
Client requests for a file by supplying its name to the server. 
Server checks for the existence of that file. If it exists, it sends the file to the client, 
otherwise sends an error message.
client

@name Ankit Apurv
@roll 180970042
@date 09/03/19
*/

import java.io.*;
import java.nio.ByteBuffer;
import java.net.*;
import java.util.Scanner;

class UDPClientUI {
	public static void main(String ... args) {
		try {
			UDPClient me = new UDPClient();
			me.communicate();
		}
		catch(IOException e) { }
		return;
	}
}

class UDPClient {
	DatagramSocket contact;

	final InetAddress self = InetAddress.getLoopbackAddress();
	final int myPort = 4890;
	final int serverPort = 4850;

	String fileName;

	UDPClient() throws IOException {
		contact = new DatagramSocket(myPort, self);
		System.out.println("got port");
	}

	public void communicate() throws IOException {
		//contact.connect(self, serverPort);
		System.out.println("connected to server, communicating");
		writeRequest();
		readResponse();
		//contact.disconnect();
		System.out.println("done, disconnected");
		contact.close();

		return;
	}

	private void writeRequest() throws IOException {
		System.out.print("File name : ");
		Scanner toSend = new Scanner(System.in);
		fileName = toSend.nextLine();
		toSend.close();
		byte[] fileNameBytes = fileName.getBytes();
		DatagramPacket fileNamePacket = new DatagramPacket(fileNameBytes, fileNameBytes.length, self, serverPort);
		contact.send(fileNamePacket);
		System.out.println(" : writeRequest : " + fileName);
		return;
	}

	private void readResponse() throws IOException {
		//1st packet - is file available response true/false
		String isAvaliable = "unavailable"; //maximum possible size/value
		byte[] isAvaliableBytes = new byte[isAvaliable.getBytes().length]; //create max required size byte array
		DatagramPacket isAvaliablePacket = new DatagramPacket(isAvaliableBytes, isAvaliableBytes.length);
		contact.receive(isAvaliablePacket);
		isAvaliable = new String(isAvaliableBytes); //reviceve response
		isAvaliable = isAvaliable.trim();
		System.out.println(" : readResponse : " + isAvaliable + "\n");

		if(isAvaliable.compareTo("available") == 0)
			getFile();
		return;
	}
	private void getFile() throws IOException, FileNotFoundException {
		//2nd packet - if true, file size int(count of bytes), int packetSize, int countOfPackets
		long fileSize;
		int packetSize, countOfPackets;
		//https://stackoverflow.com/a/2183279
		byte[] packet2Payload = new byte[sizeOfLong + sizeOfInt + sizeOfInt];
		
		DatagramPacket fileSizePacket = new DatagramPacket(fileSizeBytes, fileSizeBytes.length);
		contact.receive(fileSizePacket);
		
		ByteBuffer packet2PayloadBuf = new ByteBuffer(packet2Payload);
		fileSize = packet2PayloadBuf.getLong(0);
		packetSize = packet2PayloadBuf.getInt(8);
		countOfPackets = packet2PayloadBuf.getInt(12);
		
		System.out.println(" : readResponse : \n" 
		+ "fileSize : " + fileSize + "\n"
		+ "packetSize : " + packetSize + "\n"
		+ "countOfPackets : " + countOfPackets + "\n");

		//3rd packet - hopefully, 1 unfragmented packet of file
		byte[] file = new byte[fileSize];
		
		for(long offset=0; offset<f.length(); offset+=packetSize)
		{
			DatagramPacket filePacket = new DatagramPacket(file, offset, packetSize);
			contact.receive(filePacket);
		}
		System.out.println(" : readResponse : got file\n");

		//comms complete writing file to disk
		File received = new File("./" + fileName);
		received.setReadable(true);
		received.setWritable(true);
		received.createNewFile();
		FileOutputStream writeFile = new FileOutputStream(received);
		writeFile.write(file);
		writeFile.close();
		System.out.println(" : readResponse : file saved\n\n");

		return;
	}
}