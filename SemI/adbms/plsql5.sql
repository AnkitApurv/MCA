CREATE TABLE NUMBERS_TBL(NUM NUMBERS(3,0));

set serveroutput on
declare
	i NUMBERS_TBL.NUM%Type := 1;
begin
	
	LOOP
		INSERT INTO numbers_tbl VALUES(i);
		i := i + 1;
		EXIT WHEN i > 10;
	END LOOP;
end;
/