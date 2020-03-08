//
// Created by Benjamin on 3/7/2020.
//

#ifndef INC_343MOVIES_RETURN_H
#define INC_343MOVIES_RETURN_H


#include "Transaction.h"
#include "Movie.h"
#include <string>
using namespace std;

class Return : public Transaction
{
public:
Return(char commandChar, int customerIDinpt, Movie* movieInpt);

void doTrans() override;
int getCustomerID() const;
Movie* getMovie() const;

private:
int customerID;
Movie *movie;
};



#endif //INC_343MOVIES_RETURN_H
