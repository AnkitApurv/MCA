set serveroutput on
declare
	v_dno varchar2(4) := '&v_dno';
	v_dname VARCHAR2(10);
	ctprj NUMBER(2, 0);
BEGIN
	v_dname := get_dept_name(v_dno);
	ctprj := get_dept_prj_count(v_dno);
	dbms_output.put_line(v_dname || ' ' || ctprj);
END;
/