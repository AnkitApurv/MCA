//Ankit Apurv
//06_08_2018
//Week02
//07Prime - Check if a number is prime

#include <iostream>

using namespace std;

void printInfo(unsigned int number, bool isPrime);

int main(void)
{
        unsigned int number, i;
	bool isPrime = true;

        cout << "Number : ";
        cin >> number;

        switch(number)
        {
		case 0:
                case 1:
			printInfo(number, false);
			break;
		case 2:
			printInfo(number, true);
			break;
                default:
                        for(i = 2; i < number; i++)
                        {
				//checking for every number
                                if(number % i == 0)
				{
					isPrime = false;
					break;
				}

                        }
			printInfo(number, isPrime);
			break;
        }
        return(0);
}

void printInfo(unsigned int number, bool isPrime)
{
	if(isPrime)
		cout << number << " is prime" << endl;
	else
		cout << number << " is not prime" << endl;
}
