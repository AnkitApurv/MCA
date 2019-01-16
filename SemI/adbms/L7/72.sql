--Write a PL/SQL block to check whether the given number is Armstrong or not.
--armstrong number - n-digit number equal to sum of n powers of its digits [number = sum(digit^numberOfDigits)]
SET SERVEROUTPUT ON
DECLARE
	armstrong number := 0;
	num number := &num;
	countOfDigits number := 0;
	temp number := num;
	temp2 number := num;
BEGIN
	WHILE temp > 0 LOOP
		temp := temp - mod(temp, 10);
		temp := temp / 10;
		countOfDigits := countOfDigits + 1;
	END LOOP;

	WHILE num > 0 LOOP
		temp := mod(num, 10);
		armstrong := armstrong + temp**countOfDigits;
		num := num - temp;
		num := num / 10;
	END LOOP;

	dbms_output.Put_line('armstrong = ' || armstrong);

	IF temp2 = armstrong THEN
		dbms_output.Put_line('It is an armstrong number');

	ELSE
		dbms_output.Put_line('It is not an armstrong number');

	END IF;
END;
/