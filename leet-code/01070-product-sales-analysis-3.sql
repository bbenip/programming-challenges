SELECT
  product_id,
  year AS first_year,
  quantity,
  price
FROM Sales AS S1
INNER JOIN (
  SELECT product_id, MIN(year) AS year
  FROM Sales
  GROUP BY product_id
) AS S2 USING(product_id, year);
