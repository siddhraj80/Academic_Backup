CREATE DATABASE IF NOT EXISTS u1_p7;
use u1_p7;

Create table applicant (

    aid  varchar(11) primary key,
    aname varchar(25),
    address varchar(50),
    abirth_dt date
);

Create table entrance_test (
    
    etid int primary key,
    etname varchar(30), 
    max_score int,
    cut_score int
);

Create table etest_centre (
    
    etcid int primary key,
    location varchar(30),
    incharge varchar(30),
    capacity int
);

Create table etest_details (
    
    aid varchar(11),
    etid int,
    etcid int,
    etest_dt date,
    score int,

  foreign key(aid) references  applicant(aid),
  foreign key(etid) references entrance_test(etid),
  foreign key(etcid) references etest_centre(etcid)
);

INSERT INTO applicant (aid, aname, address, abirth_dt) VALUES
	(1123, 'siddhraj', 'Andheri, Mumbai', '2000-05-15'),
	(1124, 'kush', 'Bandra, Mumbai', '2001-08-22'),
	(1125, 'veer', 'Satellite, Ahmedabad', '1999-12-05'),
	(1126, 'Dhrumil', 'Borivali, Mumbai', '2002-01-30'),
	(1127, 'harsh', 'Thane, Mumbai', '2000-10-11'),
	(1128, 'Priyanshu', 'Navrangpura, Ahmedabad', '2001-03-14');

INSERT INTO entrance_test (etid, etname, max_score, cut_score) VALUES
	(1, 'Oracle Fundamentals', 100, 60),
	(2, 'Java SE Programming', 100, 65),
	(3, 'Web Development Basics', 100, 55);

INSERT INTO etest_centre (etcid, location, incharge, capacity) VALUES
	(101, 'Mumbai', 'Mr. R. K. Sharma', 3),
	(102, 'Ahmedabad', 'Ms. Sunita Patel', 10),
	(103, 'Pune', 'Mr. Anil Deshmukh', 5);


INSERT INTO etest_details (aid, etid, etcid, etest_dt, score) VALUES

	(1123, 1, 101, '2011-11-05', 85), 
	(1123, 2, 101, '2011-11-12', 78),
	(1124, 1, 101, '2011-11-05', 85), 
	(1124, 2, 101, '2011-11-12', 92),
	(1124, 3, 101, '2011-11-14', 80), 
	(1125, 1, 102, '2011-11-06', 70),
	(1125, 2, 102, '2011-11-13', 50), 
	(1126, 3, 101, '2011-11-05', 40), 
	(1127, 1, 102, '2011-11-06', 75),
	(1128, 1, 102, '2011-11-07', 90),
	(1128, 2, 102, '2011-11-14', 88),
    (1128, 3, 102, '2011-11-15', 95);


/* 1.Modify the APPLICANT table so that every applicant 
   idhasan‘A’beforeitsvalue.For example,
  if the applicant id ‘1123’, it should now become ‘A1123’. */

ALTER TABLE etest_details DROP FOREIGN KEY etest_details_ibfk_1;

UPDATE applicant set aid = CONCAT('A',aid);
UPDATE etest_details set aid = CONCAT('A',aid);

ALTER TABLE etest_details 
ADD CONSTRAINT etest_details_ibfk_1 
FOREIGN KEY (aid) REFERENCES applicant(aid);

-- 2.Display the test center details where no tests will be conducted.

SELECT * from etest_centre
WHERE etcid NOT IN( SELECT etcid FROM etest_details);

/* 3.Display the details about applicants who have the same 
score as that of “Jaydev” in “Oracle Fundamentals”. */

SELECT a.* 
FROM applicant a
JOIN etest_details ed ON a.aid = ed.aid
WHERE ed.score = (
    SELECT ed2.score 
    FROM etest_details ed2
    JOIN applicant a2 ON ed2.aid = a2.aid
    JOIN entrance_test et2 ON ed2.etid = et2.etid
    WHERE a2.aname = 'jaydev' AND et2.etname = 'Oracle Fundamentals'
);

/* 4.Display the details of applicants who 
have appeared for all the tests.  */

SELECT et.etid, etd.aid,a.aname from etest_details  as etd 
JOIN applicant as a on etd.aid = a.aid
join entrance_test as et
	on et.etid = etd.etid 
    GROUP by etd.aid
    HAVING COUNT(etd.aid) = (SELECT COUNT(*) from entrance_test);

-- 5.Display those tests where no applicant has failed. 
SELECT * 
FROM entrance_test 
WHERE etid NOT IN (
    SELECT etd.etid 
    FROM etest_details etd
    JOIN entrance_test et ON etd.etid = et.etid
    WHERE etd.score < et.cut_score
);

/* 6.Display details of entrance test centers which had full 
attendance between 1stNovember and   
          15 November 2011. */

SELECT etc.* 
FROM ETEST_CENTRE etc
JOIN ETEST_DETAILS etd ON etc.etcid = etd.etcid
WHERE etd.etest_dt BETWEEN '2011-11-01' AND '2011-11-15'
GROUP BY etc.etcid, etc.location, etc.incharge, etc.capacity, etd.etest_dt
HAVING COUNT(DISTINCT etd.aid) = etc.capacity;

/* 7.Display the details of those applicants who have scored more 
than the cut-off score in the tests they have appeared in. */

SELECT etd.aid, a.aname, et.etid, etd.score, et.cut_score from etest_details as etd
JOIN applicant as a on etd.aid = a.aid
JOIN entrance_test as et ON etd.etid = et.etid
HAVING (etd.score > et.cut_score);

/* 8.Display the average and the maximum score, test wise of 
the tests conducted at Mumbai. */

SELECT test.etname as Test_Name,AVG(etd.score), MAX(etd.score),et.location FROM etest_details as etd
JOIN entrance_test as test on test.etid = etd.etid
join etest_centre as et on et.etcid = etd.etcid
GROUP by etd.etid
HAVING (et.location = "Mumbai");

/* 9.Display the number of 
applicants who have appeared for each test, test center wise.  */

SELECT ed.etid, et.etname, ed.etcid, ec.location, COUNT(DISTINCT ed.aid) AS applicant_count
FROM ETEST_DETAILS ed
JOIN ENTRANCE_TEST et ON ed.etid = et.etid
JOIN ETEST_CENTRE ec ON ed.etcid = ec.etcid
GROUP BY ed.etid, et.etname, ed.etcid, ec.location;