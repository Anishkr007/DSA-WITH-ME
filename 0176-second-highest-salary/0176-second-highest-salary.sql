# Write your MySQL query statement below

SELECT max(salary) AS SecondHighestSalary
from Employee
WHERE salary<(
    select max(salary) from Employee
);