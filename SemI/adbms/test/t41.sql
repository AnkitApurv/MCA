CREATE table Policy (
Policy_no Varchar2(10) primary key,
premium number(7),
customer_id varchar2(10),
status char(1),
pending_premium number(1));

insert into Policy (Policy_no, premium, customer_id, pending_premium) values ('LIC_111', 10000, 'Cust_100', 1);
insert into Policy (Policy_no, premium, customer_id, pending_premium) values ('LIC_112', 15000, 'Cust_101', 2);



insert into Policy (Policy_no, premium, customer_id, pending_premium) values ('LIC_114', 10000, 'Cust_102', 1);
insert into Policy (Policy_no, premium, customer_id, pending_premium) values ('LIC_115', 15000, 'Cust_103', 2);

insert into Policy (Policy_no, premium, customer_id, pending_premium) values ('LIC_118', 15000, 'Cust_101', 2);