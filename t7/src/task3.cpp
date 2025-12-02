#include "../include/Bank.h"
#include "../include/MicroBank.h"
#include "../include/tasks.h"
#include <iostream>

using namespace std;

void task3() {
  cout << "\nЗадание 3: Наследование и виртуальные функции\n" << endl;

  Bank bank(5.0);
  MicroBank microBank(3.0, 5.0);

  double sum = 10000.0;

  cout << "Расчёт для суммы " << sum << ":\n" << endl;

  cout << "Обычный банк:" << endl;
  bank.GetPercent(sum);

  cout << "\nМикробанк:" << endl;
  microBank.GetPercent(sum);

  cout << "\nПолиморфизм через указатель на базовый класс:" << endl;
  Bank *ptr1 = &bank;
  Bank *ptr2 = &microBank;

  cout << "Через указатель на Bank (обычный банк):" << endl;
  ptr1->GetPercent(sum);

  cout << "Через указатель на Bank (микробанк):" << endl;
  ptr2->GetPercent(sum);
}
