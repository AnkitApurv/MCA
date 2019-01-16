//Author : Ankit Apurv
//Week 7
//24_09_2018
//Student result, multi level inheritence

#include <iostream>
using namespace std;

class Student
{
    protected:
        unsigned int roll, yoj;
        char name[5], branch[3];
};

class Exam : protected Student
{
    protected:
        unsigned int m1, m2, m3, m4, m5, m6;
};

class Result : protected Exam
{
    protected:
        unsigned int total;
        char grade;

    public:
        void setInfo();
        void setResult();
        void getReport();
};

void Result::setInfo()
{
    cout << "\nName : "; for(int i=0; i<5; i++) cin >> name[i];
    cout << "Branch : "; for(int i=0; i<3; i++) cin >> branch[i];
    cout << "Roll : "; cin >> roll;
    cout << "Year of Joining : "; cin >> yoj;
    cout << "Subject 1 : "; cin >> m1;
    cout << "Subject 2 : "; cin >> m2;
    cout << "Subject 3 : "; cin >> m3;
    cout << "Subject 4 : "; cin >> m4;
    cout << "Subject 5 : "; cin >> m5;
    cout << "Subject 6 : "; cin >> m6;
    cout << "\n\n";
    return;
}

void Result::setResult()
{
    total = m1 + m2 + m3 + m4 + m5 + m6;
    if(total <= 600 && total > 540)
        grade = 'A';
    else if(total <= 540 && total > 480)
        grade = 'B';
    else if(total <= 480 && total > 420)
        grade = 'C';
    else if(total <= 420 && total > 360)
        grade = 'D';
    else if(total <= 360 && total > 300)
        grade = 'E';
    else if(total <= 300)
        grade = 'F';

    return;
}

void Result::getReport()
{
    cout << "\nName : "; for(int i=0; i<5; i++) cout << name[i]; cout << "\n";
    cout << "Branch : "; for(int i=0; i<3; i++) cout << branch[i]; cout << "\n";
    cout << "Roll : " << roll << "\n";
    cout << "Year of Joining : " << yoj << "\n";
    cout << "Subject 1 : " << m1 << "\n";
    cout << "Subject 2 : " << m2 << "\n";
    cout << "Subject 3 : " << m3 << "\n";
    cout << "Subject 4 : " << m4 << "\n";
    cout << "Subject 5 : " << m5 << "\n";
    cout << "Subject 6 : " << m6 << "\n";
    cout << "Total Marks : " << total << "\n";
    cout << "Grade : " << grade << "\n";
    cout << "\n\n";
    return;
}

int main(void)
{
    Result r1;
    r1.setInfo();
    r1.setResult();
    r1.getReport();

    return(0);
}