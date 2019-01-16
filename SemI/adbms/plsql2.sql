/* Find area of circle */
SET SERVEROUTPUT ON
DECLARE
	pi constant number := 3.14;
	radius number := & radius;
	area number;
BEGIN
	area := pi*radius*radius;
	dbms_output.put_line('Area of circle is : ' || area);
END;
/