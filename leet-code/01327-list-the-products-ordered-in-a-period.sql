SELECT product_name, SUM(unit) AS unit
FROM Products
INNER JOIN Orders USING(product_id)
WHERE order_date BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY product_id
HAVING SUM(unit) >= 100;
