--Write a package containing procedure to calculate area of circle, perimeter and a function to find factorial of a number.
CREATE OR REPLACE PACKAGE BODY math_calc IS
	PROCEDURE circle_calc(radius IN NUMBER, area OUT NUMBER, perimeter OUT NUMBER) IS
	BEGIN
		area := 3.14 * radius * radius;
		perimeter := 2 * 3.14 * radius;
	END circle_calc;

	FUNCTION factorial_calc(n IN NUMBER) RETURN NUMBER IS
		f number(12) := 1;
		t number(4);
	BEGIN
		t := n;
		while t > 1 loop
			f := f * t;
			t := t - 1;
		end loop;
		return(f);
	END factorial_calc;
END math_calc;
/