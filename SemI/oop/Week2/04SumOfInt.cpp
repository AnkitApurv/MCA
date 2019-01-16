
//Ankit Apurv
//06_08_2018
//Week02
//04SumOfInt - Sum of digits of given integer

#include <iostream>

using namespace std;

int main(void)
{
        unsigned int number, sum, digit;

        cout << "Positive number : ";
        cin >> number;
        sum = 0;

        while(number > 0)
        {
                digit = number % 10;
                number /= 10;
                sum += digit;
        }

        cout << "Sum of it's digits : " << sum;

        return(0);
}
