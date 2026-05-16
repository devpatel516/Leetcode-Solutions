# Write your MySQL query statement below
/* Write your PL/SQL query statement below */
select id,movie,description,rating
from cinema
where description not in('boring') and mod(id,2)!=0
order by rating desc;