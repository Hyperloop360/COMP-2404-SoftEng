#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Account.h"
#include "defs.h"
#include <string>

/*
 * Class: Customer
 * Purpose: Represents a bank customer containing a unique ID, name,
 *          and a primitive array collection of Account objects.
 * Members:
 *   - custId: integer representing the unique customer ID
 *   - name: string representing the customer's name
 *   - accounts: primitive array storing Account objects
 *   - numAccounts: integer tracking the current number of accounts
 */

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
