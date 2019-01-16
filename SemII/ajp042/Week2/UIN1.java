/*
@desc User inputs (Numeric data) Input two integers, n and r.  
• Evaluate nCr = n! / (r! * (n-r)!).  
• Find the GCD and LCM of these two integers. 
Note: Write separate functions for calculating factorial and GCD. 
@author Ankit Apurv
@date 08/01/19
*/
import java.util.Scanner;

class UIN1
{
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		
		System.out.print("a (larger) : ");
		int a = s.nextInt();
		System.out.print("b (smaller) : ");
		int b = s.nextInt();
		
		System.out.println("GCD : " + gcd(a,b)
						  +"\nLCM : " + lcm(a,b)
						  +"\nnCr : " + nCr(a,b));
	}
	
	static int gcd(int a, int b)
	{
		int c=0;
		do
		{	c=a%b;
			a=b;
			b=c;
		} while(c>0);
		return a;
	}
	
	static int lcm(int a, int b)
	{
		return (a*b)/gcd(a,b);
	}
	
	static int factorial(int a)
	{
		int n=1;
		while(a>0)
			n *= a--;
		return n;
	}
	
	static int nCr(int n, int r)
	{
		return ( factorial(n) / (factorial(r) * factorial(n-r)) );
	}
}