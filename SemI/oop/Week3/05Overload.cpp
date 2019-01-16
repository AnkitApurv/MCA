//Ankit Apurv
//13_08_2018
//03
//05Overload - use function overloading, swap int, float, char

#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
        return;
}

void swap(float* a, float* b)
{
        float temp;
        temp = *a;
        *a = *b;
        *b = temp;
        return;
}

void swap(char* a, char* b)
{
        char temp;
        temp = *a;
        *a = *b;
        *b = temp;
        return;
}

int main(void)
{
        //integers
        int a, b;
        cout << "Integers\n";
        cout << "a : ";
        cin >> a;
        cout << "b : ";
        cin >> b;
        swap(&a, &b);
        cout << "a : " << a <<" , b : " << b << "\n";

        //floats
        float c, d;
        cout << "Floats\n";
        cout << "c : ";
        cin >> c;
        cout << "d : ";
        cin >> d;
        swap(&c, &d);
        cout << "c : " << c <<" , d : " << d << "\n";

        //chars
        char e, f;
        cout << "Chars\n";
        cout << "e : ";
        cin >> e;
        cout << "f : ";
        cin >> f;
        swap(&e, &f);
        cout << "e : " << e <<" , f : " << f << "\n";

        return(0);
}