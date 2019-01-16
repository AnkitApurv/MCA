//Author : Ankit Apurv
//Week 7
//24_09_2018
//Employee result, multi level inheritence

#include <iostream>
using namespace std;

class Employee
{
    protected:
        unsigned int empCode;
        char empName[5];
    public:
        Employee() {};
        Employee(unsigned int c, char n[5])
        {
            empCode = c;
            for(int i=0; i<5; i++)
                empName[i] = n[i];
        };
        ~Employee() {};
};

class Faculty : protected Employee
{
    protected:
        unsigned int yoe;
        char qualification[7];
    public:
        Faculty() {};
        Faculty(unsigned int y, char q[7], unsigned int ec, char en[])
        {
            Employee(ec, en);
            yoe = y;
            for(int i=0; i<7; i++)
                qualification[i] = q[i];
        };
        ~Faculty() {};
};

class Permanent : protected Faculty
{
    protected:
        unsigned int basicPay, totalAllowance;
    public:
        Permanent() {};
        Permanent(unsigned int b, unsigned int t, unsigned int y, char q[7], unsigned int ec, char en[])
        {
            Faculty(y, q, ec, en);
            basicPay = b;
            totalAllowance = t;
        };
        void show()
        {
            cout << "Basic Pay : " << basicPay << "\n";
            cout << "Total Allowance : " << totalAllowance << "\n";
            cout << "Code : " << empCode << "\n";
            cout << "Name : " << empName << "\n";
            cout << "Qualification : " << qualification << "\n";
            cout << "YOE : " << yoe << "\n\n";
        };
        ~Permanent() {};
};

class Contract : protected Faculty
{
    protected:
        unsigned int probationYears;
    public:
        Contract() {};
        Contract(unsigned int py, unsigned int y, char q[7], unsigned int ec, char en[])
        {
            Faculty(y, q, ec, en);
            probationYears = py;
        };
        void show()
        {
            cout << "Probation Years : " << probationYears << "\n";
            cout << "Code : " << empCode << "\n";
            cout << "Name : " << empName << "\n";
            cout << "Qualification : " << qualification << "\n";
            cout << "YOE : " << yoe << "\n\n";
        };

        ~Contract() {};
};

class NonTeaching : protected Employee
{
    protected:
        char grade;
    public:
        NonTeaching() {};
        NonTeaching(char g, unsigned int ec, char en[])
        {
            Employee(ec, en);
            grade = g;
        };
        void show()
        {
            cout << "Grade : " << grade << "\n";
            cout << "Code : " << empCode << "\n";
            cout << "Name : " << empName << "\n\n";
        };
        ~NonTeaching() {};
};



int main(void)
{
    Permanent p(25000, 10000, 4, "dr     ", 10, "qwert");
    Contract c(7, 4, "mr     ", 5, "asdfg");
    NonTeaching n('a', 7, "zxcvb");
    p.show();
    c.show();
    n.show();
    return(0);
}