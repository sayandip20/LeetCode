# Write your MySQL query statement below
select e.name, b.bonus from Employee e left join Bonus b using(empId) where coalesce(bonus,0)<1000 ;