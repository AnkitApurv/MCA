--Write a PL/SQL block to apply string functions on a given string.
SET SERVEROUTPUT ON
DECLARE
	s varchar2(10) := '&s';
	s2 s%Type;
	l number;
BEGIN
	l := length(s);
	dbms_output.put_line(l);
	s2 := asciistr(s);
	dbms_output.put_line(s2);
	s2 := substr(s, 1, 1);
	dbms_output.put_line(s2);
	l := instr(s, s2);
	dbms_output.put_line(l);
	s2 := replace(s, s2, ' ');
	dbms_output.put_line(s2);
	s2 := trim(s2);
	dbms_output.put_line(s2);
END;
/