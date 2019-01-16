/*
@desc 
Input a floating-point number from the command line. 
For this number, display the following: 
• Absolute value 
• Square root 
• Cube root 
• Square 
• Next integer 
• Previous integer 
• Nearest integer
@author Ankit Apurv
@date 08/01/19
*/

class CLA3
{
	public static void main(String args[])
	{
		float n = Float.parseFloat(args[0]);
		System.out.println("Absolute Value : " + Math.abs(n));
		System.out.println("Square Root : " + Math.sqrt(n));
		System.out.println("Cube Root : " + Math.cbrt(n));
		System.out.println("Square : " + Math.pow(n, 2));
		System.out.println("Next Integer : " + (int)Math.ceil(n));
		System.out.println("Previous Integer : " + (int)Math.floor(n));
		System.out.println("Nearest Integer : " + Math.round(n));
	}
}