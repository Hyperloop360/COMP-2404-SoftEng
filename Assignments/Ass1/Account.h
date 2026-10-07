#ifndef ACCOUNT_H
#define ACCOUNT_H

/*
 * Class: Account
 * Purpose: Represents a bank account belonging to a customer,
 *          storing its unique ID, customer ID, and balance, and
 *          providing operations for credit, debit, and printing.
 * Members:
 *   - acctId: integer representing the unique account ID
 *   - custId: integer representing the unique customer ID
 *   - balance: float representing the account balance
 */

class Account {
public:
  Account(int = 0, int = 0, float = 0.0f);
  int getId();
  bool credit(float);
  bool debit(float);
  void print();

private:
  int acctId;
  int custId;
  float balance;
};

#endif
