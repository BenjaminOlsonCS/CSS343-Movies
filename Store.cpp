#include "Store.h"

Store::Store() {
    // default constructor needs customer and transaction classes
    for(int i = 0; i < 3; i++)
        genres.push_back(new BSTree);
}

void Store::buildMovie(ifstream &movieFile) {
    char genre;
    movieFile >> genre;

    // check for movie genre
    if(genre == 'F') {
        char comma;
        movieFile >> comma;
        int stock;
        movieFile >> stock;
        movieFile >> comma;
        string director;
        getline(movieFile, director, ',');
        string title;
        getline(movieFile, title, ',');
        int releaseYear;
        movieFile >> releaseYear;
        Movie *com = new Comedy(genre, stock, director, title, releaseYear);
        genres[0] = new BSTree;
        genres[0]->insert(com);
    }





    // pseudo code method
    /*
     * read char for genre.
     * if else statement to build for class of genre.
     * read expected variables of genre type,
     * (assume correct formatting).
     * instantiate object of genre type with parameters.
     * add object to appropriate index of vector<BST>
     */
}
