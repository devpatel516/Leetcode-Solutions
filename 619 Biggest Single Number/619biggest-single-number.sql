# Write your MySQL query statement below
select (select num 
from MyNumbers
group by num 
having count(num)=1
order by count(num) asc,num desc limit 1) as 'num';

#wrapping query inside scalar subquery makes MySQL return NULL automatically instead of empty result