# Write your MySQL query statement below
with cte as(select departmentId,name,salary,rank() over(partition by departmentId order by salary desc) as 'rank' from Employee)

select d.name as 'Department',c.name as 'Employee',c.salary as 'Salary' from
Department d join cte c
on d.id=c.departmentId
where c.rank=1;