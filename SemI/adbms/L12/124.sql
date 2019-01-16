--Write two functions to calculate age and service experience of all employees and return these values to calling PL/SQL block and display.
CREATE OR REPLACE FUNCTION calc_age(bd IN DATE) RETURN NUMBER IS
	age NUMBER(2, 0);
BEGIN
	age := to_number(extract(year from sysdate)) - to_number(extract(year from bd));
	RETURN(age);
END;
/

CREATE OR REPLACE FUNCTION calc_exp(doj IN DATE) RETURN NUMBER IS
	exp NUMBER(2, 0);
BEGIN
	exp := to_number(extract(year from sysdate)) - to_number(extract(year from doj));
	RETURN(exp);
END;
/