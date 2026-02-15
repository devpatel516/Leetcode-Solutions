# Write your MySQL query statement below
SELECT V.customer_id,count(*) as count_no_trans FROM
VISITS V LEFT JOIN TRANSACTIONS T 
ON V.VISIT_ID=T.VISIT_ID
WHERE T.VISIT_ID IS NULL
GROUP BY V.customer_id;
