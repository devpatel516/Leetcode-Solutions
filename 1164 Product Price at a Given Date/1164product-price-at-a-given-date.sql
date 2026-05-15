# Write your MySQL query statement below
with cte as(select product_id,new_price,change_date,rank() over(partition by product_id order by change_date desc) as 'temp' from Products where change_date<='2019-8-16')

select product_id,new_price as 'price' from cte where temp=1
union
select product_id,10 from Products where product_id not in (select distinct(product_id) from cte);