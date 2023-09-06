# Write your MySQL query statement below

-- Method1 --> By using Subqueries
# Select name as Customers FROM Customers
# WHERE id NOT IN (SELECT customerId from Orders);

-- Method2 --> By using JOIN
# SELECT c.name AS Customers FROM Customers AS c
# LEFT JOIN Orders AS o 
# ON c.id = o.customerID WHERE o.customerID IS NULL;

select name as Customers from Customers
left join Orders 
on Customers.id = Orders.customerID
where Orders.customerID is NULL;