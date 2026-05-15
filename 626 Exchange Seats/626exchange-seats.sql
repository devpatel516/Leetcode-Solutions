# Write your MySQL query statement below
select id,
        case
            when id%2=0 then lag(student) over()
            when id%2=1 then coalesce(lead(student) over(),student)
        end as student
    from Seat;