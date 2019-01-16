set serveroutput on
create or replace trigger t_del_emp_each
before
DELETE ON emp
for each row
DECLARE

BEGIN
	DBMS_OUTPUT.PUT_LINE('DELETING');
END;
/