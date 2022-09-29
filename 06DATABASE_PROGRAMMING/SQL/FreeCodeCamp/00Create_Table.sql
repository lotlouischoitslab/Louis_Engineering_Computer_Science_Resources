-- INT Whole Numbers
-- DECIMAL(10,4) Decimal Numbers Exact Value
-- VARCHAR(100)  String of text of length 1
-- BLOB Binary Large Object, Stores large data
-- DATA YYYY-MM-DD
-- TIMESTAMP YYYY-MM-DD HH:MM:SS used for recording
CREATE TABLE student(
	student_id INT,
    name VARCHAR(20),
    major VARCHAR(20),
    PRIMARY KEY(student_id)
);

DESCRIBE student;

DROP TABLE student; -- drops the table

ALTER TABLE student ADD gpa DECIMAL(3,2); -- 3 digits, 2 decimals after the point

ALTER TABLE student DROP COLUMN gpa; 