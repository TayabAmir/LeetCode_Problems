# Write your MySQL query statement below
Select E.name as Employee from Employee E, Employee M where E.managerId = M.id and E.salary > M.salary