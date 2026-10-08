#include "defs.h"
#include <cstdlib>
#include <iostream>
using namespace std;

#include "Bank.h"

Bank::Bank(string n) {
  name = n;
  numCustomers = 0;
  numPendingTr = 0;
  numLoggedTr = 0;
}

void Bank::setName(string n) { name = n; }

bool Bank::addCustomer(int custId, string n) {
  if (numCustomers >= MAX_ARR_SIZE || containsCustomer(custId)) {
    return false;
  }
  Customer newCust(custId, n);
  customers[numCustomers] = newCust;
  numCustomers++;
  return true;
}

bool Bank::containsCustomer(int custId) {
  for (int i = 0; i < numCustomers; ++i) {
    if (customers[i].getId() == custId) {
      return true;
    }
  }
  return false;
}

Customer &Bank::findCustomer(int custId) {
  for (int i = 0; i < numCustomers; ++i) {
    if (customers[i].getId() == custId) {
      return customers[i];
    }
  }
  cout << "Error: Customer with ID " << custId << " not found." << endl;
  exit(1);
}

bool Bank::addAccount(int acctId, int custId, float initBalance) {
  if (!containsCustomer(custId)) {
    cout << "ERROR: customer " << custId << " not found" << endl;
    return false;
  }
  if (containsAccount(custId)) {
    return false;
  }
  Customer &cust = findCustomer(custId);
  return cust.addAccount(acctId, initBalance);
}

bool Bank::containsAccount(int accId) {
  for (int i = 0; i < numCustomers; ++i) {
    if (customers[i].containsAccount(accId)) {
      return true;
    }
  }
  return false;
}

Account &Bank::findAccount(int acctId) {
  for (int i = 0; i < numCustomers; ++i) {
    if (customers[i].containsAccount(acctId)) {
      return customers[i].findAccount(acctId);
    }
  }
  cout << "Error: Account with ID " << acctId << " not found." << endl;
  exit(1);
}

void Bank::addToTrArray(Transaction arr[], int &numTr, Transaction &newTr) {
  if (numTr >= MAX_ARR_SIZE) {
    return;
  }
  int i = 0;
  while (i < numTr && newTr.getDate().lessThan(arr[i].getDate())) {
    i++;
  }
  for (int j = numTr - 1; j >= i; --j) {
    arr[j + 1] = arr[j];
  }
  arr[i] = newTr;
  numTr++;
}

bool Bank::addTransaction(TransactionType t, int acctId, float amt, int yr,
                          int mth, int day) {
  if (!containsAccount(acctId)) {
    cout << "ERROR: account " << acctId << " not found" << endl;
    return false;
  }
  Transaction newTr(t, acctId, amt, yr, mth, day);
  addToTrArray(pendingTransactions, numPendingTr, newTr);
  return true;
}

void Bank::processTransactions() {
  int yr, mth, day;
  currentDate(yr, mth, day);
  Date today(day, mth, yr);

  Transaction tempPending[MAX_ARR_SIZE];
  int tempNum = 0;

  for (int i = 0; i < numPendingTr; ++i) {
    Transaction &tr = pendingTransactions[i];
    if (!today.lessThan(tr.getDate())) {
      if (!containsAccount(tr.getAcctId())) {
        cout << "Error: Account " << tr.getAcctId()
             << " associated with transaction not found." << endl;
      } else {
        Account &acct = findAccount(tr.getAcctId());
        if (tr.process(acct)) {
          addToTrArray(loggedTransactions, numLoggedTr, tr);
        }
      }
    } else {
      tempPending[tempNum++] = tr;
    }
  }

  for (int j = 0; j < tempNum; ++j) {
    pendingTransactions[j] = tempPending[j];
  }
  numPendingTr = tempNum;
}

void Bank::printCustomers() {
  cout << "Bank Name: " << name << endl;
  for (int i = 0; i < numCustomers; ++i) {
    customers[i].print();
  }
}

void Bank::printTransactions(Transaction arr[], int numTr) {
  for (int i = 0; i < numTr; ++i) {
    arr[i].print();
  }
}

void Bank::printPendingTr() {
  printTransactions(pendingTransactions, numPendingTr);
}

void Bank::printLoggedTr() {
  printTransactions(loggedTransactions, numLoggedTr);
}
