--5.1 List the minimum, maximum and average salaries and rename the column as min_sal,max_sal,avg_sal of the company
select MIN(sal) AS min_sal, MAX(sal) AS max_sal, AVG(sal) AS avg_sal from emp; --

--5.2 List the Projects name undertaken by Marketing Department
select prj_name from proj where dno IN (select dno from dept where dname='Marketing'); --

--5.3 Display the employees name and salary in descending order by salary.
select ename, sal from emp order by sal desc; --

--5.4 List the name of departments which are working with more than 1 project NOT DONE
select distinct dname from dept, proj having count(proj.dno) > 1;
where dept.dno = proj.dno 

--5.5 Display department name, Max salary and Min salary in each department
select dept_no, max(sal) AS max_sal, min(sal) AS min_sal from emp group by dept_no; --

--5.6 Display number of employees working in each department and their department name
select distinct ename, dname from emp, dept where emp.dept_no = dept.dno; --

--5.7 List the employees whose experience is more than 5 years.
select empno, ename, date_of_join AS doj from emp where extract(year from sysdate) - extract(year from date_of_join) > 5; --

--5.8 List the Employees who are born in the month of December.
select empno, ename, date_of_join AS doj from emp where extract(month from date_of_join)=12; --

--5.9 List the Employees who are born on a given year.
select empno, ename, date_of_join AS doj from emp where extract(year from date_of_join)=1990; --

--5.10 Display the DOB of all employees in the format “dd-mm-yy”.
select empno, ename, to_char(date_birth, 'DD-MM-YY') from emp; --

--5.11 List the Employees having service experience more than 10 years.
select empno, ename, date_of_join AS doj from emp where extract(year from sysdate) - extract(year from date_of_join) > 10; --

--5.12 List the projects which have duration more than 1 year.
SELECT PRJ_NO, PRJ_NAME, strt_date, end_date from proj WHERE extract(year from end_date) - extract(year from strt_date) > 1; --

--5.13 List the Employees Name who is working at Locations (BNG,MUB,HYD)
select ename from emp where dept_no in (select dno from dept where location in('BNG', 'MUB', 'HYD')); --

--5.14 Update the COMM column of EMP table based on the SAL. Use COMM=COMM+SAL*10/100
select comm from emp;
UPDATE emp SET comm=comm+(sal/10); --