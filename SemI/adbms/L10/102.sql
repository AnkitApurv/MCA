DECLARE
	principal number(10, 2) := &principal;
	rate number(4, 2) := &rate;
	duration number(2, 0) := &duration;
	intrest number(10, 2);
	--User Defined Exception Decleration
	Less_Principal EXCEPTION;
	Less_Intrest EXCEPTION;
	Less_duration Exception;
BEGIN
	IF principal<=1000 THEN
		RAISE Less_Principal;
	END IF;
	IF rate<5 THEN
		RAISE Less_Intrest;
	END IF;
	IF duration<1 THEN
		RAISE Less_duration;
	END IF;
	intrest := (principal*rate*duration)/100;
	DBMS_OUTPUT.PUT_LINE(intrest);
	EXCEPTION 
	WHEN Less_Principal THEN DBMS_OUTPUT.PUT_LINE('Less_Principal');
	WHEN Less_Intrest THEN DBMS_OUTPUT.PUT_LINE('Less_Intrest');
	WHEN Less_duration THEN DBMS_OUTPUT.PUT_LINE('Less_duration');
END;
/