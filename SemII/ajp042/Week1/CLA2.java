/*
@desc Input an integer from the command line. 
Check whether it is odd or even. 
Find and display the sum of its digits.
@author Ankit Apurv
@date 08/01/19
*/

class CLA2
{
	public static void main(String args[])
	{
		int n = Integer.parseInt(args[0]);
		if(n%2 == 0)
			System.out.println(n + " is even");
		else
			System.out.println(n + " is odd");
		int sum=0;
		while(n>0)
		{
			sum += n%10;
			n /= 10;
		}
		System.out.println("Sum of digits : " + sum);
	}
}