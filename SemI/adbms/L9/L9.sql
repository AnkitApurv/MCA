DECLARE
	CURSOR cur_stud IS SELECT rno, mark1, mark2, mark3, mark4 from stud;
	v stud%rowtype;
BEGIN
	BEGIN
	OPEN cur_stud;
		LOOP
			FETCH cur_stud into v.rno, v.mark1, v.mark2, v.mark3, v.mark4;
			EXIT WHEN cur_stud%NOTFOUND;
			IF sum(v.mark1, v.mark2, v.mark3, v.mark4) >= 350 THEN
				v.grade = 'A';
			ELSIF sum(v.mark1, v.mark2, v.mark3, v.mark4) >= 300 THEN
				v.grade = 'B';
			ELSIF sum(v.mark1, v.mark2, v.mark3, v.mark4) >= 250 THEN
				v.grade = 'C';
			END IF;
		END LOOP;
	CLOSE cur_stud;
END;
/