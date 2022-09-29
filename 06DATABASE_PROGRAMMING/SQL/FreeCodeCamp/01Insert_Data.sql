DROP TABLE student; -- drops the table
CREATE TABLE student(
	student_id INT AUTO_INCREMENT, 
    name VARCHAR(20),
    major VARCHAR(20) DEFAULT 'Undecided',
    PRIMARY KEY(student_id)
);

DESCRIBE student;
INSERT INTO student(name,major) VALUES('Jack','Biology');
INSERT INTO student(name,major) VALUES('Kate','Sociology');
INSERT INTO student(name) VALUES('Claire');
INSERT INTO student(name,major) VALUES('Jack','Biology');
INSERT INTO student(name,major) VALUES('Mike','Computer Science');
SELECT * FROM student; 