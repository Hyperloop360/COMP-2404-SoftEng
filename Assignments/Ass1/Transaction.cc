#include <iostream>
using namespace std;

#include "Transaction.h"

Transaction::Transaction(TransactionType t, int id, float amt, int yr, int mth,
                         int day)
    : type(t), acctId(id), amount(amt), date(day, mth, yr) {}

int Transaction::getAcctId() { return acctId; }

Date &Transaction::getDate() { return date; }

bool Transaction::process(Account &acct) {
  if (type == TR_DEBIT) {
    if (!acct.debit(amount)) {
      cout << "Error: Failed to process debit transaction of $" << amount
           << " on account " << acctId << "." << endl;
      return false;
    }
    return true;
  } else if (type == TR_CREDIT) {
    if (!acct.credit(amount)) {
      cout << "Error: Failed to process credit transaction of $" << amount
           << " on account " << acctId << "." << endl;
      return false;
    }
    return true;
  }
  cout << "Error: Unknown or unsupported transaction type." << endl;
  return false;
}

void Transaction::print() {
  string typeStr = "Other";
  if (type == TR_DEBIT) {
    typeStr = "Debit";
  } else if (type == TR_CREDIT) {
    typeStr = "Credit";
  }
  cout << "Type: " << typeStr << ", Account ID: " << acctId << ", Amount: $"
       << amount << ", Date: ";
  date.print();
}
