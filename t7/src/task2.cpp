#include "../include/Account.h"
#include "../include/tasks.h"
#include <iostream>

using namespace std;

void task2() {
  cout << "\nЗадание 2: Статическая функция приветствия\n" << endl;

  cout << Account::greet() << endl;

  Account acc(5000.0);
  acc.display();

  cout << "\n" << Account::greet() << endl;
}
