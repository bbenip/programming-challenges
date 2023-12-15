WITH
  UserWithMostRatings AS (
    SELECT name, COUNT(rating) AS number_of_ratings
    FROM MovieRating
    INNER JOIN Users USING(user_id)
    GROUP BY user_id
    ORDER BY number_of_ratings DESC, name ASC
    LIMIT 1
  ),
  HighestRatedMovie AS (
    SELECT title, AVG(rating) AS average_rating
    FROM MovieRating
    INNER JOIN Movies USING(movie_id)
    WHERE created_at LIKE '2020-02-%'
    GROUP BY movie_id
    ORDER BY average_rating DESC, title ASC
    LIMIT 1
  )

(
  SELECT name AS results
  FROM UserWithMostRatings
)
UNION ALL
(
  SELECT title AS results
  FROM HighestRatedMovie
);
