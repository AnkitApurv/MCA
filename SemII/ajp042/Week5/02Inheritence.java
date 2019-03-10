/*
@desc Create three classes as per the following specifications: 
• Student: Data members are Register Number, Name, Course and Semester. 
• Exam (derived from class Student): Data members are the marks scored in three subjects. 
• Result (derived from class Exam): Data members are Total Marks and Grade. 
Input the relevant data of one student (in the main() method) and process the result.

@name Ankit Apurv
@roll 180970042
@date 05/02/19
*/

import java.util.Scanner;

class Student {
	int registration, semester;
	String name, course;
	
	Student(int r, int s, String n, String c) {
		registration = r;
		semester = s;
		name = n;
		course = c;
	}
	
	void display() {
		System.out.println("registration : " + registration);
		System.out.println("semester : " + semester);
		System.out.println("name : " + name);
		System.out.println("course : " + course);
		return;
	}
}

class Exam extends Student {
	int subjectMarks[] = new int[3];

	Exam(int r, int s, String n, String c, int m1, int m2, int m3) {
		super(r, s, n, c);
		subjectMarks[0] = m1;
		subjectMarks[1] = m2;
		subjectMarks[2] = m3;
	}
	void display() {
		super.display();
		int j=1;
		for(int i : subjectMarks)
			System.out.println("Subject "+ j++ +" Marks : " + i);
		return;
	}
}


class Result extends Exam {
	int total;
	char grade = 'C';
	
	Result(int r, int s, String n, String c, int m1, int m2, int m3) {
		super(r, s, n, c, m1, m2, m3);
		for(int i : subjectMarks)
			total += i;
		int avg = total/3;
		if(avg <= 100 && avg >= 80)
			grade = 'A';
		else if(avg <= 80 && avg >= 60)
			grade = 'B';
		else if(avg <= 60 && avg >= 40)
			grade = 'C';
		else
			grade = 'F';
	}
	void display() {
		super.display();
		System.out.println("Total : " + total);
		System.out.println("Grade : " + grade);
		return;
	}
}

class ResultUI {
	public static void main(String args[]) {
		Scanner s = new Scanner(System.in);
		int r, sm;
		int m[] = new int[3];
		String n, c;
		System.out.print("Registration : ");
		r = s.nextInt();
		System.out.print("Semester : ");
		sm = s.nextInt();
		for(int i=0; i<=2; i++)
		{
			System.out.print("Marks "+ (i+1) + " : ");
			m[i] = s.nextInt();
		}
		System.out.print("name : ");
		n = s.next().toString();
		System.out.print("course : ");
		c = s.next().toString();
		
		System.out.print("\n\n\n");
		
		Result b = new Result(r, sm, n, c, m[0], m[1], m[2]);
		
		b.display();
		return;
	}
}