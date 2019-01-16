//08 Report
#include <iostream>
#include <string>

using namespace std;

const char tab = '\t';
const char newline = '\n';

struct StudentInfo {
	string name;
	unsigned int roll;
	unsigned short int yoj;
	unsigned short int sem;
	unsigned short int marks[5];
	unsigned short int total;
	unsigned short int avg;
	unsigned char grade;
};

StudentInfo getInfo(void)
{
	unsigned short int i;
	StudentInfo s;
	cout << "Name : ";
	cin >> s.name;
	cout << "Roll : ";
	cin >> s.roll;
	cout << "Year of Joining : ";
	cin >> s.yoj;
	cout << "Semester : ";
	cin >> s.sem;
	cout << "Marks(5 subjects) : ";
	for(i = 0; i < 5 ;i++)
	{
		s.marks[i] = 0;
		do
		{
			if(s.marks[i]>100)
				cout << "Invalid Marks! Re-enter : ";
			cin >> s.marks[i];
		}
		while(s.marks[i]>100);
	}
	s.total = s.avg = 0;
	for(i = 0; i < 5 ;i++)
		s.total += s.marks[i];
	s.avg = s.total/5;

	if(s.avg>=40 && s.avg<50)
		s.grade = 'E';
	else if(s.avg>=50 && s.avg<60)
		s.grade = 'D';
	else if(s.avg>=60 && s.avg<80)
		s.grade = 'C';
	else if(s.avg>=80 && s.avg<90)
		s.grade = 'B';
	else if(s.avg>=90 && s.avg<=100)
		s.grade = 'A';
	else
		s.grade = 'F';
	return(s);
}

void showInfo(StudentInfo s)
{
	system("clear");

	cout << "-------------------------------------------------------------------------------" << newline;

	cout << tab << tab << "Score Card for Student : " << s.name << newline;
	
	cout << "Registration Number : " << s.roll << tab << tab << "Semester : " << s.sem << tab << "Year : " << s.yoj << newline;
	
	cout << "Grade Assigned : " << newline << newline;

	cout << "Serial No." << tab << tab << "Subject Name" << tab << tab << "Marks Scored (out of 100)" << newline;

	cout << "_______________________________________________________________________________" << newline;

	cout << "1" << tab << tab << tab << "OOPD" << tab << tab << tab << s.marks[0] << newline;
	cout << "2" << tab << tab << tab << "ADBMS" << tab << tab << tab << s.marks[1] << newline;
	cout << "3" << tab << tab << tab << "ADSA" << tab << tab << tab << s.marks[2] << newline;
	cout << "4" << tab << tab << tab << "CM" << tab << tab << tab << s.marks[3] << newline;
	cout << "5" << tab << tab << tab << "SEPM" << tab << tab << tab << s.marks[4] << newline;

	cout << "_______________________________________________________________________________" << newline;
	
	cout << tab << tab << tab << "Total :" << tab << tab << tab << s.total << newline;
	cout << tab << tab << tab << "Average :" << tab << tab << s.avg << newline;
	cout << tab << tab << tab << "Grade :" << tab << tab << tab << s.grade << newline;
	
	cout << newline << newline;
	cout << "Signatures :" << newline << newline;
	cout << tab << tab << "Student" << tab << tab << tab << "HOD" << newline;
	cout << "-------------------------------------------------------------------------------" << newline;
	return;
}

int main(void)
{
	unsigned int i, sCount;
	cout << "How many students ? ";
	cin >> sCount;

	struct StudentInfo s;
	for(i = 1; i <= sCount; i++)
	{
		s = getInfo();
		showInfo(s);
	}
	return(0);
}

