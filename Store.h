#ifndef PROGRAM4_STORE_H
#define PROGRAM4_STORE_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Store {
public:
    // default constructor
    Store();

    void buildMovie(ifstream& movieFile);
    void buildCustomer(ifstream& customerFile);
    void processTrans(ifstream& transFile);

    void displayInventory() const;

private:
// can't do this until Customer and Transaction classes are implemented
    /*
    Customer[] customers; //hashtable of customers
    //some hashing functions for customers
    bool addCustomer(Customer* patron); //adds a customer to the hashtable
    bool getCustomer(int searchKey, Customer*& patron) const; //searches for customer in
    //hashtable, searchKey type can change later
    int calcSearchKey(int searchKey); //Returns the array index that uses a hashfunction to
//find a customer, searchKey can change later

    vector<BSTree> genres; //size 3 for now, has Comedy at 0, Drama at 1, Classics at 2
*/
};

#endif //PROGRAM4_STORE_H
