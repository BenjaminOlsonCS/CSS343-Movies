#ifndef INC_343MOVIES_CUSTOMER_H
#define INC_343MOVIES_CUSTOMER_H


#include "Transaction.h"
#include <vector>

class Customer
{
public:

    Customer(int id, string& lastName, string& firstName);

    string getFirstName() const;
    string getLastName() const;
    int getID() const;
    void addTrans(string& trans); //add a Transaction to a customer’s Transaction
    void displayHistory() const; //outputs the Transaction linked list for the customer

private:
    int customerID;
    string lastName;
    string firstName;
    vector<string> history; // vector of transaction strings
    // list containing each transaction a customer has completed
};



#endif //INC_343MOVIES_CUSTOMER_H
