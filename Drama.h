#ifndef PROGRAM4_DRAMA_H
#define PROGRAM4_DRAMA_H

#include <string>
#include "Movie.h"

using namespace std;

/*
 * The Drama class inherits from the Movie class. This class
 * contains information stored in the Movie class, and overrides
 * the comparison operators to check for sorted order.
 */
class Drama : public Movie
{
public:
    // parameterized constructor
    Drama(char genre, int stock, const string &director, const string &title, int releaseYear)
            : Movie(genre, stock, director, title, releaseYear)
    {
    };

    // overridden overloaded comparison operators
    bool operator<(const Movie &) const override;

    bool operator>(const Movie &) const override;

    bool operator==(const Movie &) const override;

    bool operator!=(const Movie &) const override;
};

#endif //PROGRAM4_DRAMA_H