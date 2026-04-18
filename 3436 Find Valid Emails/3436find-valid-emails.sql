# Write your MySQL query statement below
SELECT * FROM USERS
WHERE EMAIL REGEXP '^[A-Za-z0-9]+@[a-zA-Z]+\\.com$'
ORDER BY USER_ID;