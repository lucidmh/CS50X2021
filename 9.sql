SELECT
     "name"
FROM
     "stars"
JOIN
    "people" ON stars."person_id" = people."id"
JOIN
    "movies" ON stars."movie_id" = movies."id"
WHERE
    "year" == "2004"
ORDER BY
    "birth"