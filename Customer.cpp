#include "Customer.h"
#include <iostream>

Customer::Customer()
{
    customerID = -1;
    lastName = "";
    firstName = "";
}

Customer::Customer(int id, string last, string first)
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
    if (!history.empty())
    {
        for (int i = 0; i < history.size(); i++)
        {
            cout << history.at(i);
            cout << endl;
        }
    }
    else
        cout << "No history to display for customer: " << customerID << endl;
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

//Used to determine if a customer is currently borrowing a movie, in order to check to see if they can return it.
bool Customer::hasBorrowedMovie(string transactionStr)
{
    cout << "have dey borrowed it doe?" << endl;
    int borrowCount = 0,returnCount = 0;
    for(int i = 0; i < history.size(); i++)
    {
        if(transactionStr.substr(2) == history.at(i).substr(2))
        {
            if(history.at(i).at(0) == 'B')
            {
                borrowCount++;
            }
            else if(history.at(i).at(0) == 'R')
            {
                returnCount++;
            }
        }
    }
    return returnCount < borrowCount;
}