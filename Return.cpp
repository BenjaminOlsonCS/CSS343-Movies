#include "Return.h"

Return::Return(char commandChar, int customerIDinpt, Movie *movieInpt) : Transaction(commandChar)
{
    movie = movieInpt;
    customerID = customerIDinpt;
}

//Returns a movie by finding the correct movie in the BST and then increasing its stock by 1.
void Return::doTrans()
{
    //todo: find the correct movie in the BST and increase its stock by 1
}

int Return::getCustomerID() const
{
    return customerID;
}

Movie *Return::getMovie() const
{
    return movie;
}
