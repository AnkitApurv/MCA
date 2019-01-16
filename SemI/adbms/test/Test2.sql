CREATE TABLE Customer(
custno VARCHAR2(2) PRIMARY KEY,
cname VARCHAR2(7),
city VARCHAR2(7));

Create table order1(
orderno varchar2(2) primary key,
orderdate date,
custno varchar2(2) not null,
itemno varchar2(2),
qty number(3, 0));

create table item(
itemno varchar(2) primary key,
itemname varchar(10),
unitprice number(30));

insert into customer values('C1', 'Anu', 'Mumbai');
insert into customer values('C2', 'k', 'Mumbai');
insert into customer values('C3', 'w', 'Mumbai');

insert into order1 values('O1', TO_DATE('02-09-18', 'DD-MM-YY'), 'C3', 'I1', 10);
insert into order1 values('O2', to_DATE('01-07-18', 'DD-MM-YY'), 'C1', 'I2', 5);
insert into order1 values('O3', to_DATE('01-08-18', 'DD-MM-YY'), 'C1', 'I1', 1);

INSERT INTO ITEM VALUES('I1', 'Pen', 70);
INSERT INTO ITEM VALUES('I2', 'Wallet', 89);
INSERT INTO ITEM VALUES('I3', 'Notebook', 78);



--1 
SELECT orderno, orderdate FROM order1 WHERE custno IN(SELECT custno FROM CUSTOMER where CITY = 'Mumbai');
---
OR ORDERDATE
-- ---------
O1 02-SEP-18
O2 01-JUL-18
O3 01-AUG-18
---



--2
SELECT custno from ORDER1 WHERE SUBSTR(TO_CHAR(orderdate, 'DD-MM-YY'), 5, 1) = 9;
---
CU
--
C3
---



--3
--display details of customers who have placed >1 orders from 1-07-18 to 01-09-18
select * from customer where custno IN(select custno from order1 where orderdate between TO_DATE('01-07-18', 'DD-MM-YY') AND TO_DATE('01-09-2018', 'DD-MM-YY'));
select * from customer where custno IN(select custno from order1 where orderdate between TO_DATE('01-07-18', 'DD-MM-YY') AND TO_DATE('01-09-2018', 'DD-MM-YY') having count(orderno) > 1);
--select * from customer where custno IN(select custno from order1 where count(orderno) > 1 AND orderdate between TO_DATE('01-07-18', 'DD-MM-YY') AND TO_DATE('01-09-2018', 'DD-MM-YY'));
--SELECT CUSTOMER.CUSTID, CNAME, CITY, orderno FROM CUSTOMER, ORDER1 WHERE ORDER1.orderdate between TO_DATE('01-07-18', 'DD-MM-YY') AND TO_DATE('01-09-2018', 'DD-MM-YY');
--SELECT CUSTOMER.CUSTID, CNAME, CITY, orderno FROM CUSTOMER, ORDER1 WHERE count(ORDER1.orderno) > 1 AND ORDER1.orderdate between TO_DATE('01-07-18', 'DD-MM-YY') AND TO_DATE('01-09-2018', 'DD-MM-YY');
---GROUP BY NOT ALLOWED ERROR -- COUNT()
CU CNAME   CITY
-- ------- -------
C1 Anu     Mumbai
---



--4
select * from ORDER1 Where itemno = 'I1' AND qty >= 5;
---
OR ORDERDATE CU IT        QTY
-- --------- -- -- ----------
O1 02-SEP-18 C3 I1         10
---