--Write a PL/SQL trigger to fire when there is an updation of salary of any employee and
--record the Empno, Dept. Name and Old Salary, date on which salary is modified and
--user who modified information in the table SAL_MOD (Empno, Dname, Old_Sal, Mod_Date, Modifier).
set serveroutput on
create or replace trigger sal_mod_log
after update OF sal
on emp for each row
DECLARE
	mod_sal emp.sal%type;
BEGIN
mod_sal := :new.sal - :old.sal;
IF updating('sal') then
		insert into SAL_MOD values(:old.empno, :old.dept_no, :old.sal, sysdate, mod_sal, user);
END IF;
END;
/

--create table SAL_MOD (
--empno NUMBER(4) not null,
--dept_no varchar2(3) not null,
--o_sal number(7, 2) not null,
--m_date date not null,
--m_sal number(7, 2) not null,
--auth varchar2(30) not null);