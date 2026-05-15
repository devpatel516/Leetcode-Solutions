# Write your MySQL query statement below
with cte as(select visited_on,amount,sum(amount) as 'temp' from Customer group by visited_on order by visited_on asc)
select visited_on,sum(temp) over(order by visited_on rows between 6 preceding and current row) as 'amount',round(avg(temp) over(order by visited_on rows between 6 preceding and current row),2) as 'average_amount' from cte limit 6,999999;