--Write a PL/SQL block to insert row into EMP table.
set serveroutput on
declare
	v emp%rowtype;
begin
	v.empno := 15;
	v.ename := 'KQP';
	v.job := 'A.MGR';
	v.mgr_id := '';
	v.date_birth := TO_DATE('10-10-2000','DD-MM-YYYY');
	v.sal := 30000;
	v.comm := 5000;
	v.dept_no := '';
	v.date_of_join := TO_DATE('10-10-2018','DD-MM-YYYY');
	v.prj_id := '';
	insert into emp values (v.empno, v.ename, v.job, v.mgr_id, v.date_birth,
 v.sal, v.comm, v.dept_no, v.date_of_join, v.prj_id);
end;
/