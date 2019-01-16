//Ankit Apurv
//06_08_2018
//Week02
//03SmallestNum - Smallest among 3 numbers

#include <iostream>

using namespace std;

int main(void)
{
        int a, b, c;

        cout << "a : ";
        cin >> a;
        cout << "b : ";
        cin >> b;
        cout << "c : ";
        cin >> c;

        if( a < b && a < c)
                cout << "a is smallest!";
        else if( b < a && b < c)
                cout << "b is smallest!";
        else
                cout << "c is smallest!";

        return(0);
}
