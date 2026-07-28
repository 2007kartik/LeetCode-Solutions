
select max(num) as num from MyNumbers
where num in(
    select num from MyNumbers group by num 
     having count(*) = 1
);


















-- SELECT MAX(num) AS num
-- FROM (
--     SELECT num
--     FROM MyNumbers
--     GROUP BY num
--     HAVING COUNT(*) = 1
-- ) as tt;