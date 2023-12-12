DELETE FROM Person WHERE (
  id NOT IN (
    SELECT id
    FROM (
      SELECT MIN(id) AS id
      FROM Person AS P1
      GROUP BY email
    ) AS MinimumIds
  )
);
