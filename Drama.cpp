#include "Drama.h"

/*
 * overloaded operator< to check if Drama movie
 * comes before movie passed in parameter, based
 * on sorted order.
 */
bool Drama::operator<(const Movie &drama) const {
    if(drama.getGenre() != 'D') {
        cout << "Not comparing movies of same genre" << endl;
        return false;
    }

    if(getDirector() < drama.getDirector())
        return true;
    else if(getDirector() == drama.getDirector()) {
        if(getTitle() < drama.getTitle())
            return true;
    }
    return false;
}

/*
 * overloaded operator> to check if Drama movie
 * comes after movie passed in parameter, based on
 * sorted order.
 */
bool Drama::operator>(const Movie &drama) const {
    if(drama.getGenre() != 'D') {
        cout << "Not comparing movies of same genre" << endl;
        return false;
    }

    if(getDirector() > drama.getDirector())
        return true;
    else if(getDirector() == drama.getDirector()) {
        if(getTitle() > drama.getTitle())
            return true;
    }
    return false;
}

/*
 * overloaded operator== to check if two
 * Drama films are equal in sorted order.
 */
bool Drama::operator==(const Movie &drama) const {
    if(drama.getGenre() != 'D') {
        cout << "Not comparing movies of same genre" << endl;
        return false;
    }

    if(getDirector() == drama.getDirector() && getTitle() == drama.getTitle())
        return true;
    return false;
}

/*
 * overloaded operator!= to check if two Drama films are
 * not equal, based on sorted order.
 */
bool Drama::operator!=(const Movie &drama) const {
    if(drama.getGenre() != 'D') {
        cout << "Not comparing movies of same genre" << endl;
        return false;
    }

    // call overloaded operator==
    if(*this == drama)
        return false;
    return true;
}
