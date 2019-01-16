//Ankit Apurv
//13_08_2018
//03
//to find cube of a number using inline function
#include <iostream>
using namespace std;
inline long cubeIn(int num)
{
        return num*num*num;
}

int main(void)
{
        int num;
        cout << "Number : ";
        cin >> num;
        cout << "Cube : " << cubeIn(num) << "\n";
        return 0;
}
