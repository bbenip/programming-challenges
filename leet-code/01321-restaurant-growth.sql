SELECT
  C1.visited_on AS visited_on,
  SUM(C2.amount) AS amount,
  ROUND(SUM(C2.amount) / 7, 2) AS average_amount
FROM (SELECT DISTINCT visited_on FROM Customer) AS C1
INNER JOIN Customer AS C2 ON (
  C1.visited_on >= C2.visited_on
  AND DATEDIFF(C1.visited_on, C2.visited_on) < 7
)
GROUP BY C1.visited_on
HAVING DATEDIFF(C1.visited_on, MIN(C2.visited_on)) = 6
ORDER BY visited_on ASC;
