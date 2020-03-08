#include "Borrow.h"

Borrow::Borrow(char transChar, int cid, Movie *m) : Transaction(transChar)
{
    customerID = cid;
    movie = m;
}

void Borrow::doTrans()
{
    //todo: find the corresponding movie in the BST, (or an alternative if it is a classic), and decrease its stock by 1.
}

int Borrow::getCustomerID() const
{
    return customerID;
}

Movie *Borrow::getMovie() const
{
    return movie;
}