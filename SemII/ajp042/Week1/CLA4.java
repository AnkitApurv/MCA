/*
@desc Input 5 integers from the command line. 
Find and display the sum.
@author Ankit Apurv
@date 08/01/19
*/

class CLA4
{
	public static void main(String args[])
	{
		int n=0;
		for(int i=0; i<args.length; i++)
			n += Integer.parseInt(args[i]);
		
		System.out.println("Sum of numbers : " + n);
	}
}