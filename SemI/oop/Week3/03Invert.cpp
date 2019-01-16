//Ankit Apurv
//13_08_2018
//03
//03Inverse - to invert an integer and multiply it by two as well

#include <iostream>
using namespace std;

int invert(int n)
{
        int digit, inv = 0;
        while(n > 0)
        {
                digit = n % 10;
                inv *= 10;
                inv += digit;
                n /= 10;
        }
        return(inv);
}

int main(void)
{
        int n, inv;
        cout << "Number : ";
        cin >> n;
        inv = invert(n);
        cout << "Inverted : " << inv <<"\n";
        cout << "Double of inverted : " << inv * 2 <<"\n";
        return(0);
}
