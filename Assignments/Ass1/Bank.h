#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include "Customer.h"
#include "Transaction.h"
#include "defs.h"
#include <string>

/*
 * Class: Bank
 * Purpose: Manages the bank's name, collection of customers, collection of
 *          pending transactions, and collection of logged transactions,
 *          providing operations to add customers, accounts, and transactions,
 *          process pending transactions in date order, and print reports.
 * Members:
 *   - name: string representing the bank name
 *   - customers: primitive array of Customer objects
 *   - numCustomers: integer tracking the number of customers
 *   - pendingTransactions: primitive array of Transaction objects waiting to be
 * processed
 *   - numPendingTr: integer tracking the number of pending transactions
 *   - loggedTransactions: primitive array of Transaction objects that have been
 * processed
 *   - numLoggedTr: integer tracking the number of logged transactions
 */

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
