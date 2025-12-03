#include "../include/tasks.h"
#include <iostream>

using namespace std;

int main() {
  int choice;

  do {
    cout << "\n========================================" << endl;
    cout << "Система учёта товарных партий" << endl;
    cout << "========================================" << endl;
    cout << "1 - Задание 1 (базовый класс)" << endl;
    cout << "2 - Задание 2 (упакованный товар)" << endl;
    cout << "3 - Задание 3 (тесты ошибок)" << endl;
    cout << "0 - Выход" << endl;
    cout << "Выбор: ";
    cin >> choice;

    switch (choice) {
    case 1:
      task1();
      break;
    case 2:
      task2();
      break;
    case 3:
      task3();
      break;
    case 0:
      cout << "Выход из программы." << endl;
      break;
    default:
      cout << "Неверный выбор" << endl;
    }
  } while (choice != 0);

  return 0;
}
