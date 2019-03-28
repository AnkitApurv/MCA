/*
@desc Collections – 2
Input five strings and store them in an ArrayList. Sort it in alphabetic order. 
Display the list in the forward direction (using an iterator) and in both directions (using a listIterator). 
@name Ankit Apurv
@roll 180970042
@date 19/03/19
*/

import java.util.*;

class Collections2 {
	public static void main(String ... args) {
		if(args.length < 5) {
			System.out.println("java Collections2 string1 ... string5");
			System.exit(1);
		}
		
		ArrayList<String> k = new ArrayList<String>();
		for(int index=0; index<5; index++)
			k.add(args[index]);
		Collections.sort(k);
		
		Iterator<String> i = k.iterator();
		System.out.println("1. By iterator, in forward direction : ");
		while(i.hasNext())
			System.out.println(i.next());
		System.out.println();

		ListIterator<String> li = k.listIterator();
		System.out.println("2. By listIterator, in forward direction : ");
		while(li.hasNext())
			System.out.println(li.next());
		System.out.println();
		
		System.out.println("3. By listIterator, in reverse direction : ");
		while(li.hasPrevious())
			System.out.println(li.previous());
		System.out.println();
		
		return;
	}
}