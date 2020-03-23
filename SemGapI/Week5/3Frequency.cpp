/*  @name 3Frequency.cpp
	@desc to find the most frequent word in an array of strings.
	@author Ankit Apurv 180970042
	@date 04/01/2019
*/

#include <iostream>
#include <string>
using namespace std;

/*  @desc findFrequency
	@args
		k : array of strings
	@return string, most frequent word
*/
string findFrequency(string k[], int size)
{
	int n[10]= {0};
	//all words occur atleast once
	for(int i=0; i<=size; i++)
	{
		n[i]=1;
	}
	//finding each word's frequency
	for(int i=0; i<size; i++)
	{
		//double loop so that each string gets compared to all other strings
		for(int j=1; j<=size; j++)
		{
			if(k[i].compare(k[j]) == 0)
			{
				n[i]++;
				n[j]++;
			}
		}
	}

	//finding highest frequency
	int highestFrequency = 0;
	for(int i=0; i<size; i++)
	{
		for(int j=1; j<=size; j++)
		{
			if(n[i] > n[j])
				highestFrequency = i;
			else
				highestFrequency = j;
		}
	}
	return k[highestFrequency];
}

/*  @desc main
	@args
		void
	@return exit code
*/
int main(void)
{
	int size = 4;
	string k[size];
	cout << "Array of 4 strings. Assuming each string is one word." << "\n";
	for(int i = 1; i<= size; i++)
	{
		cout << "String " << i << " : ";
		cin >> k[i-1];
	}
	cout << "Most frequent word : " << findFrequency(k, size) << "\n";
	return 0;
}