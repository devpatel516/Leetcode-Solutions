# Write your MySQL query statement below
select t.user_id,ROUND(IFNULL(t.confirmed/t.total,0),2) as 'confirmation_rate' from (select s.user_id,count(c.action) as 'total',sum(c.action='confirmed') as 'confirmed' from
Signups s
left join Confirmations c 
on s.user_id=c.user_id
group by s.user_id) t;