CREATE TABLE branch (
	branch_id INT PRIMARY KEY,
    branch_name VARCHAR(40),
    mgr_id INT,
    mgr_start_date DATE,
    FOREIGN KEY(mgr_id) REFERENCES employee(emp_id) ON DELETE SET NULL
);

DELETE FROM employee
WHERE emp_id = 102;

SELECT * FROM branch;

CREATE TABLE branch_supplier (
	branch_id INT,
    supplier_name VARCHAR(40),
    supply_type VARCHAR(40),
    FOREIGN KEY(branch_id) REFERENCES branch(branch_id) ON DELETE SET NULL
);

DELETE FROM branch
WHERE branch_id = 2;

SELECT * FROM branch_supplier;