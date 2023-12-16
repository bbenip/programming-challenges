SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM Insurance AS I1
WHERE (
  tiv_2015 IN (SELECT tiv_2015 FROM Insurance WHERE pid != I1.pid)
  AND (lat, lon) NOT IN (SELECT lat, lon FROM Insurance WHERE pid != I1.pid)
);
