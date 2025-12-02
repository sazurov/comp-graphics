#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
  std::string name;
  double balance;
  double expense;
  double income;

public:
  Account(const std::string &name, double balance = 0.0);

  std::string getName() const;
  double getBalance() const;
  double getExpense() const;
  double getIncome() const;

  Account &operator++();
  Account &operator--();
  Account &operator+(double value);

  void display() const;
};

#endif // ACCOUNT_H
