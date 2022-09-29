SELECT * FROM student;

SELECT student.name, student.major
FROM student
ORDER BY student_id DESC; 

SELECT *
FROM student
ORDER BY student_id ASC; 
SELECT *
FROM student
LIMIT 2;

SELECT name,major
FROM student
WHERE major='Chemistry' OR major = 'Biology';

-- <,>,<=,>=,=,<>,AND,OR