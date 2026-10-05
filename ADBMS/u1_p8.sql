Create table customer (

    cust_id int primary key,
    cust_name varchar(50),
    cust_addr varchar(255),
    cust_city varchar(255),
    email_id varchar(50),
    contact_no bigint
);

CREATE TABLE magazine(
    mag_id int PRIMARY KEY,
    mag_name varchar(100),
    unit_rate float,
    type_of_subsciption varchar(50)
    
    );

CREATE TABLE subscription(
    cust_id int,
    mag_id int,
    start_date date,
    end_date date,
    
    FOREIGN KEY (cust_id) REFERENCES customer(cust_id),
    FOREIGN KEY (mag_id) REFERENCES magazine(mag_id)
    
    );



INSERT INTO Customer (Cust_Id, Cust_Name, Cust_Addr, Cust_City, EmailID, Contact_No) VALUES 
(1, 'Siddhraj solanki', 'Sector 21', 'Gandhinagar', 'siddhraj@email.com', '9876543210'),
(2, 'Veer patel', 'C.G. Road', 'Ahmedabad', 'veer@email.com', '9876543211'),
(3, 'Dhrumil mehra', 'Sector 7', 'Gandhinagar', 'dhrumil@email.com', '9876543212'),
(4, 'Priyanshu parmar', 'Infocity', 'Gandhinagar', 'priyanshu@email.com', '9876543213'),
(5, 'Harsh rohit', 'Koba Circle', 'Gandhinagar', 'harsh@email.com', '9876543214'),
(6, 'Yash gohil', 'Vastrapur', 'Ahmedabad', 'yash@email.com', '9876543215'),
(7, 'Kishan marwadi ', 'Sector 28', 'Gandhinagar', 'kishan@email.com', '9876543216'),
(8, 'Siddharaj dabhi', 'Alkapuri', 'Vadodara', 'siddharaj@email.com', '9876543217'),
(9, 'Kush patel', 'Race Course', 'Rajkot', 'kush@email.com', '9876543218'),
(10, 'Vedant Gogari', 'Sector 11', 'Gandhinagar', 'vedant@email.com', '9876543219');


INSERT INTO Magazine (Mag_Id, Mag_Name, Unit_Rate, Type_of_subscription) VALUES 
(101, 'Outlook', 150.00, 'monthly'),
(102, 'India Today', 50.00, 'weekly'),
(103, 'The Economist', 500.00, 'monthly'),
(104, 'Business Today', 120.00, 'monthly'),
(105, 'Forbes', 250.00, 'monthly'),
(106, 'Time Magazine', 400.00, 'weekly'),
(107, 'National Geographic', 300.00, 'monthly'),
(108, 'Reader Digest', 90.00, 'monthly'),
(109, 'Sports Illustrated', 180.00, 'monthly'),
(110, 'Digit', 110.00, 'monthly');


INSERT INTO Subscription (Cust_Id, Mag_Id, start_date, end_date) VALUES 

(1, 101, '2010-09-15', '2011-09-15'), 
(3, 101, '2010-11-20', '2011-11-20'), 
(7, 101, '2011-01-05', '2012-01-05'), 
(2, 101, '2010-10-01', '2011-10-01'), 
(4, 102, '2010-12-05', '2011-06-05'), 
(5, 103, '2011-01-10', '2012-01-10'), 
(6, 106, '2010-09-25', '2011-09-25'), 
(1, 102, CURRENT_DATE - INTERVAL '5' DAY, CURRENT_DATE + INTERVAL '175' DAY),
(2, 102, CURRENT_DATE - INTERVAL '10' DAY, CURRENT_DATE + INTERVAL '170' DAY),
(8, 102, CURRENT_DATE - INTERVAL '3' DAY, CURRENT_DATE + INTERVAL '177' DAY),
(3, 103, CURRENT_DATE - INTERVAL '12' DAY, CURRENT_DATE + INTERVAL '348' DAY),
(9, 103, CURRENT_DATE - INTERVAL '2' DAY, CURRENT_DATE + INTERVAL '358' DAY),  
(4, 104, CURRENT_DATE - INTERVAL '8' DAY, CURRENT_DATE + INTERVAL '352' DAY),  
(5, 105, CURRENT_DATE - INTERVAL '15' DAY, CURRENT_DATE + INTERVAL '350' DAY), 
(10, 107, '2012-05-20', '2013-05-20');


-- 1.
CREATE  VIEW view1 as 
	SELECT c.cust_name, m.mag_name, m.unit_rate,s.start_date FROM subscription s
    JOIN customer c ON c.cust_id = s.cust_id
    JOIN magazine m on m.mag_id = s.mag_id
    WHERE s.start_date BETWEEN '2010-10-01' AND '2011-02-01'
    
    -- display created view
    SELECT * FROM view1


-- 2.
SELECT m.mag_name, s.start_date, COUNT(s.mag_id) as highest_sale FROM subscription s
JOIN magazine m ON m.mag_id = s.mag_id
WHERE s.start_date BETWEEN CURRENT_DATE - INTERVAL '01' month AND CURRENT_DATE
GROUP BY s.mag_id 


-- 3.
DELIMITER //
CREATE or REPLACE FUNCTION func1()
RETURNS INT
BEGIN
  DECLARE cust_count INT;
  SELECT COUNT(s.cust_id)
  INTO cust_count
  FROM subscription s
	JOIN customer c ON c.cust_id = s.cust_id
	JOIN magazine m ON m.mag_id = s.mag_id

WHERE c.cust_city = "Gandhinagar" AND s.start_date > '2010-08-01' AND m.mag_name = "Outlook";
  RETURN cust_count;
END; //
DELIMITER ;

SELECT func1();


-- 4.