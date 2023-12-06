SELECT
  product_id,
  (CASE WHEN new_price IS NULL THEN 10 ELSE new_price END) AS price
FROM (
  SELECT *
  FROM (
    SELECT product_id
    FROM Products
    GROUP BY product_id
  ) AS P1
  LEFT JOIN (
    SELECT product_id, MAX(change_date) AS change_date
    FROM Products
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id
  ) AS P2 USING(product_id)
) AS P3
LEFT JOIN Products AS P4 USING(product_id, change_date);

