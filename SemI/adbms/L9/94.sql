--to display name and salary given project via prameterized cursor
SET serveroutput ON
DECLARE
	v_ename emp.ename%type;
	v_sal emp.sal%type;
	k_prj emp.prj_id%type := '&k_prj';

	CURSOR emp_info(k_prj varchar2) IS select ename, sal from emp where prj_id = k_prj;
BEGIN
	OPEN emp_info(k_prj);
	dbms_output.put_line(k_prj);
		LOOP
			FETCH emp_info into v_ename, v_sal;
			dbms_output.put_line(v_ename || ' ' || v_sal);
			EXIT WHEN emp_info%notfound;
		END LOOP;
	CLOSE emp_info;
END;
/