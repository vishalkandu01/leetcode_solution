# Write your MySQL query statement below
select request_at as day, round((sum(case when status != 'completed' then 1 else 0 end)/count(distinct id)), 2) as 'cancellation rate'
from trips
where request_at between '2013-10-01' and '2013-10-03' 
and client_id not in (select users_id from users where banned = 'yes')
and driver_id not in (select users_id from users where banned = 'yes')
group by request_at;