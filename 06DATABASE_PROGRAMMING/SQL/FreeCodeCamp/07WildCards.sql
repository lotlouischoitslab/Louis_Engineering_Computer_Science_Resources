-- % any # characters one character

-- Find any client who are LLC

SELECT *
FROM client
WHERE client_name LIKE '%LLC';

-- Find any branch suppliers who are in the label business
SELECT *
FROM branch_supplier
WHERE supplier_name LIKE '% Label%';

-- Find any employee born in October
SELECT *
FROM employee
WHERE birth_day LIKE '%____-10%';

-- Find any clients who are schools
SELECT * 
FROM client
WHERE client_name LIKE '%school%';

SELECT * FROM employee