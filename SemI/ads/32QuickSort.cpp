/*  @author Ankit Apurv
    @desc QuickSort
    @date 30/10/2018
*/

#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
	return;
}

int partition(int a[], int low, int high)
{

	int pivot = a[high];    //choosing pivot element
    int pIndex = low;	//element's index to compare with pivot
    for(int i=low; i<=high-1; i++)
    {
        if(a[i]<= pivot)
        {
            swap(a[pIndex], a[i]);
            pIndex++;
        }
    }
    //exchange pivot with pIndex at the completion of loop
    swap(a[pIndex], a[high]);
    return pIndex;
}

void quickSort(int a[], int low, int high)
{
	//d n c recursion
	if(low < high)
	{
		int pIndex = partition(a, low, high);
		quickSort(a, low, pIndex-1);
		quickSort(a, pIndex+1, high);
	}
	return;
}

int main(void)
{
	int a[7];
	for(int i = 0; i < 7; i++) cin >> a[i];
	quickSort(a, 0, 6);
	for(int i = 0; i < 7; i++) cout << a[i] << "\t";
	return 0;
}