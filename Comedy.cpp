#include "Comedy.h"

/*
 * overloaded operator< to check if
 * comedy movie is sorted before movie
 * in parameter.
 */
bool Comedy::operator<(const Movie &funny) const {
    if(funny.getGenre() != 'F') {
        cout << "Not comparing movies of same genre" << endl;
        return false;
    }

    if(getTitle() < funny.getTitle())
        return true;
    else if(getTitle() == funny.getTitle()) {
        if (getReleaseYear() < funny.getReleaseYear())
            return true;
    }
    return false;
}

/*
 * overloaded operator> to check if movie
 * is sorted after movie in parameter.
 */
bool Comedy::operator>(const Movie & funny) const {
    if(funny.getGenre() != 'F') {
        cout << "Not comparing movies of same genre" << endl;
        return false;
    }

    if(getTitle() > funny.getTitle())
        return true;
    else if(getTitle() == funny.getTitle()) {
        if(getReleaseYear() > funny.getReleaseYear())
            return true;
    }
    return false;
}

/*
 * overloaded operator== to check if two
 * comedy movies are equal.
 */
bool Comedy::operator==(const Movie & funny) const {
    if(funny.getGenre() != 'F') {
        cout << "Not comparing movies of same genre" << endl;
        return false;
    }

    // check for equality
    if(getTitle() == funny.getTitle() && getReleaseYear() == funny.getReleaseYear())
        return true;
    return false;
}

/*
 * overloaded operator!= to check if two
 * comedy films are not equivalent based on
 * sorted order.
 */
bool Comedy::operator!=(const Movie &funny) const {
    if(funny.getGenre() != 'F') {
        cout << "Not comparing movies of same genre" << endl;
        return false;
    }

    // call overloaded operator==
    if(*this == funny)
        return false;
    return true;
}
