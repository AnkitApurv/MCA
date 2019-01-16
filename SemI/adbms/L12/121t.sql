set serveroutput on
declare
	intrest number(10, 2);
	principle number(10, 2) := &principle;
	rate number(4, 2) := &rate;
	duration number(2, 0) := &duration;
BEGIN
	intrest_calc(principle, rate, duration, intrest);
	dbms_output.put_line('intrest is ' || intrest);
END;
/