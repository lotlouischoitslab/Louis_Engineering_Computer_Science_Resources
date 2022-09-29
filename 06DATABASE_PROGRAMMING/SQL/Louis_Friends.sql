CREATE TABLE Louis_Friends(
	student_id INT AUTO_INCREMENT,
    name VARCHAR(1000),
    age INT,
    major VARCHAR(1000) DEFAULT 'Undecided',
    minor VARCHAR(1000) DEFAULT 'None',
    PRIMARY KEY(student_id)
);

DESCRIBE Louis_Friends;
DROP TABLE Louis_Friends; -- drops the table Louis Friends

INSERT INTO Louis_Friends(name,age,major,minor) VALUES('Louis Sungwoo Cho',21,'Civil and Environmental Engineering','Computer Science');
INSERT INTO Louis_Friends(name,age,major) VALUES('Juyoung Choi',21,'Computer Science + Astronomy');
INSERT INTO Louis_Friends(name,age,major) VALUES('Hakyung Peter Yun',21,'Computer Engineering');
INSERT INTO Louis_Friends(name,age,major) VALUES('Sangyun Lee',21,'Computer Engineering');
SELECT * FROM Louis_Friends; 


UPDATE Louis_Friends 
SET major = 'CEE'
WHERE major = 'Civil and Environmental Engineering';

UPDATE Louis_Friends 
SET major = 'CS+Astro'
WHERE major = 'Computer Science + Astronomy';

UPDATE Louis_Friends 
SET major = 'CompE'
WHERE major = 'Computer Engineering';

SELECT * FROM student_id NATURAL JOIN major;