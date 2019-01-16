set serveroutput on
DECLARE
cursor ea is select empno, date_birth, date_of_join from emp;
	e emp.empno%type;
	bd date;
	dj date;
	n1 number(2);
	n2 number(2);
BEGIN
	open ea;
	loop
	fetch ea into e, bd, dj;
	exit when ea%notfound;
		n1 := calc_age(bd);
		n2 := calc_exp(dj);
		DBMS_OUTPUT.PUT_LINE('ID : '|| e);
		DBMS_OUTPUT.PUT_LINE('Age : '|| n1);
		DBMS_OUTPUT.PUT_LINE('Exp : '|| n2);
	end loop;
	close ea;
END;
/