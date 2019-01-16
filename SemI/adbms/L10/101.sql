declare
	v_tosses INTEGER := &v_tosses;
	v_head integer := &v_head;
	v_prob number;
begin
	v_prob := v_head/v_tosses;
	DBMS_OUTPUT.PUT_LINE('Probability is : ' || v_prob);
	EXCEPTION
		WHEN ZERO_DIVIDE THEN
			DBMS_OUTPUT.PUT_LINE('Number of coin tosses can''t be zero!');
END;
/