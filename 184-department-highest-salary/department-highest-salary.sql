# Write your MySQL query statement below

# select d.name as department, e.name as employee, e.salary as Salary from department d, employee e
# where e.departmentId = d.id and (e.departmentId, e.salary) in
# (select departmentId, MAX(salary) from Employee group by departmentId);


select d.name as department, e.name as employee, e.salary as Salary 
from employee e, department d
where e.departmentId = d.id and (e.departmentId, e.salary) 
in (select departmentId, max(salary) 
from employee 
group by departmentId);