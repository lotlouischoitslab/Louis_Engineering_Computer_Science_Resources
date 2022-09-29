SELECT * FROM student;

UPDATE student 
SET major = 'Bio'
WHERE major = 'Biology';

UPDATE student 
SET major = 'CS'
WHERE major = 'Computer Science';

UPDATE student 
SET major = 'Chemistry'
WHERE major = 'Undecided';

DELETE FROM student
WHERE student_id = 5;
