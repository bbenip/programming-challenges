SELECT MAX(salary) AS SecondHighestSalary
FROM (
  SELECT DISTINCT salary
  FROM Employee
  ORDER BY salary DESC
  LIMIT 1 OFFSET 1
) AS RelevantSalary;
