#include "../include/Account.h"
#include <iostream>

Account::Account(const std::string &name, double balance)
    : name(name), balance(balance), expense(0.0), income(0.0) {}

std::string Account::getName() const { return name; }

double Account::getBalance() const { return balance; }

double Account::getExpense() const { return expense; }

double Account::getIncome() const { return income; }

Account &Account::operator++() {
  income += 1.0;
  balance += 1.0;
  return *this;
}

Account &Account::operator--() {
  expense += 1.0;
  balance -= 1.0;
  return *this;
}

Account &Account::operator+(double value) {
  if (value > 0) {
    income += value;
    balance += value;
  } else if (value < 0) {
    double expense_value = value * -1;
    expense += expense_value;
    balance -= expense_value;
  }
  return *this;
}

void Account::display() const {
  std::cout << "Счёт: " << name << std::endl;
  std::cout << "  Остаток: " << balance << std::endl;
  std::cout << "  Доход: " << income << std::endl;
  std::cout << "  Расход: " << expense << std::endl;
}
