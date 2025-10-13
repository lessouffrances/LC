def main():
    # Example 1
    squares = []
    for i in range(1, 101):
        squares.append(i**2)

    # print(squares)

    square_2 = [ i** 2 for i in range(1, 101) ]
    # print(square_2)

    # Example 2
    remainders5 = [ x**2 % 5 for x in range(1, 101) ]
    print(remainders5)
    remainders11 = [ x**2 % 11 for x in range(1, 101) ]
    print(remainders11)

    # Example 3
    movies = [
    "The Shawshank Redemption",
    "The Godfather",
    "The Dark Knight",
    "Schindler's List",
    "Pulp Fiction",
    "The Lord of the Rings: The Return of the King",
    "Forrest Gump",
    "Inception",
    "Fight Club",
    "The Matrix",
    "The Empire Strikes Back",
    "The Lord of the Rings: The Fellowship of the Ring",
    "The Godfather Part II",
    "Interstellar",
    "The Green Mile",
    "Gladiator",
    "Saving Private Ryan",
    "The Silence of the Lambs",
    "Se7en",
    "The Usual Suspects",
    "Braveheart",
    "The Departed",
    "Terminator 2: Judgment Day",
    "The Prestige",
    "The Lion King",
    "Star Wars: A New Hope",
    "Avengers: Endgame",
    "Back to the Future",
    "The Lord of the Rings: The Two Towers",
    "Django Unchained",
    "Whiplash",
    "The Intouchables",
    "Parasite",
    "The Wolf of Wall Street",
    "Goodfellas",
    "The Social Network",
    "Mad Max: Fury Road",
    "12 Angry Men",
    "The Grand Budapest Hotel",
    "No Country for Old Men",
    "Shutter Island",
    "La La Land",
    "The Dark Knight Rises",
    "Joker",
    "Titanic",
    "Inglourious Basterds",
    "Alien",
    "Blade Runner 2049",
    "A Beautiful Mind",
    "Memento",
    "The Imitation Game",
    "Black Panther",
    "Spider-Man: Into the Spider-Verse",
    "Her",
    "Logan",
    "Toy Story 3",
    "The Pianist",
    "A Clockwork Orange",
    "The Big Lebowski",
    "Eternal Sunshine of the Spotless Mind",
    "The Great Gatsby",
    "Requiem for a Dream"
    ]

    gmovies = []
    for title in movies:
        if title.startswith("G"):
            gmovies.append(title)
    print(gmovies)

    gmovies = [ movie for movie in movies if movie.startswith("G") ]
    print(gmovies)

    movies = [
    ("The Shawshank Redemption", 1994),
    ("The Godfather", 1972),
    ("The Dark Knight", 2008),
    ("Schindler's List", 1993),
    ("Pulp Fiction", 1994),
    ("The Lord of the Rings: The Return of the King", 2003),
    ("Forrest Gump", 1994),
    ("Inception", 2010),
    ("Fight Club", 1999),
    ("The Matrix", 1999),
    ("The Empire Strikes Back", 1980),
    ("The Lord of the Rings: The Fellowship of the Ring", 2001),
    ("The Godfather Part II", 1974),
    ("Interstellar", 2014),
    ("The Green Mile", 1999),
    ("Gladiator", 2000),
    ("Saving Private Ryan", 1998),
    ("The Silence of the Lambs", 1991),
    ("Se7en", 1995),
    ("The Usual Suspects", 1995),
    ("Braveheart", 1995),
    ("The Departed", 2006),
    ("Terminator 2: Judgment Day", 1991),
    ("The Prestige", 2006),
    ("The Lion King", 1994),
    ("Star Wars: A New Hope", 1977),
    ("Avengers: Endgame", 2019),
    ("Back to the Future", 1985),
    ("The Lord of the Rings: The Two Towers", 2002),
    ("Django Unchained", 2012),
    ("Whiplash", 2014),
    ("The Intouchables", 2011),
    ("Parasite", 2019),
    ("The Wolf of Wall Street", 2013),
    ("Goodfellas", 1990),
    ("The Social Network", 2010),
    ("Mad Max: Fury Road", 2015),
    ("12 Angry Men", 1957),
    ("The Grand Budapest Hotel", 2014),
    ("No Country for Old Men", 2007),
    ("Shutter Island", 2010),
    ("La La Land", 2016),
    ("The Dark Knight Rises", 2012),
    ("Joker", 2019),
    ("Titanic", 1997),
    ("Inglourious Basterds", 2009),
    ("Alien", 1979),
    ("Blade Runner 2049", 2017),
    ("A Beautiful Mind", 2001),
    ("Memento", 2000),
    ("The Imitation Game", 2014),
    ("Black Panther", 2018),
    ("Spider-Man: Into the Spider-Verse", 2018),
    ("Her", 2013),
    ("Logan", 2017),
    ("Toy Story 3", 2010),
    ("The Pianist", 2002),
    ("A Clockwork Orange", 1971),
    ("The Big Lebowski", 1998),
    ("Eternal Sunshine of the Spotless Mind", 2004),
    ("The Great Gatsby", 2013),
    ("Requiem for a Dream", 2000)
    ]

    pre2kmovies_1 = []
    for movie, year in movies:
        if year > 2000:
            pre2kmovies_1.append(movie)

    pre2kmovies_2 = [ movie for (movie, year) in movies if year > 2000 ]
    print(pre2kmovies_2)

    if pre2kmovies_1 == pre2kmovies_2:
        print("correct")


    # Example 4
    v = [2, -3, 1]
    w = [ 4*num for num in v ]
    print(w)

    # Example 5 Cartesian product of sets
    set1 = {1, 2, 3, 4, 5}
    set2 = {"apple", "banana", "cherry", "date", "elderberry"}
    set1 = list(set1)
    print(set1)
    set2 = list(set2)
    print(set2)

    cartesianProductof12 = [ (a, b) for a in set1 for b in set2 ]
    print(cartesianProductof12)

main()