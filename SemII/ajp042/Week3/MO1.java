/*
@desc Input the coordinates (integer values) of three points P1, P2 and P3 in a plane.
• Calculate and the distance between P1 and P2 (by passing the
coordinates of one point as arguments).
• Calculate and the distance between P1 and P3 (by passing one point
itself as argument).
@author Ankit Apurv
@date 15/01/19
*/

import java.util.Scanner;

class MO1
{
	public static void main(String args[])
	{
		Point p1 = new Point();
		Point p2 = new Point();
		Point p3 = new Point();
		System.out.println("\nDistance b/w P1 and P2 : " + p1.distance(p2.x, p2.y)
						  +"\nDistance b/w P1 and P3 : " + p1.distance(p3));
	}	
}

class Point
{
	int x, y;
	Point()
	{
		setCoords();
	}/*
	Point(int j, int k)
	{
		this.x = j;
		this.y = k;
	}*/
	public void setCoords()
	{
		Scanner s = new Scanner(System.in);
		System.out.print("\nX coordinate : ");
		this.x = s.nextInt();
		System.out.print("Y coordinate : ");
		this.y = s.nextInt();
		return;
	}
	public double distance(int j, int k)
	{
		return (Math.sqrt(Math.pow(x-j, 2) + Math.pow(y-k, 2)));
	}
	public double distance(Point p)
	{
		return (Math.sqrt(Math.pow(x-p.x, 2) + Math.pow(y-p.y, 2)));
	}
}