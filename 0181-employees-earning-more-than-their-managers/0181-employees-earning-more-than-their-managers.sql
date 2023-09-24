# Write your MySQL query statement below
SELECT name as Employee
FROM Employee a
WHERE a.salary > (SELECT salary FROM Employee WHERE a.managerId = id);