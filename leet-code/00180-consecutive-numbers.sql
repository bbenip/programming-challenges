SELECT DISTINCT L1.num AS ConsecutiveNums
FROM Logs AS L1
INNER JOIN (
  SELECT
    L2.id AS next_id,
    L2.num AS num
  FROM Logs AS L2
  INNER JOIN Logs AS L3 ON L3.id = L2.id + 1
  WHERE L2.num = L3.num
) AS L4 ON L4.next_id = L1.id + 1
WHERE L1.num = L4.num;
