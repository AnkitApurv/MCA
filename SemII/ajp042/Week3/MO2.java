/*
@desc Input an array of n1 integers and n2 strings. Sort each of the arrays using
bubble sort method.
@author Ankit Apurv
@date 22/01/19
*/

import java.util.Scanner;

class MO2
{
	public static void main(String args[])
	{
		String s2[] = sort(args);
		
		System.out.print("Size of integer array : ");
		Scanner s = new Scanner(System.in);
		int iLen = s.nextInt();
		int i1[] = new int[iLen];
		
		for(int i=0; i<iLen; i++)
			i1[i] = s.nextInt();
		int i2[] = sort(i1);
		
		System.out.println("Sorted integer array : ");
		for(int k : i2)
			System.out.print(k + "\t");
		System.out.println("\nSorted string array : ");
		for(String k : s2)
			System.out.println(k);
		return;
	}
	static int[] sort(int x[])
	{
		int v=0;
		for(int i=0; i<x.length; i++)
		{
			for(int j=0; j<x.length-1; j++)
			{
				if(x[j] > x[j+1])
				{
					v = x[j];
					x[j] = x[j+1];
					x[j+1] = v;
				}
			}
		}
		return x;
	}
	static String[] sort(String x[])
	{
		String v;
		for(int i=0; i<x.length; i++)
		{
			for(int j=0; j<x.length-1; j++)
			{
				if(x[j].compareTo(x[j+1]) > 0)
				{
					v = x[j];
					x[j] = x[j+1];
					x[j+1] = v;
				}
			}
		}
		return x;
	}
}