SELECT title FROM movies JOIN stars ON movies.id=stars.movie_id JOIN people ON stars.person_id=people.id WHERE name="Helena Bonham Carter"
INTERSECT
SELECT title FROM movies JOIN stars ON movies.id=stars.movie_id JOIN people ON stars.person_id=people.id WHERE name="Johnny Depp";

-- The SQL INTERSECT operator is used to return the results of 2 or more SELECT statements. However, it only returns the rows selected by all queries or data sets. If a record exists in one query and not in the other, it will be omitted from the INTERSECT results.