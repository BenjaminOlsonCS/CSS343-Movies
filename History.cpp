#include "History.h"
#include "Customer.h"

History::History(char commandChar, int customerIDinpt) : Transaction(commandChar)
{
    customerID = customerIDinpt;
}

int History::getCustomerID() const
{
    return customerID;
}

void History::doTrans(Customer *customer)
{
    customer->displayHistory();
}