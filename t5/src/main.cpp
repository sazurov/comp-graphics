#include "../include/tests.h"
#include <iostream>

using namespace std;

int main() {
  int choice;

  do {
    cout << "\n========================================" << endl;
    cout << "Выберите задание:" << endl;
    cout << "1 - Тестирование класса Car" << endl;
    cout << "2 - Тестирование класса Account" << endl;
    cout << "0 - Выход" << endl;
    cout << "========================================" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;

    switch (choice) {
    case 1:
      testCar();
      break;
    case 2:
      testAccount();
      break;
    case 0:
      cout << "Выход из программы." << endl;
      break;
    default:
      cout << "Неверный выбор. Попробуйте снова." << endl;
    }
  } while (choice != 0);

  return 0;
}
