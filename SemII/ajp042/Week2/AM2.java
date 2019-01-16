/*
@desc Input an array of n integers. Reverse all elements of the array and store them
in another array. Display the original and reversed integers in two columns.
Note: Write separate functions for reversing an integer.
@author Ankit Apurv
@date 08/01/19
*/

import java.util.Scanner;

class AM2
{
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		System.out.print("Array Size : ");
		int size = s.nextInt();
		
		int a[] = new int[size];
		getArray(a);
		int b[] = new int[a.length];
		
		for(int i=0; i<a.length; i++)
			b[i] = reverseInt(a[i]);
		
		System.out.println("\t" + "Original" + "\t" + "Reversed" + "\n");
		for(int i=0; i<a.length; i++)
			System.out.println("\t" + a[i] + "\t\t" + b[i] + "\n");
		return;
	}
	static void getArray(int a[])
	{
		Scanner s = new Scanner(System.in);
		System.out.println("Array Elements : ");
		for(int i=0; i<a.length; i++)
			a[i] = s.nextInt();
		return;
	}
	static int reverseInt(int k)
	{
		if(k >= 0 && k <= 9)
			return k;
		else
		{
			int w=0, size=0;
			if(k<=9999 && k>=1000)
				size=1000;
			else if(k<=999 && k>=100)
				size=100;
			else if(k<=99 && k>=10)
				size=10;
			while(size !=0)
			{
				w += (k % 10) * size;
				k /= 10;
				size /= 10;
			}
			return w;
		}
	}
}