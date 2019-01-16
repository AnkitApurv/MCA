//Ankit Apurv
//06_08_2018
//Week02
//02SwapMinusTemp - Swap without temp variable

#include <iostream>

using namespace std;

int main(void)
{
        int a, b;

        cout << "a : ";
        cin >> a;
        cout << "b : ";
        cin >> b;

        a = a + b;
        b = a - b;
        a = a - b;

        cout << "After Swap" << endl;
        cout << "a : " << a << " and " << "b : " << b << endl;

        return(0);
}