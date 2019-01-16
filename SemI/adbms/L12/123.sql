--Write a function to calculate square of a number and return calculated value to the calling PL/SQL block.
CREATE OR REPLACE FUNCTION sqre(n IN NUMBER) RETURN NUMBER IS
	s NUMBER(9, 2);
BEGIN
	s := round(n * n, 2);
	RETURN(s);
END;
/