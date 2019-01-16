--Write functions to find department name and number of projects it is handling. Display this information in the calling PL/SQL block.

CREATE OR REPLACE FUNCTION get_dept_name(v_dno IN VARCHAR2) RETURN VARCHAR2 IS
	v_dname VARCHAR(10);
BEGIN
	select dname into v_dname from dept where dno = v_dno;
	RETURN(v_dname);
END;
/

CREATE OR REPLACE FUNCTION get_dept_prj_count(v_dno IN VARCHAR2) RETURN NUMBER IS
	ctprj NUMBER(2, 0);
BEGIN
	select count(prj_no) into ctprj from proj where dno = v_dno group by dno;
	RETURN(ctprj);
END;
/