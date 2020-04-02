SELECT DISTINCT(name) FROM movies JOIN stars ON movies.id=stars.movie_id JOIN people ON stars.person_id=people.id WHERE year=2004 ORDER BY birth;

-- Index to go faster
-- CREATE INDEX person_index ON stars(person_id);
-- CREATE INDEX movie_index ON stars(movie_id);
-- CREATE INDEX id_index ON movies(id);