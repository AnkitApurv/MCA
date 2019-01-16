--Write a PL/SQL block trigger to carry out the following action:
--on deleting a deptno from dept table, all the records with that deptno has to be
--deleted from the emp table.
set serveroutput on
create or replace trigger del_cascade_dept_emp
BEFORE delete on dept FOR EACH ROW
DECLARE
	v_d dept.dno%type;
BEGIN
	select :old.dno into v_d from dept;
	delete from emp where dept_no = v_d;
END;
/
--SELECT TRIGGER_NAME, TRIGGERING_EVENT FROM USER_TRIGGERS WHERE TABLE_NAME='DEPT';