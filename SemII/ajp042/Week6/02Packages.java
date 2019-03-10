/*
@desc Packages 
Create a class that performs conversion of temperatures – from Celsius to Fahrenheit and vice versa. 
Include the following two packages: 
• CToF with a class CelsToFahr containing a method called ConvertCToF (double C) 
• FToC with a class FahrToCels containing a method called ConvertFToC (double F).  
Use a menu to select the type of conversion, input the relevant data, calculate and display the result.

@name Ankit Apurv
@roll 180970042
@date 12/02/19
*/

import java.util.Scanner;
import CToF.*;
import FToC.*;

class Packages {
	public static void main(String ... args) {
		Scanner s = new Scanner(System.in);
		boolean doWork = true;
		int choice = 0;
		double temperature = 0.0;
		System.out.println("Temperature Conversion");
		System.out.println("1. Fahrenheight to Celsius");
		System.out.println("2. Celsius to Fahrenheight");
		System.out.println("Exit");
		while(doWork) {
			System.out.print("\nChoice : "); choice = s.nextInt();
			switch(choice) {
				case 1 : 
						System.out.print("Fahrenheight : "); temperature = s.nextDouble();
						System.out.printf("Celsius : %.3f", CelsToFahr.ConvertCToF(temperature));
						break;
				case 2 :
						System.out.print("Celsius : "); temperature = s.nextDouble();
						System.out.printf("Fahrenheight : %.3f", FahrToCels.ConvertFToC(temperature));
						break;
				default :
				case 3 :
						doWork = false;
						break;
			}
		}
		return;
	}
}