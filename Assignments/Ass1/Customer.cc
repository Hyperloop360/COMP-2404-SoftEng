
#include <cstdlib>
#include <iostream>
using namespace std;

#include "Customer.h"

Customer::Customer(int id, string n) {
  custId = id;
  name = n;
  numAccounts = 0;
}

int Customer::getId() { return custId; }

bool Customer::addAccount(int acctId, float acctBalance) {
  if (numAccounts >= MAX_ARR_SIZE) {
    return false;
  }
  Account newAcct(acctId, custId, acctBalance);
  accounts[numAccounts] = newAcct;
  numAccounts++;
  return true;
}

bool Customer::containsAccount(int acctId) {
  for (int i = 0; i < numAccounts; ++i) {
    if (accounts[i].getId() == acctId) {
      return true;
    }
  }
  return false;
}

Account &Customer::findAccount(int acctId) {
  for (int i = 0; i < numAccounts; ++i) {
    if (accounts[i].getId() == acctId) {
      return accounts[i];
    }
  }
  cout << "Error: Account with ID " << acctId << " not found for customer."
       << endl;
  exit(1);
}

void Customer::print() {
  cout << "Customer ID: " << custId << ", Name: " << name << endl;
  for (int i = 0; i < numAccounts; ++i) {
    cout << " ";
    accounts[i].print();
  }
}
