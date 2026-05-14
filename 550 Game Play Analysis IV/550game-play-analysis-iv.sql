-- # Write your MySQL query statement below
with cte as(select player_id,event_date,lead(event_date) over(partition by player_id ORDER BY event_date) as 'next_date',row_number() over(partition by player_id order by event_date) as 'rn' from Activity)
select round(sum(if(datediff(next_date,event_date)=1,1,0))/(select count(distinct(player_id)) from cte),2) as 'fraction' from cte where rn=1;