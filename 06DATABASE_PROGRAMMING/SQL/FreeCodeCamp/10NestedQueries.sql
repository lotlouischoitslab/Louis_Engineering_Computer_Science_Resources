-- Find names of all employees who have sold over 10,000 to a single client
SELECT employee.first_name, employee.last_name
FROM employee
WHERE employee.emp_id IN (
	SELECT works_with.emp_id
	FROM works_with
	WHERE works_with.total_sales > 30000
);

-- Find all clients who are handled by the branch
-- that Michael Scott wants to manage
-- Assume you know Michael's ID

-- WHen you are using something like a quality, good idea to limit down to 1
SELECT client.client_name
FROM client
WHERE client.client_branch_id = (
	SELECT branch.branch_id
	FROM branch
	WHERE branch.mgr_id = 102 -- Not guaranteed to return 1 value
	LIMIT 1 -- make this a limit
);

SELECT * FROM client



