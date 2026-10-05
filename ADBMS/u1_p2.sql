    use u1_p2;

create table student (
	roll_no int primary key,
    name varchar(25) not null,
    class varchar(20) not null,
    birthdate date not null
    );
    
create table course (
	course_no int primary key,
    course_name varchar(35) not null,
    max_marks int not null,
    pass_marks int not null
    );

create table sc (
	roll_no int ,
    course_no int,
    marks int not null,
    
    foreign key (roll_no) references student(roll_no),
    foreign key (course_no) references course(course_no)
    );
    
INSERT INTO student VALUES
(101, 'siddhraj', 'MCA-I', '1980-01-15'),
(102, 'veer', 'MCA-I', '1982-02-22'),
(103, 'dhrumil', 'MCA-I', '1981-03-10'),
(104, 'priyanshu', 'MCA-II', '1982-04-05'),
(105, 'kavya', 'MCA-II','1983-05-18'),
(106, 'harsh', 'MCA-I', '1980-06-25'),
(107, 'kush', 'MCA-II','1984-02-12'),
(108, 'yash', 'MCA-I','1982-08-30');

INSERT INTO course VALUES
(201, 'Database Management System', 100, 40),
(202, 'Java Programming', 100, 35),
(203, 'Python Programming', 100, 35),
(204, 'Computer Networks', 100, 40),
(205, 'Operating System', 100, 35),
(206, 'Web Technology', 100, 35),
(207, 'Data Structures', 100, 40),
(208, 'Software Engineering', 100, 45);

INSERT INTO sc VALUES
(101, 201, 78),
(101, 202, 85),
(102, 201, 92),
(102, 203, 88),
(103, 201, 65),
(103, 204, 72),
(104, 202, 76),
(104, 205, 81),
(105, 203, 69),
(105, 206, 74),
(106, 201, 83),
(106, 207, 91),
(107, 202, 87),
(107, 208, 79),
(108, 201, 71),
(108, 205, 84);

--add a constraint that the marks entered should be strickly between 0 and 100.
ALTER TABLE sc
ADD CONSTRAINT marks
CHECK (marks > 0 AND marks < 100);

--Display details of students who take the ‘Database Management System’ course. 
SELECT st.*,c.course_name
FROM student st
JOIN sc s
	ON st.roll_no = s.roll_no
JOIN course c
	ON c.course_no = s.course_no
WHERE c.course_name = 'Database Management System';

--Display the average marks obtained by each student.Select all courses where passing marks are more than 30% of average maximum mark. 
SELECT st.roll_no,
       st.name,
       AVG(sc.marks) AS average
FROM student st
JOIN sc
    ON st.roll_no = sc.roll_no
GROUP BY st.roll_no, st.name;

--Display details of students who were born in 1980 or 1982. 
SELECT *
FROM student
WHERE EXTRACT(YEAR FROM birthdate) IN (1980, 1982);

--Create a view that displays student courseno and its corresponding marks.  
CREATE VIEW Student_Course_Marks AS
SELECT roll_no,
       course_no,
       marks
FROM sc;

SELECT *
FROM Student_Course_Marks;