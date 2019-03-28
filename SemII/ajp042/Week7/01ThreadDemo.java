/*
@desc Multithreading 
Input an integer n. Calculate and display the squares and cubes of all integers from 1 to n using two different threads. 

@name Ankit Apurv
@roll 180970042
@date 12/02/19
*/

class ThreadDemo {
	public static void main(String ... args)throws Exception {
		int k = Integer.parseInt(args[0]);
		for(int i=1; i <= k; i++) {
			CalcSquare s = new CalcSquare(i);
			s.start();
			s.join();
			CalcCube c = new CalcCube(i);
			c.start();
			c.join();
		}
		return;
	}
}

class CalcSquare extends Thread {
	int k;
	CalcSquare(int w) { k = w; }
	public void run() {
		System.out.println("Square of " + k + " : " + Math.pow(k, 2));
		return;
	}
}

class CalcCube extends Thread {
	int k;
	CalcCube(int w) { k = w; }
	public void run() {
		System.out.println("Cube of " + k + " : " + Math.pow(k, 3));
		return;
	}
}