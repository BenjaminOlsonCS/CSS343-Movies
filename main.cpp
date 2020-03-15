#include <iostream>

#include "Store.h"
#include <fstream>


int main()
{

    Store s;
    ifstream customerFile;
    customerFile.open("data4customers.txt");
    s.buildCustomer(customerFile);
    customerFile.close();

    ifstream movieFile;
    movieFile.open("data4movies.txt");
    s.buildMovie(movieFile);
    movieFile.close();

    ifstream transactionFile;
    transactionFile.open("data4commands.txt");
    s.processTrans(transactionFile);
    transactionFile.close();
    return 0;
}