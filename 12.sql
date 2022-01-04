SELECT
     "title"
FROM
     "stars"
JOIN
     "movies" ON stars."movie_id" = movies."id"
JOIN
     "people" ON stars."person_id" = people."id"
WHERE
     "name" IN ('Helena Bonham Carter', 'Johnny Depp')
GROUP BY
     "title" HAVING COUNT(distinct name) = 2
