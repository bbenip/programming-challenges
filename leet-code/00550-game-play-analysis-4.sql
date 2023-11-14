SELECT
  ROUND(
    SUM(CASE WHEN event_date IS NOT NULL THEN 1 ELSE 0 END) / COUNT(*),
    2
  ) AS fraction
FROM Activity AS A1
RIGHT JOIN (
  SELECT player_id, MIN(event_date) AS min_event_date
  FROM Activity
  GROUP BY player_id
) AS A2 ON (
  A1.player_id = A2.player_id
  AND DATE_ADD(min_event_date, INTERVAL 1 DAY) = event_date
);
