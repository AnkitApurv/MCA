--Write a procedure to take SAL of given Employee as input and calculate HRA, PF, DA, GROSS, TAX and NETSAL and 
--return them to calling PL/SQL block(take EMPNO as keyboard input to get SAL). 

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
CREATE OR REPLACE PROCEDURE emp_pkg_calc
(basic IN NUMBER, hra OUT NUMBER, da OUT NUMBER, pf OUT NUMBER, gross OUT NUMBER, net OUT NUMBER, tax OUT NUMBER) IS
BEGIN
	hra := round(basic * 0.5, 2);
	da := round(basic * 0.2, 2);
	pf := round(basic * 0.12, 2);
	gross := round(basic + hra + da, 2);
	net := round(gross - pf, 2);
	tax := round(net * 0.2, 2);
END;
/