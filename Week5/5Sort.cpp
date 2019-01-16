/*  @name 4BST.cpp
    @desc
    5.  Given an array of integers, sort the array according to frequency of elements. 
    For example, if the input array is {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12}, then modify the array to 
    {3, 3, 3, 3, 2, 2, 2, 12, 12, 4, 5}.  If frequencies of two elements are same, print them in increasing order.
    @author Ankit Apurv 180970042
    @date 06/01/2019
*/
#include<iostream>
using namespace std;

//NOTE : frequency[0].element is the count of unique elements present in the list at any given time
struct frequency {
	int element;
	int count;
};

/*  @desc counts frequency of each element
    @args
       void
    @return void
*/
void countFrequency(int list[], int length, frequency f[])
{
	for(int i=0; i<length; i++)
	{
		bool found = false;
		//is the current element already present in the frequency list?
		for(int j=1; j<length; j++)
		{
			if(list[i] == f[j].element)
			{
				f[j].count++;
				found = true;
			}
		}
		//element not in the frequency list, make new entry
		if(!found)
		{
			f[0].element++;
			f[f[0].element].element = list[i];
			f[f[0].element].count++;
		}
	}
}

/*  @desc sort based on elements frequency
    @args
       void
    @return void
*/
void sort(int sortedlist[], frequency f[])
{
	//sorting frequency list by frequency, highest first
	for(int i=1; i<=f[0].element-1; i++)
	{
		for(int j=2; j<=f[0].element; j++)
		{
			if((f[i].count<f[j].count) && (i<j))
			{
				frequency n;
				n = f[i];
				f[i] = f[j];
				f[j] = n;
			}
		}
	}
	int listCounter = 0;
	for(int i=1; i<=f[0].element; i++)
	{
		for(int j=1; j<=f[i].count; j++)
		{
			sortedlist[listCounter++] = f[i].element;
		}
	}
	return;
}

/*  @desc main
    @args
       void
    @return exitcode : int 0
*/
int main(void)
{
	int size = 10;
	int list[size], sList[size];
	frequency f[size+1];
	cout << "Enter the elements with repetitions : \n";
	for(int i=0; i<size; i++)
		cin >> list[i];
	for(int i=0; i<size+1; i++)
	{
		f[i].element = 0;
		f[i].count = 0;
	}
	countFrequency(list, size, f);
	sort(sList, f);
	cout << "Sorted List : \n";
	for(int i=0; i<size; i++)
		cout << sList[i] << "\n";
	return 0;
}