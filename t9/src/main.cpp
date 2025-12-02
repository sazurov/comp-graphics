#include "../include/tasks.h"
#include <iostream>

using namespace std;

int main() {
  int choice;

  do {
    cout << "\n========================================" << endl;
    cout << "Выберите действие:" << endl;
    cout << "1 - Работа с ФИО в файлах" << endl;
    cout << "0 - Выход" << endl;
    cout << "========================================" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;

    switch (choice) {
    case 1:
      task1();
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
