--Write a PL/SQL block to calculate the area of a circle for a value of radius varying from 3 to 7.
--Store the Radius and the corresponding values of calculated Area in an empty table named CIRCLE, consisting of two columns radius & area.
SET SERVEROUTPUT ON
DECLARE
	pi constant number := 3.14;
	radius number;
	area number;
	circum number;
BEGIN
	radius := dbms_random.value(3,7);
	area := round(pi*radius*radius, 2);
	circum := round(2*pi*radius, 2);
	INSERT INTO circle VALUES (radius, area);
	--INSERT INTO circle VALUES (radius, area, circum);
	dbms_output.put_line('Area of circle is : ' || area);
END;
/