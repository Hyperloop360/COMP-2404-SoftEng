#include <iomanip>
#include <iostream>
using namespace std;

#include "Account.h"

Account::Account(int id, int cId, float bal) {
  acctId = id;
  custId = cId;
  balance = bal;
}

int Account::getId() { return acctId; }

bool Account::credit(float amt) {
  if (amt <= 0.0f) {
    return false;
  }
  balance += amt;
  return true;
}

bool Account::debit(float amt) {
  if (amt <= 0.0f) {
    return false;
  }
  if (balance - amt < 0.0f) {
    return false;
  }
  balance -= amt;
  return true;
}

void Account::print() {
  cout << "Account ID: " << acctId << ", Customer ID: " << custId
       << ", Balance: $" << fixed << setprecision(2) << balance << endl;
}
