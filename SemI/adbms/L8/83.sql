--Write a PL/SQL block for inserting rows into EMPSAL
--create table empsal(
--empno number(4, 0) primary key,
--ename varchar2(10),
--basic number(7, 2),
--hra number(6, 2),
--da number(6, 2),
--gross number(8, 2),
--pf number(6, 2),
--net number(8, 2));
--alter table empsal modify(hra number(7, 2), da number(7, 2), gross number(10, 2), pf number(7, 2), net number(10, 2));

SET SERVEROUTPUT ON
DECLARE
	v_eno emp.empno%type := &v_eno;
	s empsal%rowtype;
BEGIN
	select empno, ename, sal into s.empno, s.ename, s.basic from emp where empno = v_eno;
	s.hra := round(s.basic * 0.5, 2);
	s.da := round(s.basic * 0.2, 2);
	s.gross := round(s.basic + s.hra + s.da, 2);
	s.pf := round(s.basic * 0.12, 2);
	s.net := round(s.gross - s.pf, 2);
	INSERT INTO empsal VALUES (s.empno, s.ename, s.basic, s.hra, s.da, s.gross, s.pf, s.net);
END;
/