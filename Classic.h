#ifndef PROGRAM4_CLASSIC_H
#define PROGRAM4_CLASSIC_H

#include <string>
#include "Movie.h"
using namespace std;

class Classic: public Movie {
public:
    // parameterized constructor
    Classic(char genre, int stock, const string &director,
            const string &title, int releaseYear, string first, string last, int month)
            : Movie(genre, stock, director, title, releaseYear) {
        firstName = first;
        lastName = last;
        releaseMonth = month;
    }

    // accessor methods
    String getActorFirstName();
    String getActorLastName();
    int getReleaseMonth();

    // overridden method for changing the movie's stock
    bool changeStock(char trans);

    // overridden overloaded comparison operators
    bool operator<(const Movie&) const override;
    bool operator>(const Movie&) const override;
    bool operator==(const Movie&) const override;
    bool operator!=(const Movie&) const override;

    // overridden method, Classic movies are displayed differently
    void display() const;



private:
    string firstName;
    string lastName;
    int releaseMonth;

    // helper method for changeStock if movie runs out of stock
    // bool availableAlt(Movie& other) const;

};

#endif //PROGRAM4_CLASSIC_H
