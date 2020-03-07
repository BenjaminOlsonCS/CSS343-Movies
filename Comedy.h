#ifndef PROGRAM4_COMEDY_H
#define PROGRAM4_COMEDY_H

#include <string>
#include "Movie.h"
using namespace std;

/*
 * The Comedy class is derived from the
 * Movie class. It stores information about
 * a movie in the comedy genre that can be outputted.
 * The class performs operations to compare
 * which comedy film would be sorted before another
 * comedy film.
 */
class Comedy: public Movie {
public:
    // parameterized constructor
    Comedy(char genre, int stock, const string &director, const string &title, int releaseYear)
            : Movie(genre, stock, director, title, releaseYear) {};

    // overridden overloaded comparison operators
    bool operator<(const Movie&) const override;
    bool operator>(const Movie&) const override;
    bool operator==(const Movie&) const override;
    bool operator!=(const Movie&) const override;


};

#endif //PROGRAM4_COMEDY_H
