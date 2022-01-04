SELECT
      "title"
FROM
      "stars"
JOIN
      "movies" ON stars."movie_id" = movies."id"
JOIN
      "people" ON stars."person_id" = people."id"
JOIN
      "ratings" ON movies."id" = ratings."movie_id"
WHERE
      "name" LIKE "Chadwick Boseman"
ORDER BY
      "rating"
DESC LIMIT "5"