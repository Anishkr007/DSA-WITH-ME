# Write your MySQL query statement below
(select employee_id 
FROM Employees 
LEFT JOIN Salaries USING(employee_id)
WHERE salary is NULL)


UNION

(select employee_id 
from Employees 
RIGHT JOIN Salaries USING (employee_id)
WHERE name is NULL)

ORDER BY employee_id
