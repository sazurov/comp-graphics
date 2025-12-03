#include "../include/math_functions.h"
#include <iostream>

using namespace std;

int main() {
  int choice;

  do {
    cout << "\n========================================" << endl;
    cout << "Выберите задание:" << endl;
    cout << "1 - Простая версия (задание 1 + 2)" << endl;
    cout << "2 - Рекурсивная версия (задание 3)" << endl;
    cout << "0 - Выход" << endl;
    cout << "========================================" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;

    switch (choice) {
    case 1:
      userCommunication();
      break;
    case 2: {
      double totalSum = userCommunicationRecursive();
      cout << "Возвращённая сумма: " << totalSum << endl;
      break;
    }
    case 0:
      cout << "Выход из программы." << endl;
      break;
    default:
      cout << "Неверный выбор. Попробуйте снова." << endl;
    }
  } while (choice != 0);

  return 0;
}
