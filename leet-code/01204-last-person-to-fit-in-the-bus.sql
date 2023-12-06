SELECT person_name
FROM Queue AS Q1
INNER JOIN (
  SELECT turn, weight
  FROM Queue
  ORDER BY turn
) AS Q2 ON (
  Q2.turn <= Q1.turn
)
GROUP BY Q1.person_id
HAVING SUM(Q2.weight) <= 1000
ORDER BY SUM(Q2.weight) DESC
LIMIT 1;
