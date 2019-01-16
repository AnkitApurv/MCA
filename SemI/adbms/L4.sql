--4.0
DESC emp;
DESC dept;
DESC proj;

--4.1
SELECT * FROM emp;
SELECT * FROM dept;
SELECT * FROM proj;

--4.2
SELECT * FROM emp WHERE sal>25000 OR dept_no='D1';

--4.3
SELECT * FROM emp WHERE sal>25199 AND sal<35201;

--4.4
CREATE TABLE emp_pseudo AS(SELECT * FROM emp);
SELECT * FROM emp_pseudo;

--4.5
SELECT DISTINCT dept_no FROM emp;

--4.6
SELECT * FROM emp ORDER BY ename ASC;

--4.7
CREATE TABLE mgr AS(SELECT * FROM emp WHERE job IN('MGR','A.MGR','GM'));
SELECT * FROM mgr;

--4.8
SELECT ename, dept_no FROM emp;

--4.9
SELECT * FROM emp WHERE mgr_id='1';

--4.10
SELECT * FROM emp WHERE ename LIKE 'M%';
SELECT * FROM emp WHERE ename LIKE 'R%';

--4.11
SELECT * FROM emp WHERE ename NOT LIKE 'S%';

--4.12
SELECT DISTINCT job FROM emp;