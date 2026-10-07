#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Account.h"
#include "Date.h"
#include "defs.h"

/*
 * Class: Transaction
 * Purpose: Represents a bank transaction (credit, debit, or other) performed on
 * a specific account, storing the type, account ID, amount, and date. Members:
 *   - type: TransactionType enumeration value
 *   - acctId: integer representing the target account ID
 *   - amount: float representing the transaction amount
 *   - date: Date object representing the transaction date
 */

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
