#include "Classic.h"

Classic::Classic(char genre, int stock, const string &director, const string &title, int releaseYear, string &first,
                 string &last, int month) : Movie(genre, stock, director, title, releaseYear) {
    firstName = first;
    lastName = last;
    releaseMonth = month;
}

Classic::~Classic() {
    delete this;
}

// accessor methods
string Classic::getActorFirstName() const {
    return firstName;
}

string Classic::getActorLastName() const {
    return lastName;
}

int Classic::getReleaseMonth() const {
    return releaseMonth;
}

/*
 * overloaded operator< to check if Classic movie
 * is sorted before movie passed in parameter.
 */
bool Classic::operator<(const Movie &classic) const {
    if(classic.getGenre() != 'C') // classic movies come after comedy and drama films
        return false;

    const Classic& film = static_cast<const Classic &>(classic);

    if(getReleaseYear() < film.getReleaseYear())
        return true;
    else if(getReleaseYear() == film.getReleaseYear()) {
        if(getReleaseMonth() < film.getReleaseMonth())
            return true;
        else if(getReleaseMonth() == film.getReleaseMonth()) {
            if(getActorFirstName() < film.getActorFirstName())
                return true;
            else if(getActorFirstName() == film.getActorFirstName()) {
                if(getActorLastName() < film.getActorLastName())
                    return true;
            }
        }
    }
    return false;
}

/*
 * overloaded operator> to check if Classic movie
 * is sorted after movie passed in parameter.
 */
bool Classic::operator>(const Movie & classic) const {
    if(classic.getGenre() != 'C') // classic movies come after comedy and drama films
        return true;

    const Classic& film = static_cast<const Classic &>(classic);

    if(getReleaseYear() > film.getReleaseYear())
        return true;
    else if(getReleaseYear() == film.getReleaseYear()) {
        if(getReleaseMonth() > film.getReleaseMonth())
            return true;
        else if(getReleaseMonth() == film.getReleaseMonth()) {
            if(getActorFirstName() > film.getActorFirstName())
                return true;
            else if(getActorFirstName() == film.getActorFirstName()) {
                if(getActorLastName() > film.getActorLastName())
                    return true;
            }
        }
    }
    return false;
}

/*
 * overloaded operator== to check if two Classic movies
 * are the same.
 */
bool Classic::operator==(const Movie &classic) const {
    if(classic.getGenre() != 'C') // classic movies come after comedy and drama films
        return false;

    const Classic& film = static_cast<const Classic &>(classic);

    if(getReleaseYear() == film.getReleaseYear() && getReleaseMonth() == film.getReleaseMonth() &&
            getActorFirstName() == film.getActorFirstName() && getActorLastName() == film.getActorLastName())
        return true;
    return false;
}

/*
 * overloaded operator!= to check if two Classic movies
 * are not equal.
 */
bool Classic::operator!=(const Movie &classic) const {
    if(*this == classic)
        return false;
    return true;
}

/*
 * displays Classic movie information, outputs all attributes
 * of the class.
 */
void Classic::display() const {
    cout << getStock() << ", " << getDirector() << ", " << getTitle() << ", ";
    cout << getActorFirstName() << " " << getActorLastName() << " " << getReleaseMonth();
    cout << " " << getReleaseYear() << endl;
}
