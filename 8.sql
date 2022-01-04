--
SELECT
     "name"
FROM
     "movies"

INNER JOIN "people" ON stars."person_id" = people."id"

INNER JOIN "stars" ON movies."id" = stars."movie_id"

WHERE
     "title" LIKE "%Toy Story"