#include "Transaction.h"

Transaction::Transaction(char transChar)
{
    transactionChar = transChar;
}

string Transaction::getTransactionStr() const
{
    return transactionStr;
}

char Transaction::getTransChar() const
{
    return transactionChar;
}

