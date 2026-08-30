CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
   
  RETURN (
        select max(salary) from 
        (select salary , dense_rank()
        over (order by salary desc) as dn
        from Employee) t
        where dn=N

  );
END