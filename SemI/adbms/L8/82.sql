--Write a PL/SQL block to accept employee number and display Employee Name, salary of employees in the format – ‘RAVI draws 32000/- as salary’.
set serveroutput on
declare
	v_empno emp.empno%type := &v_empno;
	v_ename emp.ename%type;
	v_sal emp.sal%type;
begin
	select ename, sal into v_ename, v_sal from emp where empno = v_empno;
	dbms_output.put_line(v_ename || ' draws ' || v_sal || ' /- as salary');
end;
/