# Write your MySQL query statement below
# SELECT name FROM Employee
# LEFT JOIN bonus FROM Bonus
# WHERE Employee.empId = Bonus.empId AND Employee.salary < 1000;

SELECT Employee.name, Bonus.bonus
FROM Employee LEFT JOIN Bonus
ON Employee.empID = Bonus.empID
WHERE (bonus < 1000 OR bonus IS NULL);
