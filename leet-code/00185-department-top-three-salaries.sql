SELECT
  D1.name AS Department,
  E1.name AS Employee,
  E1.salary AS Salary
FROM Department AS D1
INNER JOIN Employee AS E1 ON (
  E1.departmentId = D1.id
)
WHERE salary >= COALESCE(
  (
    SELECT DISTINCT salary
    FROM Employee AS E2
    WHERE E2.departmentId = E1.DepartmentId
    ORDER BY salary DESC
    LIMIT 1 OFFSET 2
  ),
  0
);
