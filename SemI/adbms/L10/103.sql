--Write a PL/SQL block to accept employee number and display Employee Name, salary
set serveroutput on
declare
	v_empno emp.empno%type := &v_empno;
	v_ename emp.ename%type;
	v_sal emp.sal%type;
	HIGH_SAL EXCEPTION;
begin
	select ename, sal into v_ename, v_sal from emp where empno = v_empno;
	dbms_output.put_line(v_ename || ' draws ' || v_sal || ' /- as salary');
	IF v_sal < 25000 THEN
		UPDATE emp SET sal = 25000 WHERE empno = v_empno;
		dbms_output.put_line('Salary Update');
	END IF;

	IF v_sal > 25000 THEN
		RAISE HIGH_SAL;
	END IF;
	EXCEPTION
	WHEN NO_DATA_FOUND THEN dbms_output.put_line('Employee not found!');
	WHEN HIGH_SAL THEN dbms_output.put_line('Salary above 25000');
end;
/