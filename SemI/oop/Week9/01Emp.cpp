/*
 @author Ankit
 @date 08/10/2018
 @week 9
 @desc abstract base class and pure virtual functions
 */

#include <iostream>
#include <string>
using namespace std;

class Employee
{
    protected:
        string name, code;
        float pay;
    public:
        Employee() {};
        virtual void getEmpInfo() = 0;
        virtual ~Employee() {};
};

class Education
{
    protected:
        string level;

    public:
        Education() {};
        virtual void getEduInfo() = 0;
        virtual ~Education() {};
};

class Labourer : protected Employee
{
    public:
        Labourer() {};
        ~Labourer() {};
        void getEmpInfo()
        {
            cout << "Name : "; cin >> name;
            cout << "Code : "; cin >> code;
            cout << "Pay : "; cin >> pay;
            return;
        };
};

class Scientist : protected Employee, Education
{
    protected:
        string field;
    public:
        Scientist() {};
        ~Scientist() {};
        void getEmpInfo()
        {
            cout << "Name : "; cin >> name;
            cout << "Code : "; cin >> code;
            cout << "Pay : "; cin >> pay;
            cout << "Field : "; cin >> field;
            return;
        }
        void getEduInfo()
        {
            cout << "Level : "; cin >> level;
            return;
        }
};

class Manager : protected Employee, Education
{
    protected:
        float experience;
    public:
        Manager() {};
        ~Manager() {};
        void getEmpInfo()
        {
            cout << "Name : "; cin >> name;
            cout << "Code : "; cin >> code;
            cout << "Pay : "; cin >> pay;
            cout << "Experience : "; cin >> experience;
            return;
        }
        void getEduInfo()
        {
            cout << "Level : "; cin >> level;
            return;
        }
};

int main(void)
{
    Labourer l;
    l.getEmpInfo();
    cout << "\n";
    Scientist s;
    s.getEmpInfo();
    s.getEduInfo();
    cout << "\n";
    Manager m;
    m.getEmpInfo();
    m.getEduInfo();
    return 0;
}