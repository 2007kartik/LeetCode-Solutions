# Write your MySQL query statement below
select 
round(count(a.player_id)/count(distinct f.player_id),2)
as fraction 
from (
    select player_id  , min(event_date) as first_login 
    from Activity group by player_id
) as f 
left join Activity a on a.player_id  = f.player_id
and a.event_date = date_add(f.first_login , interval 1 day);