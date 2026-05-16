# Write your MySQL query statement below
/* Write your PL/SQL query statement below */
select tweet_id
from tweets
where length(content)>15;