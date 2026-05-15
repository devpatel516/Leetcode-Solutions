# Write your MySQL query statement below
with cte as(select id,num,lead(num) over() as 'next',lag(num) over() as 'prev' from Logs)

select distinct(num) as 'ConsecutiveNums' from cte where num=next and next=prev and prev=num;