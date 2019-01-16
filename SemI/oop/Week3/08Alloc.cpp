#include <iostream>
using namespace std;
int main()
{
	int *p = new int[3], k;
	for(k=0; k<3; k++)
	{
		cout << "Enter a number : ";
		cin >> *p;
		p++;
	}
	p -= 3;
	cout << "\n Entered numbers with their address are: \n";
	for (k=0; k<3; k++)
	{
		cout << "\t" << *p << "\t" << p << "\n";
		p++;
	}
	p -= 3;
	delete p;
}
