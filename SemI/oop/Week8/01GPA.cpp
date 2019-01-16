/*
 @author Ankit
 @date 01/10/2018
 @week 8
 @desc virtual base class and pure virtual function
 */

#include <iostream>
#include <string>
using namespace std;

class Student
{
    protected:
        string name, course;
        unsigned int registration;
    public:
        Student() {};
        ~Student() {};
};

class Exam : virtual protected Student
{
    protected:
        float egpa;
    public:
        Exam() {};
        ~Exam() {};
};

class Sports : virtual protected Student
{
    protected:
        float sgpa;
    public:
        Sports() {};
        ~Sports() {};
};

class Result : protected Exam, Sports
{
    private:
        float rgpa;
    public:
        void calc();
        void show();
        void get();
        Result() {};
        ~Result() {};
};

void Result::calc()
{
    rgpa = (egpa + sgpa) / 2;
    return;
}

void Result::show()
{
    cout << "CGPA : " << rgpa << "\n";
    return;
}

void Result::get()
{
    cout << "Name : "; cin >> name;
    cout << "Registration : "; cin >> registration;
    cout << "Course : "; cin >> course;
    cout << "Exam GPA : "; cin >> egpa;
    cout << "Sports GPA : "; cin >> sgpa;
    return;
}

int main(void)
{
    Result r;
    r.get();
    r.calc();
    r.show();
    return 0;
}