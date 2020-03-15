#ifndef INC_343MOVIES_STORE_H
#define INC_343MOVIES_STORE_H


#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "BSTree.h"
#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"
#include "Customer.h"
#include "Inventory.h"
#include "History.h"
#include "Borrow.h"
#include "Return.h"

using namespace std;


class Store
{
public:

    Store(); //default constructor

    //~Store(); // destructor

    void buildMovie(ifstream &movieFile);

    void displayInventory() const;

    void addGenre(char genre); // add movie genre as a valid genre type, not used in this iteration.

    void buildCustomer(istream &customerFile); //uses hashtable
    void processTrans(istream &transFile); //Don't forget about invalid inputs

private:
    bool isValidGenre(char genre) const; // checks if genre from text file is valid
    BSTree *movies; // binary search tree that holds all movies in the store
    vector<char> genreTypes; // holds valid genres for the store

    const static int hashSize = 1009;
    Customer *customers[hashSize]; //hashtable of customers, 1000 maximum customers, 1009 is smallest prime above that.
    bool addCustomer(Customer *patron); //adds a customer to the hashtable
    bool getCustomer(int customerID, Customer *&patron) const; //searches for customer in customers hashtable
    Movie* makeMovie(char genre, string movieData);
};

#endif //INC_343MOVIES_STORE_H
