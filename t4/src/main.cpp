#include "../include/tasks.h"
#include <iostream>

using namespace std;

int main() {
  int choice;

  do {
    cout << "\n========================================" << endl;
    cout << "Выберите задание:" << endl;
    cout << "1 - Поиск символа в строке" << endl;
    cout << "2 - Замена символа в строке" << endl;
    cout << "3 - Сортировка и поиск в массиве" << endl;
    cout << "0 - Выход" << endl;
    cout << "========================================" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;
    cin.ignore();

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
      cout << "Неверный выбор. Попробуйте снова." << endl;
    }
  } while (choice != 0);

  return 0;
}
