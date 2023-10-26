SELECT W2.id AS id
FROM Weather AS W1
INNER JOIN Weather AS W2 ON DATE_ADD(W1.recordDate, INTERVAL 1 DAY) = W2.recordDate
WHERE W2.temperature > W1.temperature;
