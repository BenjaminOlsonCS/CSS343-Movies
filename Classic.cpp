#include "Classic.h"

Classic::~Classic() {
    // make sure strings are deleted
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
bool Classic::operator<(const Classic &classic) const {
    if(getReleaseYear() < classic.getReleaseYear())
        return true;
    else if(getReleaseYear() == classic.getReleaseYear()) {
        if(getReleaseMonth() < classic.getReleaseMonth())
            return true;
        else if(getReleaseMonth() == classic.getReleaseMonth()) {
            if(getActorFirstName() < classic.getActorFirstName())
                return true;
            else if(getActorFirstName() == classic.getActorFirstName()) {
                if(getActorLastName() < classic.getActorLastName())
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
bool Classic::operator>(const Classic & classic) const {
    if(getReleaseYear() > classic.getReleaseYear())
        return true;
    else if(getReleaseYear() == classic.getReleaseYear()) {
        if(getReleaseMonth() > classic.getReleaseMonth())
            return true;
        else if(getReleaseMonth() == classic.getReleaseMonth()) {
            if(getActorFirstName() > classic.getActorFirstName())
                return true;
            else if(getActorFirstName() == classic.getActorFirstName()) {
                if(getActorLastName() > classic.getActorLastName())
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
bool Classic::operator==(const Classic &classic) const {
    if(getReleaseYear() == classic.getReleaseYear() && getReleaseMonth() == classic.getReleaseMonth() &&
            getActorFirstName() == classic.getActorFirstName() && getActorLastName() == classic.getActorLastName())
        return true;
    return false;
}

/*
 * overloaded operator!= to check if two Classic movies
 * are not equal.
 */
bool Classic::operator!=(const Classic &classic) const {
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
