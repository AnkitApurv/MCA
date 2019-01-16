#include <iostream>
#include <string>

struct StudentInfo {
	std::string name;
	std::string branch;
	std::string doj;
	std::string subjects;
	std::string dept;
	std::string college;
	std::string university;
};

struct StudentInfo getInfo(void);

void showInfo(struct StudentInfo s);

int main(void)
{
	unsigned int i, sCount;
	std::cout << "How many students ? ";
	std::cin >> sCount;

	struct StudentInfo s;
	for(i = 1; i <= sCount; i++)
	{
		s = getInfo();
		showInfo(s);
	}
	return(0);
}

struct StudentInfo getInfo()
{
	struct StudentInfo s;
	std::cout << "Name : ";
	std::cin >> s.name;
	std::cout << std::endl << "Branch : ";
	std::cin >> s.branch;
	std::cout << std::endl << "Date of Joining : ";
	std::cin >> s.doj;
	std::cout << std::endl << "Subjects : ";
	std::cin >> s.subjects;
	std::cout << std::endl << "Department : ";
	std::cin >> s.dept;
	std::cout << std::endl << "College : ";
	std::cin >> s.college;
	std::cout << std::endl << "University : ";
	std::cin >> s.university;
	return(s);
}

void showInfo(struct StudentInfo s)
{
	std::cout << std::endl << "Name : " << s.name << std::endl;
	std::cout << "Branch : " << s.branch << std::endl;
	std::cout << "Date of Joining : " << s.doj << std::endl;
	std::cout << "Subjects : " << s.subjects << std::endl;
	std::cout << "Department : " << s.dept << std::endl;
	std::cout << "College : " << s.college << std::endl;
	std::cout << "University : " << s.university << std::endl;
	return;
}
