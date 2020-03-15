#include "Return.h"

Return::Return(char commandChar, int customerIDinpt, Movie *movieInpt) : Transaction(commandChar)
{
    movie = movieInpt;
    customerID = customerIDinpt;
}

//preconditions: movie is a valid movie and the transaction has already been added to a customer's history.
//postconditions: the movie's stock has increased by one
void Return::doTrans(Movie *movie)
{
    movie->changeStock(transactionChar);
}

int Return::getCustomerID() const
{
    return customerID;
}

Movie *Return::getMovie() const
{
    return movie;
}
