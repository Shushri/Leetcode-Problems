SELECT e.name AS Employee
FROM Employee e
join Employee m
on e.managerId=m.id
where e.salary>m.salary;