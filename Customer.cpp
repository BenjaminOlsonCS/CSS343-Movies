#include "Customer.h"
#include <iostream>

Customer::Customer(int id, string& last, string& first)
{
    customerID = id;
    lastName = last;
    firstName = first;
}

// Adds a transaction to a customer's history.
void Customer::addTrans(string &trans)
{
    history.push_back(trans);
}

// Displays the history of transactions for a customer
void Customer::displayHistory() const
{
    if(!history.empty())
    {
        for(int i = 0; i < history.size(); i++)
        {
            cout << history.at(i);
            cout << endl;
        }
    }
}


string Customer::getFirstName() const
{
    return firstName;
}

string Customer::getLastName() const
{
    return lastName;
}

int Customer::getID() const
{
    return customerID;
}

