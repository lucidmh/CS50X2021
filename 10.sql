SELECT
     "name"
FROM
     "directors"
JOIN
     "movies" ON directors."movie_id" = movies."id"
JOIN
     "ratings" ON movies."id" = ratings."movie_id"
JOIN
     "people" ON directors."person_id" = people."id"
WHERE
     "rating" >= "9.0"