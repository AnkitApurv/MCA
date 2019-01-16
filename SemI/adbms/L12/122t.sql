SET SERVEROUTPUT ON
DECLARE
	v_eno emp.empno%type := &v_eno;
	v_s emp.sal%type;
	hra emp.sal%type;
	da emp.sal%type;
	gross emp.sal%type;
	pf emp.sal%type;
	net emp.sal%type;
	tax emp.sal%type;
BEGIN
	select sal into v_s from emp where empno = v_eno;
	emp_pkg_calc(v_s, hra, da, gross, pf, net, tax);
	dbms_output.put_line(v_s || ' ' || hra || ' ' || da || ' ' || gross || ' ' || pf || ' ' || net || ' ' || tax);
END;
/