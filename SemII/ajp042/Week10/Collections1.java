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
		Vector<Integer> oddV = new Vector<Integer>();
		int counter = 1;
		int i = 1;
		while(counter <= 5) {
			oddV.add(i);
			i += 2;
			counter++;
		}
		int choice = 0;
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Collections 1\n\n"
		+ "1. Insert at specified position\n" 
		+ "2. Insert at end\n"
		+ "3. Delete element at specified position\n"
		+ "4. Delete element\n"
		+ "5. Display the vector\n"
		+ "6. Exit(default)\n\n");

		int element, position;
		while(choice != 6) {
			element = position = 0;
			System.out.print("\nChoice : ");
			choice = sc.nextInt();
			switch(choice) {
				case 1 : 
					System.out.print("At position : ");
					position = sc.nextInt();
					System.out.print("Element : ");
					element = sc.nextInt();
					oddV.add(position, element);
					break;
				
				case 2 : 
					System.out.print("Element : ");
					element = sc.nextInt();
					oddV.addElement(element);
					break;
				
				case 3 :
					System.out.print("At position : ");
					position = sc.nextInt();
					element = oddV.remove(position);
					System.out.println("Element : " + element);
					break;
				
				case 4 : 
					System.out.print("Element : ");
					element = sc.nextInt();
					Integer k = Integer.valueOf(element); //new Integer(int) is deprecated since Java 9
					oddV.remove(k);
					break;
				
				case 5 :
					System.out.println("Vector : \n" + oddV);
					break;
				
				case 6 :
				default : 
					choice = 6;
					break;
			}
		}
		sc.close();
		return;
	}
}