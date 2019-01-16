set serveroutput on
declare
	radius number(3) := &radius;
	area number(7);
	perimeter number(5);
	factorial number(3) := &factorial;
	f number(7);
BEGIN
	math_calc.circle_calc(radius, area, perimeter);
	dbms_output.put_line(area || ' ' || perimeter);

	f := math_calc.factorial_calc(factorial);
	dbms_output.put_line(f);
END;
/