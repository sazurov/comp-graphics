#include "../include/Account.h"
#include <iostream>

using namespace std;

double Account::totalMoneyInCashbox = 0.0;

Account::Account(double balance)
    : accountName("Счёт"), balance(balance), expense(0.0), income(0.0),
      remainder(balance) {
  totalMoneyInCashbox += balance;
}

void Account::addExpense(double sum) {
  expense += sum;
  remainder -= sum;
  totalMoneyInCashbox -= sum;
}

void Account::addIncome(double sum) {
  income += sum;
  remainder += sum;
  totalMoneyInCashbox += sum;
}

void Account::display() const {
  cout << "\nИнформация о счёте:" << endl;
  cout << "Название: " << accountName << endl;
  cout << "Сальдо: " << balance << endl;
  cout << "Расход: " << expense << endl;
  cout << "Доход: " << income << endl;
  cout << "Остаток: " << remainder << endl;
  cout << "Всего денег в кассе: " << totalMoneyInCashbox << endl;
}

string Account::greet() { return "Вас приветствует Наш Банк"; }

double Account::getTotalMoney() { return totalMoneyInCashbox; }
