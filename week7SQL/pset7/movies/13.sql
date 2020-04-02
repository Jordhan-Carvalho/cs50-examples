

SELECT DISTINCT(name) FROM stars JOIN movies ON stars.movie_id IN
(SELECT movie_id FROM movies JOIN stars ON movies.id=stars.movie_id JOIN people ON stars.person_id=people.id WHERE name="Kevin Bacon" AND birth=1958)
JOIN people ON stars.person_id=people.id WHERE name<>"Kevin Bacon";

-- COULD ADD INDEXS