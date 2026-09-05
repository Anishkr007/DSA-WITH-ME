# Write your MySQL query statement below

select name from SalesPerson
where sales_id NOT IN(
    select sales_id from Orders e1
    Where com_id IN(
        select com_id from Company e2
        where e1.com_id=e2.com_id 
        AND e2.name='RED'
    )

);