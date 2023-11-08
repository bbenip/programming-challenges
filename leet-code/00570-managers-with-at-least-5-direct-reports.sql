SELECT E1.name AS name
FROM Employee AS E1
LEFT JOIN Employee AS E2 ON E1.id = E2.managerId
GROUP BY E1.id
HAVING COUNT(*) >= 5;
