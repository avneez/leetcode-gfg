select max(salary)
as secondHighestSalary  from employee
where salary not in (select max(salary) from employee);