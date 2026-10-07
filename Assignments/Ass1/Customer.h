#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Account.h"
#include "defs.h"
#include <string>

class Customer {
public:
  Customer(int = 0, string = "");
  int getId();
  bool addAccount(int acctId, float acctBalance);
  bool containsAccount(int acctId);
  Account &findAccount(int acctid);
  void print();

private:
  int custId;
  string name;
  Account accounts[MAX_ARR_SIZE];
  int numAccounts;
};

#endif
