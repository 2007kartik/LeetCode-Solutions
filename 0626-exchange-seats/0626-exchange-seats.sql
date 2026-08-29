# Write your MySQL query statement below
select (case when id%2=1 and id<>(select count(*) from Seat) then id+1 
             when id%2=0 then id-1 
             when id=(select count(*) from Seat) then id end) as id  , 
             student from Seat order by id asc;