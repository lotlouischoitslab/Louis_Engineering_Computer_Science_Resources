-- Find a list of employees and branch names
SELECT first_name AS Company_Names
FROM employee
UNION
SELECT branch_name
FROM branch
UNION 
SELECT client_name
FROM client;

-- Find a list of all clients & branch suppliers names:
SELECT client_name, branch_id
FROM client
UNION
SELECT supplier_name, branch_id
FROM branch_supplier;

-- Find a list of all money spent on earned by the company
SELECT salary
FROM employee
UNION
SELECT total_sales
FROM works_with;
