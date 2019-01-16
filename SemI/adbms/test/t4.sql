set serveroutput on
declare
v_p_no Policy.Policy_no%type;
v_c_no Policy.customer_id%type := '&v_c_no';
v_p Policy.premium%type;
v_pp Policy.pending_premium%type;
v_ppp number(10, 2);
CURSOR pol(v_c_no varchar2) IS select Policy_no, premium, pending_premium from POLICY where customer_id = v_c_no;
begin
open pol(v_c_no);
loop
	fetch pol into v_p_no, v_p, v_pp;
	v_ppp := v_p * v_pp;
	if v_pp < 2 then
		update Policy set status = 'g' where Policy_no = v_p_no;
	else
		update Policy set status = 'b' where Policy_no = v_p_no;
	end if;
	dbms_output.put_line('Dear ' || v_c_no || ' you have policy ' || v_p_no || ' having Rupees ' || v_ppp || '/- as dues');
exit when pol%notfound;
end loop;
close pol;
end;
/