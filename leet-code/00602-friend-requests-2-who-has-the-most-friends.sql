SELECT id, COUNT(accept_date) AS num
FROM (
  (SELECT DISTINCT requester_id AS id FROM RequestAccepted)
  UNION
  (SELECT DISTINCT accepter_id AS id FROM RequestAccepted)
) AS UniqueIds
INNER JOIN RequestAccepted ON (id = requester_id OR id = accepter_id)
GROUP BY id
ORDER BY num DESC
LIMIT 1;
