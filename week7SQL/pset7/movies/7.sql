SELECT title,rating FROM movies JOIN ratings ON movies.id=ratings.movie_id WHERE year=2010 GROUP BY title ORDER BY rating DESC;

-- Index to go faster
-- CREATE INDEX movie_index ON ratings(movie_id);
-- CREATE INDEX id_index ON movies(id);