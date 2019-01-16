//Ankit Apurv
//27_8_18
//04
//04 Complex

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
		friend Complex add(int s1, Complex s2);
		friend Complex add(Complex s1, Complex s2);
		friend void show(Complex s1);
};

Complex add(int s1, Complex s2)
{
    Complex c;
    c.rational = s1 + s2.rational;
    c.irrational = s2.irrational;
    return(c);
}
Complex add(Complex s1, Complex s2)
{
    Complex c;
    c.rational = s1.rational + s2.rational;
    c.irrational = s1.irrational;
    return(c);
}

void show(Complex c1)
{
	cout << "\n" << c1.rational << " + " << c1.irrational << "\n";
	return;
}

int main(void)
{
	Complex c1, c2, c3, c4;
	show(c1);
	show(c2);
	show(c3);
	show(c4);
	c3 = add(15, c1);
	c4 = add(c1, c2);
	show(c3);
	show(c4);
	return(0);
}
