# Write your MySQL query statement below
(select name as 'results' from Users u
join MovieRating m 
on u.user_id=m.user_id
group by name
order by count(movie_id) desc,name asc limit 1)
union all
(select title as 'results' from Movies m
join MovieRating r
on m.movie_id=r.movie_id
where date_format(created_at,'%Y-%m')='2020-02'
group by title
order by avg(rating) desc,title asc limit 1);