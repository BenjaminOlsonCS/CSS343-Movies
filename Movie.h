#ifndef PROGRAM4_MOVIE_H
#define PROGRAM4_MOVIE_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/*
 * The Movie class is an abstract class
 * that represents a movie of any genre.
 * The class has accessor methods for
 * each attribute of the class, and pure virtual
 * overloaded comparison operators used for
 * sorting movies within their genres.
 */
class Movie {

public:
    Movie(char genre, int stock, const string &director, const string &title, int releaseYear);
    virtual ~Movie();

    // accessor methods
    string getTitle() const;
    int getStock() const;
    string getDirector() const;
    char getGenre() const;
    int getReleaseYear() const;

    // method called when borrowing or returning movie
    virtual bool changeStock(char trans);

    // factory method for movies
    //static Movie *makeMovie(char genre);

    // overloaded comparison operators
    virtual bool operator<(const Movie&) const = 0;
    virtual bool operator>(const Movie&) const = 0 ;
    virtual bool operator==(const Movie&) const = 0;
    virtual bool operator!=(const Movie&) const = 0;
    virtual void display() const;

protected:
    // Movie attributes
    string title;
    int stock;
    string director;
    char genre;
    int releaseYear;

    // returns true if customer has borrowed this movie
    // bool verifyMovieBorrowed(Customer& customer)
};


#endif //PROGRAM4_MOVIE_H
