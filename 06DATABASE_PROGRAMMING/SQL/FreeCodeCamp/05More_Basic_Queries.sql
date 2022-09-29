-- Find all employees ordered by sex and then name
SELECT * 
FROM employee
ORDER BY sex, first_name, last_name;

-- Find the first 5 employees in the table
SELECT * 
FROM employee
LIMIT 5;

-- Find the first and last names of all employees
SELECT first_name, last_name
FROM employee;

-- Find the forename and surname of all employees
SELECT first_name AS forename, last_name AS surname
FROM employee;

-- Find out all the different genders
SELECT DISTINCT sex
FROM employee;

-- Find out all the different branch id
SELECT DISTINCT branch_id
FROM employee;


