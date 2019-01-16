--Write a PL/SQL block trigger to do INSERT/UPDATE/DELETE operation only during week days.
--Raise an exception if the day is SAT or SUN and also display user who initiated operation.
set serveroutput on
create or replace trigger emp_day_off
before insert or update or delete on emp
begin
	if to_char(sysdate,'DY') = 'SUN' or to_char(sysdate,'DY') = 'SAT' then
	raise_application_error(-20111,'No changes can be made on saturday or sunday.' || user);
	end if;
end;
/