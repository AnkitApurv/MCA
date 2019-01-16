--student(regno, m1, m2. avg, grade);

--create table student(
--regno number(3) primary key,
--m1 number(2),
--m2 number(2),
--avg number(2, 1),
--grade char(2));

--INSERT INTO STUDENT (regno, m1 ,m2) VALUES (1, 87, 93);
--INSERT INTO STUDENT (regno, m1 ,m2) VALUES (2, 77, 84);
--INSERT INTO STUDENT (regno, m1 ,m2) VALUES (3, 79, 68);

--pl/sql block to accept regno from user and process his avg marks and grade


alter table student modify avg number(3, 1);

create table circle(
radius number(3, 2),
area number(9, 2));