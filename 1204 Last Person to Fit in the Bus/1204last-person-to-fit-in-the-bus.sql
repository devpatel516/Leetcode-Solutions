# Write your MySQL query statement below
with cte as(select *,sum(weight) over (order by turn) as 'cs' from Queue)

select person_name from cte where cs<=1000 order by cs desc limit 1;