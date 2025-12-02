#include "../include/MicroBank.h"
#include <iostream>

using namespace std;

MicroBank::MicroBank(double microPercent, double bankPercent)
    : Bank(bankPercent), microPercent(microPercent) {}

void MicroBank::GetPercent(double sum) const {
  double totalPercent = microPercent + bankPercent;
  double percent = sum * totalPercent / 100.0;
  cout << "Ваш процент по микробанку составляет: " << percent << endl;
}
