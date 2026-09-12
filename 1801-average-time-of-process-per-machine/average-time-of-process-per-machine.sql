# Write your MySQL query statement below
with t1 as(select machine_id,count(process_id) as c,sum(timestamp) as 'e' from Activity where activity_type='end' group by machine_id),
t2 as (select machine_id,count(process_id) as c,sum(timestamp) as 's' from Activity where activity_type='start' group by machine_id)

select t1.machine_id as 'machine_id',round(sum(t1.e-t2.s)/t1.c,3) as 'processing_time' 
from t1 join t2 on t1.machine_id=t2.machine_id group by t1.machine_id;
