#ifndef INC_343MOVIES_HISTORY_H
#define INC_343MOVIES_HISTORY_H

#include "Transaction.h"

class Customer;

class History : public Transaction
{
public:
    History(char commandChar, int customerIDinpt);

    int getCustomerID() const;

    void doTrans(Customer *customer);

private:
    int customerID;
};

#endif //INC_343MOVIES_HISTORY_H
