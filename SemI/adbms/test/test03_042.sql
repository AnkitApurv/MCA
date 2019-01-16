SET SERVEROUTPUT ON
DECLARE
	v_name Book_Issue.book_name%type;
	v_id Book_Issue.Book_ID%type := '&v_id';
	v_c Book_Issue.copies%TYPE;
BEGIN
	select book_name, copies into v_name, v_c from Book_Issue where Book_ID = v_id;
	IF v_c > 0 THEN
		v_c := v_c - 1;
		update Book_Issue SET copies = v_c where Book_ID = v_id;
		dbms_output.put_line(v_name || ' issued and return date is ' || sysdate);
	ELSE
		dbms_output.put_line(v_name || ' is currently not available.');
	END IF;
END;
/