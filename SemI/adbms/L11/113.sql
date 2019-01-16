--Write a PL/SQL trigger to fire when there is an insert /update/deletes operation on EMP table;
--record the information in AUDIT_EMP table which has same structure as that of EMP along 
--with a new column OPERATION (stores UPDATE/INSERT/DELETE depending on operation being done.)
set serveroutput on
create or replace trigger emp_audit
after insert or update or delete
on emp for each row
BEGIN
CASE
	WHEN updating then
		insert into emp_audit_log values(:old.EMPNO, :old.ENAME, :old.JOB, :old.MGR_ID, :old.DATE_BIRTH, :old.SAL, :old.COMM, :old.DEPT_NO, :old.DATE_OF_JOIN, :old.PRJ_ID, 'UPDATE');
	WHEN inserting then
		insert into emp_audit_log values(:new.EMPNO, :new.ENAME, :new.JOB, :new.MGR_ID, :new.DATE_BIRTH, :new.SAL, :new.COMM, :new.DEPT_NO, :new.DATE_OF_JOIN, :new.PRJ_ID, 'INSERT');
	WHEN deleting then
		insert into emp_audit_log values(:old.EMPNO, :old.ENAME, :old.JOB, :old.MGR_ID, :old.DATE_BIRTH, :old.SAL, :old.COMM, :old.DEPT_NO, :old.DATE_OF_JOIN, :old.PRJ_ID, 'DELETE');
END CASE;
END;
/

--CREATE TABLE emp_audit_log (
--EMPNO NUMBER(4) NOT NULL,
--ENAME VARCHAR2(10),
--JOB VARCHAR2(9),
--MGR_ID NUMBER(4),
--DATE_BIRTH DATE,
--SAL NUMBER(7,2),
--COMM NUMBER(7,2),
--DEPT_NO VARCHAR2(3),
--DATE_OF_JOIN DATE,
--PRJ_ID VARCHAR2(5),
--ops varchar2(6) not null);