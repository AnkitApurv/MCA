SET SERVEROUTPUT ON
DECLARE
	v_reg student.regno%type;
	v_m1 student.m1%type;
	v_m2 student.m2%type;
	v_avg student.avg%type;
	v_grade student.grade%type;
BEGIN
	v_reg := & v_reg;
	SELECT m1, m2 INTO v_m1, v_m2 FROM student WHERE regno = v_reg;
	v_avg := (v_m1 + v_m2) / 2;
	UPDATE student SET avg = v_avg WHERE regno = v_reg;
	dbms_output.put_line('Average : ' || v_avg);
END;
/