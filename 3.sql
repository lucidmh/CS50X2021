--select the name of the movies row
SELECT
     "title"
--to choose from the movies table
FROM
    "movies"
--we should choose the movies after the 2018 realese date (ALPHABETICAL)
WHERE
    "year" >= 2018
ORDER BY
    "title" ASC