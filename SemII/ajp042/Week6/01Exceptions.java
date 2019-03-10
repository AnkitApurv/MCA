/*
@desc Exception handling 
Create a try block that is likely to generate Number Format and Arithmetic exceptions 
and incorporate necessary catch blocks to catch and handle them appropriately. 
Use these exceptions to count the number of strings and integers entered through the command line. 
Also, use an exception to demonstrate user-defined exception (entered number is negative). 

@name Ankit Apurv
@roll 180970042
@date 12/02/19
*/

/*
D:\ajp042\Week6>java ExceptionDemo uagrf 2324 fadk 90 -5
java.lang.NumberFormatException: For input string: "uagrf"
java.lang.NumberFormatException: For input string: "fadk"
java.lang.ArithmeticException: / by zero
 is negative.-5IntegerNegativeException
Count of integers : 3
Count of strings : 2
*/

class ExceptionDemo {
	public static void main(String ... args) {	
		int countOfInts = 0, countOfStr = 0, number = 0, k = 0;
		for(String s : args)
		{
			try {
				number = Integer.parseInt(s);
				countOfInts++;
				if(number < 0) throw new IntegerNegativeException();
				if(number < 100) k = number / (number-number);
			}
			catch(NumberFormatException e) {
				System.out.println(e.toString());
				countOfStr++;
			}
			catch(ArithmeticException e) {
				System.out.println(e.toString());
			}
			catch(IntegerNegativeException e) {
				System.out.println(number + e.toString());
			}
		}
		System.out.println("Count of integers : " + countOfInts +
						   "\nCount of strings : " + countOfStr);
		return;
	}
}

class IntegerNegativeException extends Exception {
	IntegerNegativeException() {
		System.out.print(" is negative.");
	}
}