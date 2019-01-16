/*
@desc Input an array of n integers. Calculate and display the following:  
• Minimum and maximum elements in it. 
• Sum of its elements (use enhanced-for loop). 
Note: Write separate function for inputting the elements of the array. 
@author Ankit Apurv
@date 08/01/19
*/

import java.util.Scanner;

class AM1
{
	public static void main(String args[])
	{
		int a[] = getArray();
		int min, max, sum=0;
		min = max= a[0];
		for(int current : a)
		{
			sum += current;
			min = Math.min(current, min);
			max = Math.max(current, max);
		}
		System.out.println("Min : "+ min
						  +"\nMax : "+ max
						  +"\nSum : "+ sum);
		return;
	}
	static int[] getArray()
	{
		Scanner s = new Scanner(System.in);
		System.out.print("Array Size : ");
		int size = s.nextInt();
		int a[] = new int[size];
		System.out.println("Array Elements : ");
		for(int i=0; i<size; i++)
			a[i] = s.nextInt();
		return a;
	}
	/*
	static int getMin(int a[])
	{
		int min=0;
		for(int i=0; i<a.length-1; i++)
		{
			for(int j=1; i<a.length; j++)
			{
				if(a[i] < a[j])
					min = a[j];
			}
		}
		return min;
	}
	
	static int getMax(int a[])
	{
		int max=0;
		for(int i=0; i<a.length-1; i++)
		{
			for(int j=1; i<a.length; j++)
			{
				if(a[i] > a[j])
					max = a[j];
			}
		}
		return max;
	}
	
	static int getSum(int a[])
	{
		int sum=0;
		for(int current : a)
		{
			sum += current;
		}
		return sum;
	}
	*/
}