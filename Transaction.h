#ifndef INC_343MOVIES_TRANSACTION_H
#define INC_343MOVIES_TRANSACTION_H


#include <string>

using namespace std;

class Transaction
{
public:
    Transaction(char transChar); //All transactions begin with their command type
    string getTransactionStr() const;

    char getTransChar() const;

protected:
    string transactionStr;
    char transactionChar;
};


#endif //INC_343MOVIES_TRANSACTION_H
