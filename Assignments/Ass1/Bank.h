#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include "Customer.h"
#include "Transaction.h"
#include "defs.h"
#include <string>

class Bank {
public:
  Bank(string = "Bank");
  void setName(string);

  bool addCustomer(int custId, string n);
  bool containsCustomer(int custId);
  Customer &findCustomer(int custId);

  bool addAccount(int acctId, int custId, float initBalance);
  bool containsAccount(int acctId);
  Account &findAccount(int accId);

  void addToTrArray(Transaction arr[], int &numTr, Transaction &newTr);
  bool addTransaction(TransactionType t, int acctId, float amt, int yr, int mth,
                      int day);
  void processTransactions();
  void printCustomers();
  void printTransactions(Transaction arr[], int numTr);
  void printPendingTr();
  void printLoggedTr();

private:
  string name;
  Customer customers[MAX_ARR_SIZE];
  int numCustomers;
  Transaction pendingTransactions[MAX_ARR_SIZE];
  int numPendingTr;
  Transaction loggedTransactions[MAX_ARR_SIZE];
  int numLoggedTr;
};

#endif
