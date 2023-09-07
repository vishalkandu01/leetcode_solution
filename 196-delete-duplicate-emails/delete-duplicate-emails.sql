# Write your MySQL query statement below
DELETE p1 from Person p1, Person p2
WHERE p1.email = p2.email and p1.id > p2.id;