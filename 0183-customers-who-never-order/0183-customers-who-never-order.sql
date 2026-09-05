# Write your MySQL query statement below
select e1.name as Customers
from Customers e1
LEFT JOIN Orders e2
ON e1.id=e2.customerId
WHERE customerId is null