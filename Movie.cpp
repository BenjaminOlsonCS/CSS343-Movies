#include "Movie.h"


/*
 * parameterized constructor, creates a movie
 * with all attributes set to values given in
 * parameter.
 */
Movie::Movie(char genre, int stock, const string &director, const string &title, int releaseYear) {
    this->genre = genre;
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->releaseYear = releaseYear;
}

/*
 * destructor
 */
Movie::~Movie() {
}

/*
 * precondition: customer has a movie
 * to return, or store has movie for
 * customer to borrow.
 * postcondition: increments or decrements
 * movie stock depending on transaction type.
 */
bool Movie::changeStock(char trans) {
    if(trans == 'B')
        stock--;
    else if(trans == 'R')
        stock++;
}

// accessor methods for each attribute of Movie class
string Movie::getTitle() const {
    return title;
}

int Movie::getStock() const {
    return stock;
}

string Movie::getDirector() const {
    return director;
}

char Movie::getGenre() const {
    return genre;
}

int Movie::getReleaseYear() const {
    return releaseYear;
}

/*
 * display() method is used to output
 * the comedy movie's information based
 * on its sorted order. This function will
 * be used to output the store's inventory.
 */
void Movie::display() const {
    cout << getStock() << ", " << getDirector() << ", ";
    cout << getTitle() << ", " << getReleaseYear() << endl;
}
