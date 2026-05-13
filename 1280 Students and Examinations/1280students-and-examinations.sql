# Write your MySQL query statement below
SELECT a.student_id,a.student_name,b.subject_name,count(c.subject_name) as 'attended_exams'
from Students a 
CROSS JOIN Subjects b 
LEFT JOIN Examinations c on b.subject_name=c.subject_name and a.student_id=c.student_id
GROUP BY a.student_id,a.student_name,b.subject_name
ORDER BY a.student_id,b.subject_name;