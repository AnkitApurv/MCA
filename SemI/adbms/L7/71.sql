--Write a PL/SQL block to find the sum of the digits of a given number.
SET SERVEROUTPUT ON
DECLARE
	s number := 0;
	num number := &num;
BEGIN
	WHILE num > 0 LOOP
		s := s + mod(num, 10);
		num := num - mod(num, 10);
		num := num / 10;
	END LOOP;
	dbms_output.Put_line('sum of digits = ' || s);
END;
/