--Write a TRIGGER to ensure that DEPT TABLE does not contain duplicate of null values in DEPTNO column.
set serveroutput on
create or replace trigger dno_valid
before insert or update OF dno
on dept for each row
DECLARE
	CURSOR DC is select dno, count(dno) from dept group by dno;
	v_dno dept.dno%type;
	v_c number(2, 0);
	MULTIPLE_DNO Exception;
	NULL_DNO Exception;
BEGIN
CASE
	WHEN inserting OR updating('dno') then
		OPEN DC;
		LOOP
		EXIT WHEN DC%notfound;
			FETCH DC INTO v_dno, v_c;
			IF v_c > 1 THEN
DBMS_OUTPUT.PUT_LINE(v_dno || ' has ' || v_c || ' mentions.');
				RAISE MULTIPLE_DNO;
			END IF;
			IF (v_dno = null) THEN
DBMS_OUTPUT.PUT_LINE('null dno found! ' || v_c || ' mentions.');
				RAISE NULL_DNO;
			END IF;
		END LOOP;
		CLOSE DC;
END CASE;
EXCEPTION
	WHEN MULTIPLE_DNO THEN DBMS_OUTPUT.PUT_LINE(v_dno || ' has ' || v_c || ' mentions.');
	WHEN NULL_DNO THEN DBMS_OUTPUT.PUT_LINE('null dno found! ' || v_c || ' mentions.');
END;
/