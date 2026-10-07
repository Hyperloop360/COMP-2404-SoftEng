#ifndef ACCOUNT_H
#define ACCOUNT_H

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
