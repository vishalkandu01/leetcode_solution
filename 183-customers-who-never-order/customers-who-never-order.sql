# Write your MySQL query statement below
Select name as Customers FROM Customers
WHERE id NOT IN (
  SELECT customerId from Orders
);