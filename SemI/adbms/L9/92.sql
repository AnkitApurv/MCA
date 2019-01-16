--Write a cursor to display the list of employees and total salary department wise.
SET serveroutput ON
DECLARE
	v_dno emp.dept_no%type;
	v_sal number(10, 2);
	v_name emp.ename%type;
	CURSOR sal_info IS select dept_no, sum(sal) from emp group by dept_no;
	CURSOR staff IS select ename from emp where dept_no = v_dno;
BEGIN
	OPEN sal_info;
		LOOP
			FETCH sal_info into v_dno, v_sal;
				dbms_output.put_line('dept : ' || v_dno);
				dbms_output.put_line('sum(sal) : ' || v_sal);

				OPEN staff;
					dbms_output.put_line('staff');
					dbms_output.put_line('--------');
					LOOP
						FETCH staff into v_name;
							dbms_output.put_line(v_name);
						EXIT WHEN staff%NOTFOUND;
					END LOOP;
				CLOSE staff;
				dbms_output.put_line('______________________________');
			EXIT WHEN sal_info%NOTFOUND;
		END LOOP;
	CLOSE sal_info;
END;
/