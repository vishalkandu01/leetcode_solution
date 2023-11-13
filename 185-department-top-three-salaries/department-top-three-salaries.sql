# Write your MySQL query statement below

select d.name as department, e.name as employee, salary from employee e
inner join department d
on d.id = e.departmentId
where 4 > (select count(distinct salary)
from employee e1 
where e1.salary >= e.salary and e1.departmentId = e.departmentid);