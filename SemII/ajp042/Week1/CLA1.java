/*
@desc Input a string from the command line. 
Find its length. 
Count the number of alphabets, digits and other characters in it.
@author Ankit Apurv
@date 08/01/19
*/

class CLA1
{
	public static void main(String args[])
	{
		int noAlphabets=0, noDigits=0, noOthers=0;
		
		for(int j=0; j<args[0].length(); j++)
		{
			if(Character.isLetter(args[0].charAt(j)))
				noAlphabets += 1;
			else	
			if(Character.isDigit(args[0].charAt(j)))
				noDigits += 1;
		}
		
		noOthers = args[0].length() - (noAlphabets + noDigits);
		
		System.out.println("Total Length : " + args[0].length());
		System.out.println("No. of Alphabets : " + noAlphabets);
		System.out.println("No. of Digits : " + noDigits);
		System.out.println("No. of Others : " + noOthers);
		
	}
}