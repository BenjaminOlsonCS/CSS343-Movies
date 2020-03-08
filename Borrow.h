#ifndef INC_343MOVIES_BORROW_H
#define INC_343MOVIES_BORROW_H


#include "string"
#include "Transaction.h"
#include "Movie.h"

using namespace std;

class Borrow : public Transaction
{
public:
    Borrow(char transChar, int cid, Movie* m);
    void doTrans() override;
    int getCustomerID() const;
    Movie* getMovie() const;
private:
    int customerID;
    Movie* movie;
};


#endif //INC_343MOVIES_BORROW_H
