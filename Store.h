#ifndef PROGRAM4_STORE_H
#define PROGRAM4_STORE_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "BSTree.h"
#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"

using namespace std;

class Store {
public:
    Store(); // default constructor

    //~Store(); // destructor

    void buildMovie(ifstream& movieFile);
    void buildCustomer(ifstream& customerFile);
    void processTrans(ifstream& transFile);

    void displayInventory() const;
    void addGenre(char genre); // add movie genre as a valid genre type

private:
    static Movie* makeMovie(char genre);
    /*
    Customer[] customers; //hashtable of customers
    //some hashing functions for customers
    bool addCustomer(Customer* patron); //adds a customer to the hashtable
    bool getCustomer(int searchKey, Customer*& patron) const; //searches for customer in
    //hashtable, searchKey type can change later
    int calcSearchKey(int searchKey); //Returns the array index that uses a hashfunction to
//find a customer, searchKey can change later
*/
    bool isValidGenre(char genre) const; // checks if genre from text file is valid
    BSTree* movies; // binary search tree that holds all movies in the store
    vector<char> genreTypes; // holds valid genres for the store
};

#endif //PROGRAM4_STORE_H
