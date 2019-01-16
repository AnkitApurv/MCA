set serveroutput on
DECLARE
	e emp.empno%type := &e;
	bd date;
	dj date;
	n1 number(2);
	n2 number(2);
BEGIN
	select date_birth, date_of_join into bd, dj from emp where empno = e;
	n1 := calc_age(bd);
	n2 := calc_exp(dj);
	DBMS_OUTPUT.PUT_LINE(n1||' '||n2);
END;
/