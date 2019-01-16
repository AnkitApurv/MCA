--Write a PL/SQL block to check an input string is palindrome or not palindrome.
SET SERVEROUTPUT ON
DECLARE
	s varchar2(10) := '&s';
	s2 s%Type;
	l number;
BEGIN
	l := length(s);
	FOR i IN REVERSE 1..l LOOP
		s2 := s2 || substr(s, i, 1);
		-- || means append
		-- substr(string, position, countOfChars)
	END LOOP;
	dbms_output.Put_line('Reverse : ' || s2);
	IF s = s2 THEN
		dbms_output.Put_line('Palindrome');
	ELSE
		dbms_output.Put_line('Not Palindrome');
	END IF;
END;
/