set serveroutput on
DECLARE
	n1 number(3);
	n2 number(3);
BEGIN
	n1:=&n1;
	n2:= sqre(n1);
	DBMS_OUTPUT.PUT_LINE('Square is '||n2);
END;
/