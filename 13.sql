SELECT
     "name" [except "Kevin Bacon"]
FROM
     "stars"
INNER JOIN
     "people" ON stars."person_id" = people."id"
INNER JOIN
     "movies" ON stars."movie_id" = movies."id"
WHERE movies.id IN(SELECT movies.id FROM movies JOIN "stars" ON movies."id" = stars."movie_id" JOIN "people" ON stars."person_id" = people."id" WHERE name = "Kevin Bacon" AND birth = "1958")
 AND "name" != "Kevin Bacon"
