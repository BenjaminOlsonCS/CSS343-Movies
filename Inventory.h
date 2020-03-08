#ifndef INC_343MOVIES_INVENTORY_H
#define INC_343MOVIES_INVENTORY_H

#include "Transaction.h"

class Inventory : public Transaction
{
public:
Inventory(char commandChar) : Transaction(commandChar) {};
void doTrans() override;
};

#endif //INC_343MOVIES_INVENTORY_H
