# Write your MySQL query statement below

SELECT name AS Customers
FROM Customers c
LEFT JOIN Orders o
ON o.customerId = c.id
WHERE o.id IS NULL;