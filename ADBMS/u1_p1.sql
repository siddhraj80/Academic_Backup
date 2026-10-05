use u1_p1;

create table cust(
	cust_no int primary key,
    cust_name varchar(25),
    addln1 varchar(30) not null,
    addln2 varchar(30) not null,
    city varchar(25) not null,
    state varchar(25) not null,
    phone bigint not null);
    
create table item (
	item_no int primary key,
	item_name varchar(25) not null,
    item_price double not null,
    qty_on_hand int not null);
    
create table invoice (
	inv_no int primary key,
    invdate date not null,
    cust_no int,
    
    foreign key (cust_no) references cust(cust_no) );
    
create table inv_item (
	inv_no int,
    item_no int,
    qty_used int not null,
    
    foreign key (inv_no) references invoice(inv_no),
    foreign key (item_no) references item(item_no));
    
INSERT INTO cust VALUES
(101, 'siddhraj', '12 MG Road', 'Near Bus Stand', 'Ahmedabad', 'Gujarat', '5463728910'),
(102, 'kavya', '25 Station Road', 'Near Railway Station', 'Baroda', 'Gujarat', '4637281905'),
(103, 'harsh', '45 Lalbaug Road', 'Near Market', 'Ahmedabad', 'Gujarat', '2856471956'),
(104, 'kush', '18 Main Road', 'Near Temple', 'Mumbai', 'Maharashtra', '8794563026'),
(105, 'veer', '32 Lalbaug', 'Near Garden', 'Ahmedabad', 'Gujarat', '7695403654'),
(106, 'dhrumil', '55 Alkapuri', 'Near Mall', 'Baroda', 'Gujarat', '6579463452'),
(107, 'priyanshu', '76 MG Road', 'Near College', 'Surat', 'Gujarat', '6708453657'),
(108, 'siddharaj', '22 Park Street', 'Near Hospital', 'Pune', 'Maharashtra', '8634565892');

INSERT INTO item VALUES
(201, 'Keyboard', 450.00, 50),
(202, 'Mouse', 250.00, 80),
(203, 'Monitor', 8500.00, 20),
(204, 'USB Cable', 150.00, 100),
(205, 'Headphones', 1200.00, 35),
(206, 'Webcam', 750.00, 25),
(207, 'Pen Drive', 500.00, 60),
(208, 'Laptop Stand', 350.00, 40);

INSERT INTO invoice VALUES
(301, '2026-07-01', 101),
(302, '2026-07-02', 102),
(303, '2026-07-03', 103),
(304, '2026-07-04', 104),
(305, '2026-07-05', 105),
(306, '2026-07-06', 106),
(307, '2026-07-07', 107),
(308, '2026-07-08', 108);

INSERT INTO inv_item VALUES
(301, 201, 2),
(302, 202, 3),
(303, 203, 1),
(304, 204, 5),
(305, 205, 2),
(306, 206, 4),
(307, 207, 3),
(308, 208, 2);

--add a column name -'colour' to the item table
ALTER TABLE item
ADD colour VARCHAR(20);

-- display item name and price in sentences form using concatention.
SELECT CONCAT(item_name, ' costs Rs. ', item_price) AS item_Details
FROM item;

--find the total value of each item (item_price * qty)
SELECT item_no,
       item_name,
       item_price,
       qty_on_hand,
       item_price * qty_on_hand AS Total_Value
FROM ITEM;

--customer belonging to gujarat state
SELECT *
FROM cust
WHERE state = 'Gujarat';

--display item with unit price between 100 and 500
SELECT *
FROM item
WHERE item_price BETWEEN 100 AND 500;

--find the customers from lalbaug city of ahmedabad and baroda
SELECT *
FROM cust
WHERE addln1 LIKE '%Lalbaug%'
  AND city IN ('Ahmedabad', 'Baroda');

--find all the customers whose name starts with the letter 'p'
SELECT *
FROM cust
WHERE cust_name LIKE 'p%';

--find the total, average, highest and lowest unit price of an item.
SELECT
    SUM(item_price) AS total,
    AVG(item_price) AS average,
    MAX(item_price) AS highest,
    MIN(item_price) AS lowest
FROM ITEM;