set serveroutput on
declare
	v_ename emp.ename%Type;
	v_sal emp.sal%Type;
	v_empno emp.empno%Type;
begin
	v_empno := & v_empmo;
	select ename, sal INTO v_ename, v_sal from emp where empno = v_empno;
	dbms_output.put_line(v_ename || ' ' || v_sal);
end;
/