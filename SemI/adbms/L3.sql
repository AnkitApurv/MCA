--3.1
INSERT INTO dept VALUES ('D1', 'Marketing', 'CHN');
INSERT INTO dept VALUES ('D2', 'Research', 'MNG');
INSERT INTO dept VALUES ('D3', 'Administrator', 'BNG');
--                             *
--ERROR at line 1:
--ORA-12899: value too large for column "MCA9042"."DEPT"."DNAME" (actual: 13, maximum: 10)
INSERT INTO dept VALUES ('D4', 'HR', 'BGG');
--*
--ERROR at line 1:
--ORA-02290: check constraint (MCA9042.LOCATION) violated
INSERT INTO dept VALUES ('D5', 'IT', 'BNG');
INSERT INTO dept VALUES (null, 'Corporate', 'HYD');
--                       *
--ERROR at line 1:
--ORA-01400: cannot insert NULL into ("MCA9042"."DEPT"."DNO")
INSERT INTO dept VALUES ('D3', 'Admin', 'BNG');
INSERT INTO dept VALUES ('D4', 'HR', 'BNG');



--3.2
INSERT INTO proj VALUES ('D1', 'P1', 'ab', 2, TO_DATE('10-10-2006','DD-MM-YYYY'), TO_DATE('10-10-2007','DD-MM-YYYY'));
INSERT INTO proj VALUES ('D2', 'P1', 'cd', 2, TO_DATE('01-10-2007','DD-MM-YYYY'), TO_DATE('10-10-2007','DD-MM-YYYY'));
INSERT INTO proj VALUES ('D3', 'P2', 'ef', 7, TO_DATE('10-10-2007','DD-MM-YYYY'), TO_DATE('10-10-2017','DD-MM-YYYY'));
INSERT INTO proj VALUES ('D1', 'P3', 'gh', 5, TO_DATE('10-01-2007','DD-MM-YYYY'), TO_DATE('10-10-2007','DD-MM-YYYY'));
INSERT INTO proj VALUES ('D4', 'P2', 'ij', 7, TO_DATE('10-10-2017','DD-MM-YYYY'), TO_DATE('10-10-2018','DD-MM-YYYY'));
INSERT INTO proj VALUES ('D3', 'P2', 'kl', 2);
--          *
--ERROR at line 1:
--ORA-00947: not enough values
INSERT INTO proj VALUES ('D2', 'P3', 'mn', 2);
--          *
--ERROR at line 1:
--ORA-00947: not enough values



--3.3
INSERT INTO emp VALUES (100, 'Ravi', 'MGR', 111, TO_DATE('10-10-1985','DD-MM-YYYY'), 32000, 16000, 'D1', TO_DATE('02-10-2001','DD-MM-YYYY'), 'P1');
--                      *
--ERROR at line 1:
--ORA-02290: check constraint (MCA9042.EMPNO_LESS_THEN_100) violated
INSERT INTO emp VALUES (01, 'Ravi', 'MGR', 11, TO_DATE('10-10-1985','DD-MM-YYYY'), 32000, 16000, 'D1', TO_DATE('02-10-2001','DD-MM-YYYY'), 'P1');
--                                         *
--ERROR at line 1:
--ORA-02291: integrity constraint (MCA9042.SYS_C0032805) violated - parent key
--not found
INSERT INTO emp VALUES (03, 'Vishal', 'CLRK', 11, TO_DATE('02-10-1980','DD-MM-YYYY'), 20000, 16000, 'D1', TO_DATE('02-10-2002','DD-MM-YYYY'), 'P3');
--                                                                                     *
--ERROR at line 1:
--ORA-02290: check constraint (MCA9042.SALARY_CEILING) violated
INSERT INTO emp VALUES (06, 'Vishal', 'MGR', 01, TO_DATE('02-10-1986','DD-MM-YYYY'), 21000, 16000, 'D2', TO_DATE('02-10-1985','DD-MM-YYYY'), 'P3');
--*
--ERROR at line 1:
--ORA-02290: check constraint (MCA9042.LOGICAL_DOB_LESS_THAN_DOJ) violated
INSERT INTO emp VALUES (23, 'Mahesh', 'CLRK', 06, TO_DATE('10-12-1974','DD-MM-YYYY'), 25000, 16000, 'D3', TO_DATE('02-10-2002','DD-MM-YYYY'), 'P2');
--                                            *
--ERROR at line 1:
--ORA-02291: integrity constraint (MCA9042.SYS_C0032805) violated - parent key not found

INSERT INTO emp VALUES (08, 'Vishal', 'CLRK', 25, TO_DATE('10-12-1970','DD-MM-YYYY'), 21000, 16000, 'D9', TO_DATE('02-10-1985','DD-MM-YYYY'), 'P1');
--                                                                                                   *
--ERROR at line 1:
--ORA-02291: integrity constraint (MCA9042.FK_EMP_PROJ) violated - parent key not found

INSERT INTO emp VALUES (null, 'Vishal', 'CLRK', 06, TO_DATE('10-12-1980','DD-MM-YYYY'), 23000, 16000, 'D1', TO_DATE('02-10-1980','DD-MM-YYYY'), 'P1');
--                      *
--ERROR at line 1:
--ORA-01400: cannot insert NULL into ("MCA9042"."EMP"."EMPNO")
INSERT INTO emp VALUES (04, 'Vishal', 'CLERK', 01, TO_DATE('02-10-1980','DD-MM-YYYY'), 25000, 16000, 'D2', TO_DATE('02-10-2005','DD-MM-YYYY'), 'P1');
--                                     *
--ERROR at line 1:
--ORA-02290: check constraint (MCA9042.JOB_TITLE) violated
INSERT INTO emp VALUES (03, 'Vishal', 'A.CLRK', 11, TO_DATE('10-12-1980','DD-MM-YYYY'), 20000, 16000, 'D1', TO_DATE('02-10-2001','DD-MM-YYYY'), 'P1');
--                                     *
--ERROR at line 1:
--ORA-02290: check constraint (MCA9042.JOB_TITLE) violated

--inserted
INSERT INTO emp VALUES (50, 'Aman', 'CEO', null, TO_DATE('10-12-1970','DD-MM-YYYY'), 60000, 30000, null, TO_DATE('03-12-1990','DD-MM-YYYY'), null);
INSERT INTO emp VALUES (11, 'Raghu', 'GM', 50, TO_DATE('10-12-1974','DD-MM-YYYY'), 45000, 15000, null, TO_DATE('03-11-1985','DD-MM-YYYY'), null);
INSERT INTO emp VALUES (01, 'Ravi', 'MGR', 11, TO_DATE('10-10-1985','DD-MM-YYYY'), 32000, 16000, 'D1', TO_DATE('02-10-2001','DD-MM-YYYY'), 'P1');
INSERT INTO emp VALUES (25, 'Manu', 'A.MGR', 50, TO_DATE('10-12-1980','DD-MM-YYYY'), 40000, 16000, 'D4', TO_DATE('02-10-2002','DD-MM-YYYY'), 'P2');
INSERT INTO emp VALUES (02, 'Raviraj', 'CLRK', 01, TO_DATE('10-12-1980','DD-MM-YYYY'), 24000, 12000, 'D1', TO_DATE('12-11-2000','DD-MM-YYYY'), 'P3');
INSERT INTO emp VALUES (03, 'Vishal', 'CLRK', 11, TO_DATE('10-12-1980','DD-MM-YYYY'), 21000, 16000, 'D1', TO_DATE('02-10-2001','DD-MM-YYYY'), 'P3');



--3.4
commit;
DELETE FROM emp WHERE prj_id='P2';
--1 row deleted.
rollback;



--3.5
commit;
SELECT dno FROM dept WHERE dname='Marketing';
--D1
DELETE FROM emp WHERE dept_no='D1';
--1 row deleted
DELETE FROM proj WHERE dno='D1';
--2 rows deleted
DELETE FROM dept WHERE dname='Marketing';
--1 row deleted
rollback;
--rollback complete
--*
--ERROR at line 1:
--ORA-02292: integrity constraint (MCA9042.SYS_C0032670) violated - child record found


--3.6
DELETE FROM emp WHERE mgr_id=01 AND prj_id='P1';
--0 rows deleted.


--3.7
SELECT dno FROM proj WHERE ROWNUM <=1;
--D1
UPDATE emp SET dept_no='D5' WHERE dept_no='D1';
--ORA-02291: integrity constraint (MCA9042.FK_EMP_PROJ) violated - parent key not found
UPDATE proj SET dno='D5' WHERE ROWNUM <=1;
--ORA-02292: integrity constraint (MCA9042.FK_EMP_PROJ) violated - child record found

--3.8
UPDATE emp SET job='MGR', sal=35000, mgr_id=11 WHERE empno=23;
--0 rows updated


--3.9
--ALTER TABLE emp MODIFY comm DEFAULT 10000 WHERE job='MGR';
--it is not a default value constraint, only a value update
UPDATE emp SET comm=10000 WHERE job='MGR';
--1 row updated.