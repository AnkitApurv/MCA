--Write a parameterized cursor to find employee with the given job and dept no.
SET serveroutput ON
DECLARE
	v_job emp.job%type;
	k_job emp.job%type := '&k_job';
	v_dno emp.dept_no%type;
	k_dno emp.dept_no%type := '&k_dno';
	v_ename emp.ename%type;

	CURSOR emp_info(k_job varchar2, k_dno varchar2) IS 
select ename, job, dept_no from emp where job = k_job AND dept_no = k_dno;
BEGIN
	OPEN emp_info(k_job, k_dno);
		--IF emp_info%rowcount = 0 THEN
			--dbms_output.put_line('Employee not found!' || emp_info%rowcount);
		--ELSE
			LOOP
				FETCH emp_info into v_ename, v_job, v_dno;
				dbms_output.put_line(v_ename || ' ' || v_job || ' ' || v_dno);
				EXIT WHEN emp_info%notfound;
			END LOOP;
		--END IF;
	CLOSE emp_info;
END;
/