# Write your MySQL query statement below
with cte as(select student_id,subject,first_value(score) over(partition by student_id,subject order by exam_date) as 'first_score',first_value(score) over(partition by student_id,subject order by exam_date desc) as 'latest_score' from Scores)


select distinct * from cte
where first_score<latest_score
order by student_id,subject;