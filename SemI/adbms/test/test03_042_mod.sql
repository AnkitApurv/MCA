SET SERVEROUTPUT ON
DECLARE
	v_name Book_Issue.book_name%type;
	v_id Book_Issue.Book_ID%type := '&v_id';
	v_c Book_Issue.copies%TYPE;
	v_d date;
BEGIN
	select book_name, copies into v_name, v_c from Book_Issue where Book_ID = v_id;
	IF v_c > 0 THEN
		v_c := v_c - 1;
		update Book_Issue SET copies = v_c where Book_ID = v_id;
		v_d := current_date + 7;
		dbms_output.put_line(v_name || ' issued and return date is ' || v_d);
	ELSE
		dbms_output.put_line(v_name || ' is currently not available.');
	END IF;
END;
/