/*
@desc Collections – 1
Create and initialize a vector with first five odd integers. 
Using a menu, perform the following operations on this vector:
	• Insert an element at a specified position 
	• Insert an element at the end 
	• Delete an element 
	• Display the contents 

@name Ankit Apurv
@roll 180970042
@date 12/03/19
*/
import java.util.*;

class Collections1 {
	public static void main(String ... args) {
		Vector<int> oddV = new Vector();
		int counter = 0;
		int i = 1;
		while(counter <= 5)
		{
			oddV.add(i);
			i += 2;
		}
		int choice = 0;
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Collections 1\n\n");
		System.out.print(
		"1. Insert at specified position\n" 
		+ "2. Insert at end"
		+ "3. Delete element at specified position\n"
		+ "4. Delete element\n"
		+ "5. Exit\n\n");
		
		while(choice != 5)
		{
			System.out.print("Choice : ");
			choice = sc.nextInt();
			switch(choice) {
				case 1 : break;
				
				case 2 : break;
				
				case 3 : break;
				
				case 4 : break;
				
				case 5 :
				default : choice = 5; break;
			}
		}
	}
}