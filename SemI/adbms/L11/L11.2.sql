set serveroutput on
create or replace trigger t before insert or update OF sal, dept_no OR DELETE on emp for each row
BEGIN 
CASE
	WHEN inserting then
		dbms_output.put_line('inserting');
		dbmS_output.put_line(:new.empno);
	WHEN UPDATING('sal') THEN
		DBMS_OUTPUT.PUT_LINE('UPDATING SALARY');
		dbmS_output.put_line(:old.sal);
		dbms_output.put_line(:new.sal);
	when updating('dept_no') THEN
		DBMS_OUTPUT.PUT_LINE('UPDATING DEPT ID');
		dbms_output.put_line(:new.dept_no);
	when DELETING THEN
		DBMS_OUTPUT.PUT_LINE('DELETING');
END CASE;
END;
/