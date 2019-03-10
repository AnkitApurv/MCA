/*
@desc Input two strings (S1 and S2) and two integers (N1 and N2). Perform the
following string operations.
• Display the upper-case equivalent of S1.
• Display the lower-case equivalent of S2.
• Extract a substring of length N2 from S1 starting at position N1.
• Insert S2 into S1 at position N1.
• Append S2 to S1.
Note: Write separate functions for the last two cases.
@author Ankit Apurv
@date 22/01/19
*/
import java.util.Scanner;
class SM3
{
	public static void main(String args[])
	{
		System.out.println(args[0].toUpperCase());
		System.out.println(args[1].toLowerCase());
		
		int n1, n2;
		Scanner s = new Scanner(System.in);
		System.out.print("N1 : "); n1 = s.nextInt();
		System.out.print("N2 : "); n2 = s.nextInt();
		if( (n1<0 || n2<0) | (n1>n2) | (n1>args[0].length() || n2>args[0].length()) | n1+n2>args[0].length())
		{
			System.out.println("Invalid numbers");
			return;
		}
		
		System.out.println(subStr(args[0], n1, n2));
		System.out.println(inStr(args[0], args[1], n1));
		System.out.println(apStr(args[0], args[1]));
		return;
	}
	static String subStr(String s, int n1, int n2)
	{
		return s.substring(n1, n1+n2);
	}
	static String inStr(String s1, String s2, int n1)
	{
		StringBuffer s = new StringBuffer();
		s.append(s1.toCharArray(), 0, s1.length()-1);
		s.insert(n1, s2.toCharArray(), 0, s2.length()-1);
		return s.toString();
	}
	static String apStr(String s1, String s2)
	{
		StringBuffer s = new StringBuffer();
		s.append(s1.toCharArray(), 0, s1.length()-1);
		s.append(s2.toCharArray(), 0, s2.length()-1);
		return s.toString();
	}
}