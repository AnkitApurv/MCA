DECLARE
	With_amount ACCOUNT.Balance%type;
	AccNum ACCOUNT.Accno%type;
	Current_Bal ACCOUNT.Bal%type;
	New_Bal ACCOUNT.Bal%type;
	--User Defined Exception Decleration
	Less_Fund EXCEPTION;
BEGIN
	AccNum:=& AccNum;
	With_amount:=& With_amount;
	SELECT Balance INTO Current_Bal FROM ACCOUNT WHERE ACCNO=AccNum;
	New_Bal:= Current_Bal - With_amount;
	IF New_Bal<1000 THEN
		RAISE Less_Fund;
	ELSE
		UPDATE ACCOUNT SET Balance=New_Bal WHERE ACCNO=AccNum;
	DBMS_OUTPUT.PUT_LINE (‘ Amount Dispatched . . .’);
	END IF;
	EXCEPTION WHEN Less_Fund THEN DBMS_OUTPUT.PUT_LINE(‘ Insufficient Fund . . .’);
END;
/