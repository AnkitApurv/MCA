--Write a cursor to display ENAME and SAL of all employees drawing salary more than 30000/-.
SET serveroutput ON
DECLARE
	CURSOR sal_info IS select ename, sal from emp where sal>30000;
	v_ename emp.ename%type;
	v_sal emp.sal%type;
BEGIN
	OPEN sal_info;
		dbms_output.put_line('ename        sal');
		dbms_output.put_line('-------- --------');
		LOOP
			FETCH sal_info into v_ename, v_sal;
			dbms_output.put_line(v_ename || '    ' || v_sal);
			EXIT WHEN sal_info%NOTFOUND;
		END LOOP;
	CLOSE sal_info;
END;
/