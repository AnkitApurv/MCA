/*
@desc Create a class called Box having length, width, and height as attributes. 
Use a method along with all possible constructors to calculate volume. 
Create a derived class with additional data members namely weight and color. 
Include a method to display the volume and all the data members used in both the classes

@name Ankit Apurv
@roll 180970042
@date 05/02/19
*/

import java.util.Scanner;

class Box {
	double length, width, height;
	Box() {
		length = width = height = 0;
	}
	
	Box(double l, double w, double h) {
		length = l;
		width = w;
		height = h;
	}
	
	double volume() {
		return length * width * height;
	}
	
	void display() {
		System.out.println("Length : " + length);
		System.out.println("Width : " + width);
		System.out.println("Height : " + height);
		System.out.println("Volume : " + volume());
		return;
	}
}

class BoxEx extends Box {
	String color;
	double weightKg;
	BoxEx() {
		super();
	}
	BoxEx(double l, double w, double h, double wK, String clr) {
		super(l, w, h);
		weightKg = wK;
		color = clr;
	}
	void display() {
		super.display();
		System.out.println("Color : " + color);
		System.out.println("Weight : " + weightKg);
		return;
	}
}


class BoxExUI {
	public static void main(String args[]) {
		Scanner s = new Scanner(System.in);
		double l, w, h, wK;
		String clr;
		System.out.print("Length : ");
		l = s.nextDouble();
		System.out.print("Width : ");
		w = s.nextDouble();
		System.out.print("Height : ");
		h = s.nextDouble();
		System.out.print("Color : ");
		clr = s.next().toString();
		System.out.print("Weight : ");
		wK = s.nextDouble();
		
		System.out.print("\n\n\n");
		
		BoxEx b = new BoxEx(l, w, h, wK, clr);
		
		b.display();
		return;
	}
}