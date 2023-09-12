# Write your MySQL query statement below

# Method 1
# SELECT s.name
# FROM Orders o
# JOIN Company c
# ON o.com_id = c.com_id
# AND c.name = 'RED'
# RIGHT JOIN SalesPerson s
# ON s.sales_id = o.sales_id
# WHERE o.sales_id IS NULL;


# Method 2
SELECT s.name FROM SalesPerson s
WHERE s.sales_id NOT IN (
  SELECT o.sales_id FROM Orders o
  JOIN Company c
  ON c.com_id = o.com_id WHERE c.name = 'RED'
)