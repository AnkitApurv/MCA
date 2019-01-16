//Author_Name : Ankit Apurv
//Date 17_9_18
//Week 06
//Operator overloading member : 02 Complex

#include <iostream>
using namespace std;

class Complex
{
    private:
        int rational;
        char irrational;

    public:
        Complex()
        {
            rational = 0;
            irrational = 'i';
        }
        Complex(int r)
        {
            rational = r;
            irrational = 'i';
        }
        Complex operator +(Complex c2)
        {
            Complex r;
            r.rational = rational + c2.rational;
            r.irrational = 'i';
            return(r);
        }
        Complex operator -(Complex c2)
        {
            Complex r;
            r.rational = rational - c2.rational;
            r.irrational = 'i';
            return(r);
        }
        void show()
        {
            cout << "\n" << rational << " + " << irrational << "\n";
            return;
        }
};

int main(void)
{
    Complex c1(8), c2(5), c3, c4;
    c1.show();
    c2.show();
    c3 = c1 + c2;
    c4 = c1 - c2;
    c3.show();
    c4.show();
    return(0);
}