--1 done
CREATE TABLE Doctor (
DocId CHAR(4) PRIMARY KEY CONSTRAINT "Start_With_D" CHECK(DocId LIKE 'D%'),
DocName VARCHAR2(25) UNIQUE,
Speciality CHAR(10) CONSTRAINT "Valid_Speciality" CHECK(Speciality IN('Skin', 'Ortho', 'Cardio')),
Fees NUMBER(5, 2),
CONSTRAINT "Fees_Floor" CHECK(Fees>149),
CONSTRAINT "Fees_Ceiling" CHECK(Fees<501));

CREATE TABLE Patient (
Patient_No NUMBER(5, 0) PRIMARY KEY,
Patient_Name VARCHAR2(20),
State VARCHAR2(25),
DocId CONSTRAINT "FK_DocId" REFERENCES Doctor(DocId) );


--2 done
ALTER TABLE Patient ADD Mobile_No NUMBER(10, 0);
ALTER TABLE Patient ADD CONSTRAINT "Valid_Mobile_No" CHECK(Mobile_No>999999999);


--3 done
INSERT INTO Doctor VALUES('D001', 'ABC', 'Skin', 250);
INSERT INTO Doctor VALUES('D002', 'DEF', 'Ortho', 400);

INSERT INTO Patient VALUES('100', 'QWE', 'H', 'D001', 9123456789);
INSERT INTO Patient VALUES('101', 'ZXC', 'V', 'D002', 9234567890);


--4 could not
UPDATE Doctor SET Fees=300 WHERE Doc_Id='D001';