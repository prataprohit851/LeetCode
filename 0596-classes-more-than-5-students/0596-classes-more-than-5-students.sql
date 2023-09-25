# Write your MySQL query statement below
WITH cte AS(
    SELECT class, COUNT(student) AS cnt
    FROM Courses
    GROUP BY class
)

SELECT class 
FROM CTE
WHERE cnt >= 5;