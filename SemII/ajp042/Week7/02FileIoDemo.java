/*
@desc File Input and Output 
Create a file containing a set of strings. Read the file, sort the strings and store them in another file 

@name Ankit Apurv
@roll 180970042
@date 12/02/19
*/

import java.io.*;

class FileIoDemo {
	/*
	args[0] unsorteStrings
	args[1] sortedStrings
	*/
	public static void main(String ... args) throws IOException {
		String k[] = new String[args.length-2];
		int i=0, j;
		for(j=2; j<args.length; j++)
			k[i++] = args[j];
		
		//writing to unsorted file args[0]
		char toWrite[] = stringArrayTocharArray(k);
		writeFile(toWrite, args[0]);
		
		//reading and sorting
		char readData[] = readFile(args[0]);
		String toSort[] = charArrayToStringArray(readData);
		String sorted[] = sort(toSort);
		
		//writing to sorted file args[1]
		toWrite = stringArrayTocharArray(sorted);
		writeFile(toWrite, args[1]);
		
		return;
	}
	
	private static void writeFile(char data[], String fileName) throws IOException {
		File newFile = new File(".", fileName);
		
		try {
			newFile.createNewFile();
			newFile.setReadable(true);
			newFile.setWritable(true);
		}
		catch(IOException e) {
			System.out.println(e.toString());
			System.exit(0);
		}
		catch(SecurityException e) {
			System.out.println(e.toString());
			System.exit(0);
		}
		
		FileWriter f = new FileWriter(newFile);
		f.write(data);
		f.close();
		
		return;
	}
	
	private static char[] readFile(String fileName) throws IOException {
		File newFile = new File(".", fileName);
		if(! (newFile.exists() & newFile.isFile() & newFile.canRead()) )
		{
			System.out.println("Can't read file!");
			System.exit(0);
		}
		char data[] = new char[(int)newFile.length()];
		
		FileReader f = new FileReader(newFile);
		f.read(data);
		f.close();
		
		return data;
	}
	
	private static char[] stringArrayTocharArray(String k[]) {
		int i = 0, l = 0;
		for(String w : k)
			l += w.length();
		l += k.length;
		char data[] = new char[l];
		
		for(String w : k)
		{
			for(int j=0; j<w.length(); j++)
				data[i++] = w.charAt(j); //char to char
			data[i++] = ' '; //separator
		}
		return data;
	}
	
	private static String[] charArrayToStringArray(char data[]) {
		String s = new String(data);
		return s.split(" ");
	}
	
	private static String[] sort(String k[]) {
		String swap;
		for(int i=1; i<=k.length; i++) {
			for(int j=0; j<k.length-1; j++) {
				if(k[j].compareTo(k[j+1]) > 0) {
					swap = k[j];
					k[j] = k[j+1];
					k[j+1] = swap;
				}
			}
		}
		return k;
	}
}