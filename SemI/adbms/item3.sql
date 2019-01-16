set serveroutput on
DECLARE
	itemno item3.itemno%type:=&itemno;
	qty_sold number(8):=&qty_sold;
	price item3.price%type:=price;
	qty_available item3.qty_available%type:=aty_available;
	net_amount number(8);
BEGIN
	qty_available:=qty_available-qty_sold;
	net_amount:=qty_sold*price;
	dbms_output.put_line('quantity avilable now:'||qty_available);
	dbms_output.put_line('net amount now:'||net_amount);
END
/