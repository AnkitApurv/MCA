/*
@desc Input a string. Reverse it. Check whether it is a palindrome or not.
Note: Write a separate function for reversing the string.
@author Ankit Apurv
@date 22/01/19
*/

class SM1
{
	public static void main(String args[])
	{
		String reversed = reverse(args[0]);
		System.out.println(reversed);
		
		System.out.println(isPalindrome(args[0], reversed));
		return;
	}
	static String reverse(String s)
	{
		StringBuffer s2 = new StringBuffer();
		for(int i=s.length()-1; i>=0; i--)
			s2.append(s.charAt(i));
		return s2.toString();
	}
	static boolean isPalindrome(String s1, String s2)
	{
		if(s1.length() != s2.length())
			return false;
		for(int i=0; i<s1.length(); i++)
			if(s1.charAt(i) != s2.charAt(i))
				return false;
		return true;
	}
}