#include "Borrow.h"

Borrow::Borrow(char transChar, int cid, Movie *m) : Transaction(transChar)
{
    customerID = cid;
    movie = m;
}

//preconditions: movie is a valid movie and the transaction has already been added to a customer's history.
//postconditions: the movie's stock has decreased by one
void Borrow::doTrans(Movie *movie)
{
    movie->changeStock(transactionChar);
}

int Borrow::getCustomerID() const
{
    return customerID;
}

Movie *Borrow::getMovie() const
{
    return movie;
}