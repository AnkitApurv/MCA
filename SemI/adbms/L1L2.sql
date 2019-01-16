 'RECTIFIED'
 CREATE TABLE EMP(
 EMPNO NUMBER(4),
 ENAME VARCHAR2(10),
 JOB VARCHAR2(9) DEFAULT 'CLRK' CONSTRAINT JOB_TITLE CHECK(JOB IN('CLRK','MGR','A.MGR','GM','CEO')),
 MGR_ID NUMBER(4),
 DATE_BIRTH DATE,
 SAL NUMBER(7,2) DEFAULT 20001 CONSTRAINT SALARY_CEILING CHECK(SAL>20000),
 COMM NUMBER(7,2) DEFAULT 1000,
 DEPT_NO VARCHAR2(3),
 DATE_OF_JOIN DATE,
 CONSTRAINT LOGICAL_DOB_LESS_THAN_DOJ CHECK(DATE_BIRTH<DATE_OF_JOIN));
 
 'PKEY AND REFERENCE'
 'DONE'
 ALTER TABLE EMP ADD CONSTRAINT EMP_PKEY PRIMARY KEY(EMPNO);
 'DONE'
 ALTER TABLE EMP MODIFY DEPT_NO REFERENCES DEPT(DNO) ON DELETE CASCADE;
 'DONE'
 ALTER TABLE EMP MODIFY MGR_ID REFERENCES EMP(EMPNO);
 
 'CREATED'
 CREATE TABLE DEPT(
 DNO VARCHAR2(3) PRIMARY KEY CONSTRAINT DNO_START_WITH_S CHECK(DNO LIKE 'D%'),
 DNAME VARCHAR2(10) UNIQUE,
 LOCATION VARCHAR2(9) DEFAULT 'BNG' CONSTRAINT LOCATION CHECK(LOCATION IN('BNG','MNG','MUB','HYD','CHN'))); 'CREATED'
 
 'CREATED'
 CREATE TABLE PROJ(
 DNO VARCHAR2(3) NOT NULL REFERENCES DEPT(DNO),
 PRJ_NO VARCHAR2(5) NOT NULL CONSTRAINT PRJ_NO_START_WITH_P CHECK(PRJ_NO LIKE 'P%'),
 PRJ_NAME VARCHAR2(10),
 PRJ_CREDITS NUMBER(2) CONSTRAINT PRJ_CREDITS_LIMITS CHECK(PRJ_CREDITS>0 AND PRJ_CREDITS<11),
 STRT_DATE DATE,
 END_DATE DATE,
 CONSTRAINT STRT_DATE_BRFORE_END_DATE CHECK(END_DATE>STRT_DATE));
 
 '2.1 DONE'
 ALTER TABLE PROJ ADD CONSTRAINT PROJ_PKEY PRIMARY KEY(DNO, PRJ_NO);
 
 '2.2 DONE'
 ALTER TABLE EMP ADD(PRJ_ID VARCHAR2(5));
 ALTER TABLE EMP ADD CONSTRAINT FK_EMP_PROJ FOREIGN KEY(DEPT_NO, PRJ_ID) REFERENCES PROJ(DNO, PRJ_NO);
 
 '2.3 DONE'
 ALTER TABLE EMP ADD CONSTRAINT EMPNO_LESS_THEN_100 CHECK(EMPNO<100);