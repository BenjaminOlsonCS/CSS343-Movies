#ifndef PROGRAM4_CLASSIC_H
#define PROGRAM4_CLASSIC_H

#include <string>
#include "Movie.h"

using namespace std;

/*
 * The Classic class inherits from the Movie class. This class
 * contains information stored in the Movie class, along with
 * extra information specific to this genre. These attributes
 * include a major actor and release month. The class uses
 * its own overloaded comparision operators to account for
 * the extra attributes.
 */
class Classic : public Movie
{
public:
    // parameterized constructor
    Classic(char genre, int stock, const string &director,
            const string &title, int releaseYear, string &first, string &last, int month);

    ~Classic() override;

    // accessor methods
    string getActorFirstName() const;

    string getActorLastName() const;

    int getReleaseMonth() const;

    bool isAlternative(const Classic&) const; // checks if film has an alternate version

    // overloaded comparison operators
    bool operator<(const Movie &) const override;

    bool operator>(const Movie &) const override;

    bool operator==(const Movie &) const override;

    bool operator!=(const Movie &) const override;

    // overridden method, Classic movies are displayed differently
    void display() const override;


private:
    string firstName;
    string lastName;
    int releaseMonth;

    // helper method for changeStock if movie runs out of stock
    // bool availableAlt(Movie& other) const;

};

#endif //PROGRAM4_CLASSIC_H