# Write your MySQL query statement below
-- with cte as(select *,
--         case 
--             when income<20000 then 'Low Salary'
--             when income>=20000 and income<=50000 then 'Average Salary'
--             when income>50000 then 'High Salary'
--         end as 'category'
-- from Accounts)

-- select category,count(account_id) from cte group by category;

select 'Low Salary' as category,sum(income<20000) as 'accounts_count' from accounts
union
select 'Average Salary' as category,sum(income>=20000 and income<=50000) as 'accounts_count' from accounts
union
select 'High Salary' as category,sum(income>50000) as 'accounts_count' from accounts