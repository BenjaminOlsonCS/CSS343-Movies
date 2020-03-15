#ifndef INC_343MOVIES_CUSTOMER_H
#define INC_343MOVIES_CUSTOMER_H

#include <string>
#include <vector>
using namespace std;

class Customer
{
public:
    Customer();

    Customer(int id, string lastName, string firstName);

    string getFirstName() const;

    string getLastName() const;

    int getID() const;

    void addTrans(string &trans); //add a Transaction to a customer’s Transaction
    void displayHistory() const; //outputs the Transaction linked list for the customer
    bool hasBorrowedMovie(string transactionStr);
private:
    int customerID;
    string lastName;
    string firstName;
    vector<string> history; // vector of transaction strings
    // list containing each transaction a customer has completed
};


#endif //INC_343MOVIES_CUSTOMER_H
