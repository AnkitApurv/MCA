/* Find area of circle */
SET SERVEROUTPUT ON
DECLARE
	pi constant number := 3.14;
	v_radius number;
	area number;
BEGIN
	SELECT radius INTO v_radius FROM circle;
	area := pi*v_radius*v_radius;
	dbms_output.put_line('Area of circle is : ' || area);
END;
/