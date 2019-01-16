--Write a procedure to calculate simple interest, taking principle, rate and year as inputs. 
CREATE OR REPLACE PROCEDURE intrest_calc (principle IN NUMBER, rate IN NUMBER, duration IN NUMBER, intrest OUT NUMBER) IS
BEGIN
	intrest := (principle * rate * duration) / 100;
END;
/