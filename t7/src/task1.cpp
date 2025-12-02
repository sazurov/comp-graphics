#include "../include/Account.h"
#include "../include/tasks.h"
#include <iostream>

using namespace std;

void task1() {
  cout << "\nЗадание 1: Класс Account с статическим полем\n" << endl;

  Account acc1(1000.0);
  acc1.display();

  cout << "\nДобавляем расход 200:" << endl;
  acc1.addExpense(200.0);
  acc1.display();

  cout << "\nДобавляем доход 500:" << endl;
  acc1.addIncome(500.0);
  acc1.display();

  cout << "\nСоздаём второй счёт с сальдо 2000:" << endl;
  Account acc2(2000.0);
  acc2.display();

  cout << "\nПроверяем первый счёт (ВсегоДенегВКассе должно увеличиться):"
       << endl;
  acc1.display();
}
