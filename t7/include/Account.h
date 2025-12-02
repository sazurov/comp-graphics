#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
  std::string accountName;
  double balance;
  double expense;
  double income;
  double remainder;
  static double totalMoneyInCashbox;

public:
  Account(double balance);

  void addExpense(double sum);
  void addIncome(double sum);

  void display() const;

  static std::string greet();
  static double getTotalMoney();
};

#endif // ACCOUNT_H
