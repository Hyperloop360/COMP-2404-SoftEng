#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Account.h"
#include "Date.h"
#include "defs.h"

class Transaction {
public:
  Transaction(TransactionType = TR_OTHER, int = 0, float = 0.0f, int = 2000,
              int = 1, int = 1);
  int getAcctId();
  Date &getDate();
  bool process(Account &acct);
  void print();

private:
  TransactionType type;
  int acctId;
  float amount;
  Date date;
};

#endif
