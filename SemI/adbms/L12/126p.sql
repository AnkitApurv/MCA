--Write a package containing procedure to calculate area of circle, perimeter and a function to find factorial of a number.
CREATE OR REPLACE PACKAGE math_calc IS
	PROCEDURE circle_calc(radius IN NUMBER, area OUT NUMBER, perimeter OUT NUMBER);
	FUNCTION factorial_calc(n IN NUMBER) RETURN NUMBER;
END math_calc;
/