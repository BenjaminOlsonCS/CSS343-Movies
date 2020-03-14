#include "Store.h"

Store::Store() {
    // default constructor needs customer and transaction classes
    movies = new BSTree;
    // we know these genres are valid
    genreTypes.push_back('F');
    genreTypes.push_back('D');
    genreTypes.push_back('C');

}

// destructor
Store::~Store() {
    movies->empty(); // deallocate memory from BSTree
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
        char genre;
        char comma;
        int stock;
        movieFile >> genre;
        if(!isValidGenre(genre)) { // in case of invalid genre
            getline(movieFile, line); // skip to next line
            continue;
        }
        movieFile >> comma;
        movieFile >> stock;
        movieFile >> comma;
        getline(movieFile, line);
        int commaIndex = line.find(',');
        string director = line.substr(1, commaIndex-1);
        line = line.erase(0, commaIndex + 1);
        commaIndex = line.find(',');
        string title = line.substr(1, commaIndex-1);
        line = line.erase(0, commaIndex + 2);
        int releaseYear;
        if(genre == 'F' || genre == 'D') {
            releaseYear = stoi(line);
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
            int spaceIndex = line.find(' ');
            string firstName = line.substr(0, spaceIndex);
            line = line.erase(0, spaceIndex + 1);
            spaceIndex = line.find(' ');
            string lastName = line.substr(0, spaceIndex);
            line = line.erase(0, spaceIndex + 1);
            int month = stoi(line);
            spaceIndex = line.find(' ');
            line = line.erase(0, spaceIndex + 1);
            releaseYear = stoi(line);
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
