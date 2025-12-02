#include "../include/Bank.h"
#include <iostream>

using namespace std;

Bank::Bank(double bankPercent) : bankPercent(bankPercent) {}

void Bank::GetPercent(double sum) const {
  double percent = sum * bankPercent / 100.0;
  cout << "Ваш процент по банку составляет: " << percent << endl;
}
