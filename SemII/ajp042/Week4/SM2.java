/*
@desc Input a string. Rearrange the characters in it in alphabetic order (E.g.,
COMPUTER should be written in the form of CEMOPRTU).
Rearranging should be done for the two cases:
• Considering the upper/lower case of alphabets
• Without considering the upper/lower case of alphabets
Note: Write separate functions for the two cases.
@author Ankit Apurv
@date 22/01/19
*/

class SM2
{
	public static void main(String args[])
	{
		System.out.println(sortCaseSensetive(args[0]));
		System.out.println(sortCaseInsensetive(args[0]));
		return;
	}
	static String sortCaseSensetive(String s)
	{
		StringBuffer s2 = new StringBuffer(s);
		char v;
		for(int i=0; i<s2.length(); i++)
		{
			for(int j=0; j<s2.length()-1; j++)
			{
				if(s2.charAt(j) > s2.charAt(j+1))
				{
					v = s2.charAt(j);
					s2.setCharAt(j, s2.charAt(j+1));
					s2.setCharAt(j+1, v);
				}
			}
		}
		//write to string buffer, chars are represented in utf-8, first chars are same as ascii, direct compare
		return s2.toString();
	}
	static String sortCaseInsensetive(String s)
	{
		StringBuffer s2 = new StringBuffer(s);	//to return
		StringBuffer s3 = new StringBuffer(s.toLowerCase());	//to comapre and swap
		char v;
		for(int i=0; i<s2.length(); i++)
		{
			for(int j=0; j<s2.length()-1; j++)
			{
				if(s3.charAt(j) > s3.charAt(j+1))
				{
					//to return
					v = s2.charAt(j);
					s2.setCharAt(j, s2.charAt(j+1));
					s2.setCharAt(j+1, v);
					//to compare and swap
					v = s3.charAt(j);
					s3.setCharAt(j, s3.charAt(j+1));
					s3.setCharAt(j+1, v);
				}
			}
		}
		//write to string buffer, chars are represented in utf-8, first chars are same as ascii, direct compare
		//first convert tolowerCase() / toUpperCase(), then compare but swap original chars
		return s2.toString();
	}
}