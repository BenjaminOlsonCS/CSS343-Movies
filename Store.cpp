#include "Store.h"

Store::Store() {
    // default constructor needs customer and transaction classes
    movies = new BSTree;
    // we know these genres are valid
    genreTypes.push_back('F');
    genreTypes.push_back('D');
    genreTypes.push_back('C');

}

/*
 * precondition: have a correctly formatted text file
 * containing a list of movies of varying genres.
 * postcondition: adds all movies from a given text file
 * to the binary search tree, and sorts them based on the
 * given sorting criteria.
 */
void Store::buildMovie(ifstream &movieFile) {
    string line;
    while(!movieFile.eof()) {
        // each movie contains these attributes in this order, regardless of genre
        char genre;
        movieFile >> genre;
        if(!isValidGenre(genre)) { // in case of invalid genre
            getline(movieFile, line); // skip to next line
            continue;
        }
        char comma;
        movieFile >> comma;
        int stock;
        movieFile >> stock;
        movieFile >> comma;
        string director;
        getline(movieFile, director, ',');
        string title;
        getline(movieFile, title, ',');
        // check for movie genre, for genre specific formatting
        if(genre == 'F' || genre == 'D') {
            int releaseYear;
            movieFile >> releaseYear;
            if(genre == 'F') { // movie is of Comedy genre
                Movie* film = new Comedy(genre, stock, director, title, releaseYear);
                movies->insert(film);
            }
            else { // movie is of Drama genre
                Movie* film = new Drama(genre, stock, director, title, releaseYear);
                movies->insert(film);
            }
        }
        else { // movie is of Classic genre
            string firstName, lastName;
            movieFile >> firstName >> lastName;
            int month;
            movieFile >> month;
            int releaseYear;
            movieFile >> releaseYear;
            Movie* film = new Classic(genre, stock, director, title, releaseYear, firstName, lastName, month);
            movies->insert(film);
        }
    }
}

/*
 * precondtion: have read a char from a correctly formatted
 * text file.
 * returns true if the char passed in is a valid genre type
 * by checking if it's in the genreTypes vector.
 */
bool Store::isValidGenre(char genre) const {
    for(int i = 0; i < genreTypes.size(); i++) {
        if(genre == genreTypes[i]) {
            return true; // genre is valid
        }
    }
    return false;
}

/*
 * this method adds a char to the genreTypes vector,
 * to indicate that this is a valid genre to read from
 * a text file.
 */
void Store::addGenre(char genre) {
    genreTypes.push_back(genre);
}

void Store::displayInventory() const {
    movies->display();
}
