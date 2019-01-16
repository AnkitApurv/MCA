//Author's Name : Ankit Apurv
//Date : 17/09/2018
//Week 06
//01MyStr : overload relational operators

#include <iostream>
using namespace std;

class my_String
{
    private:
        char value[100];

    public:
        my_String()
        {
            for(int i = 0; i < 100; i++)
                value[i] = '\0';
        }
        void set(void)
        {
            cout << "\n";
            for(int i = 0; i < 100; i++)
                cin >> value[i];
            cout << "\n";
            return;
        }
        void get(void)
        {
            cout << "\n";
            for(int i = 0; i < 100; i++)
                cout << value[i];
            cout << "\n";
            return;
        }
        friend bool operator <= (my_String a, my_String b);
        friend bool operator >= (my_String a, my_String b);
};

bool operator <= (my_String a, my_String b)
{
    unsigned int i, j;

    for(i = 1; i <= 10; i++)
        if(a.value[i] == '\0')
            break;

    for(j = 1; j <= 10; j++)
        if(b.value[j] == '\0')
            break;

    return(i <= j);
}

bool operator >= (my_String a, my_String b)
{
    unsigned int i, j;

    for(i = 1; i <= 10; i++)
        if(a.value[i] == '\0')
            break;

    for(j = 1; j <= 10; j++)
        if(b.value[j] == '\0')
            break;

    return(i >= j);
}

int main(void)
{
    my_String a, b;
    a.set();
    b.set();
    a.get();
    b.get();
    cout << (a <= b);
    cout << (a >= b);
    return(0);
}