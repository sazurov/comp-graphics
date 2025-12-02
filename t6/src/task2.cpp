#include "../include/tasks.h"
#include <iostream>

using namespace std;

void decrement(int x) {
  x--;
  cout << "Внутри decrement(int x): x = " << x << endl;
}

void decrement(int *x) {
  (*x)--;
  cout << "Внутри decrement(int* x): *x = " << *x << endl;
}

void task2() {
  cout << "\nЗадание 2: Декремент с указателем и без\n" << endl;

  int value1 = 10;
  int value2 = 20;

  cout << "Тест decrement(int x):" << endl;
  cout << "До вызова: value1 = " << value1 << endl;
  decrement(value1);
  cout << "После вызова: value1 = " << value1 << " (не изменилось)" << endl;

  cout << "\nТест decrement(int* x):" << endl;
  cout << "До вызова: value2 = " << value2 << endl;
  decrement(&value2);
  cout << "После вызова: value2 = " << value2 << " (изменилось)" << endl;
}
