/*
 @author Ankit
 @date 01/10/2018
 @week 8
 @desc virtual base class and pure virtual function
 */

#include <iostream>
#include <string>
using namespace std;

class Employee
{
    protected:
        string name, code;
    public:
        Employee() {};
        Employee(string n, string c)
        {
            name = n;
            code = c;
        };
        ~Employee() {};
};

class Account : virtual protected Employee
{
    protected:
        float pay;
    public:
        Account() {};
        Account(float p) { pay = p; };
        ~Account() {};
};

class Admin : virtual protected Employee
{
    protected:
        float experience;
    public:
        Admin() {};
        Admin(float e) { experience = e; };
        ~Admin() {};
};

class Master : protected Account, Admin
{
    public:
        void create();
        void update();
        void show();
        Master()
        {
            create();
        }
        ~Master() {};
};

void Master::create()
{
    cout << "Name : "; cin >> name;
    cout << "Code : "; cin >> code;
    cout << "Experience : "; cin >> experience;
    cout << "Pay : "; cin >> pay;
    cout << "\n";
    return;
}

void Master::update()
{
    create();
}

void Master::show()
{
    cout << "Name : " << name << "\n";
    cout << "Code : " << code << "\n";
    cout << "Experience : " << experience << "\n";
    cout << "Pay : " << pay << "\n\n";
    return;
}

int main(void)
{
    Master r;
    r.show();
    r.update();
    r.show();
    return 0;
}