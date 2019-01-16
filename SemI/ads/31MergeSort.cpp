/*  @author Ankit Apurv
    @desc MergeSort
    @date 30/10/2018
*/

#include <iostream>
using namespace std;

void merge(int a[], int low, int mid, int high)
{
	int fS, sS;
	fS = mid - low + 1;
	sS = high - mid;
	int f[fS], s[sS];

	int i, j, k;

	for(i = 0; i < fS; i++)
		f[i] = a[low + i];
	for(i = 0; i < sS; i++)
		s[i] = a[mid + 1 + i];

	i = 0, j = 0, k = low;
	while(i < fS && j < sS)
	{
		if(f[i] < s[j])
		{
			a[k] = f[i];
			i++;
		}
		else //f[i] >= s[j]
		{
			a[k] = s[j];
			j++;
		}
		k++;
	}
	while(i < fS)
	{
		a[k] = f[i];
		k++, i++;
	}
	while(j < sS)
	{
		a[k] = s[j];
		k++, j++;
	}
	return;
}

void mergeSort(int a[], int low, int high)
{
	if(low < high)
	{
		int mid = (low + high) / 2;
		mergeSort(a, low, mid);
		mergeSort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
	return;
}

int main(void)
{
	int a[7];
	for(int i = 0; i < 7; i++) cin >> a[i];
	mergeSort(a, 0, 6);
	for(int i = 0; i < 7; i++) cout << a[i] << "\t";
	return 0;
}