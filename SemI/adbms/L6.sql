--6.1 List Job category and total salary paid for the each jobs category by the company.
SELECT JOB, SUM(SAL) FROM EMP GROUP BY(JOB);

--6.2 Display name of the department from which maximum number of employees are working on project P1.
SELECT DNAME FROM DEPT WHERE DNO IN(SELECT max(count(empno)) FROM emp WHERE PRJ_ID ='P1' group by dept_no);

--6.3 Select all employees from ‘Marketing’ and ‘Research’ dept.
SELECT empno, ename FROM EMP WHERE DEPT_NO IN(select dno from dept where dname IN('Research', 'Marketing'));

--6.4 Display all employee names and salary whose salary is greater than minimum salary of the company.
select ename, sal from emp where sal > (select min(sal) from emp);

--6.5 Issue a query to find all the employees who work in the same job as Mahesh.
select empno, ename from emp where job=(select job from emp where ename='Mahesh');

--6.6 Create a View EMP_PRJ_VW to display records of employees of ‘marketing’ department and project in which they are working.
CREATE VIEW marketing_staff AS
select empno, ename from emp where dept_no in (select dno from dept where dname='Marketing')
WITH READ ONLY CONSTRAINT VIEW_MARKETING_STAFF_READ_ONLY;
CREATE VIEW emp_prj_vw AS
select empno, ename from emp where dept_no in (select dno from dept where dname='Marketing');

--6.7 Display employee names and projects in which they are working using View EMP_PRJ_VW
select ename, prj_id from emp where empno in (select empno from marketing_staff);
select ename, prj_id from emp where empno in (select empno from emp_prj_vw);

--6.8 Insert a record into View EMP_PRJ_VW and check the underlying tables for result and confirm result with reason.
insert into emp_prj_vw values(5, 'Yash');
select ename from emp where empno=5; --insert works

--6.9 Create a unique index on the column name DNAME on DEPT table.
create unique index dept_name on dept(dname);

--6.10 Create an index on the columns (name and job) on EMP table.
create index emp_job on emp(ename, job);

--6.11 Create a Sequence STUD_SEQ which starts from 100 to 999 with increments of 3.
create sequence stud_seq MINVALUE 100 MAXVALUE 999 START WITH 100 INCREMENT BY 3 CACHE 5;