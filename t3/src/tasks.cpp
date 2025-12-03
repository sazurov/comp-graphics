#include "../include/tasks.h"
#include "../include/PackagedProduct.h"
#include "../include/ProductBatch.h"
#include "../include/SafePackagedProduct.h"
#include "../include/tests.h"
#include <iostream>

using namespace std;

void task1() {
  cout << "\nЗадание 1: Базовый класс товарной партии\n" << endl;

  ProductBatch batch;

  string name;
  int qty, day, month, year;

  cout << "Введите наименование товара: ";
  cin.ignore();
  getline(cin, name);
  cout << "Введите количество: ";
  cin >> qty;
  cout << "Введите дату поставки (день месяц год): ";
  cin >> day >> month >> year;

  batch.initialize(qty, name, day, month, year);

  int choice;

  do {
    cout << "\n=== Меню тестов задания 1 ===" << endl;
    cout << "1 — test1" << endl;
    cout << "2 — test2" << endl;
    cout << "3 — test3" << endl;
    cout << "0 — Вернуться в главное меню" << endl;
    cout << "Выбор: ";
    cin >> choice;

    switch (choice) {
    case 1:
      test1(batch);
      batch.showRemainder();
      batch.showFullReport();
      break;
    case 2:
      test2(batch);
      batch.showRemainder();
      batch.showFullReport();
      break;
    case 3:
      test3(batch);
      batch.showRemainder();
      batch.showFullReport();
      break;

    case 0:
      break;

    default:
      cout << "Неверный номер теста" << endl;
    }

  } while (choice != 0);
}

void task2() {
  cout << "\nЗадание 2: Упакованный товар\n" << endl;

  PackagedProduct product;

  string name;
  int itemsPer, packages, day, month, year;

  cout << "Введите наименование товара: ";
  cin.ignore();
  getline(cin, name);
  cout << "Введите количество в упаковке: ";
  cin >> itemsPer;
  cout << "Введите количество упаковок: ";
  cin >> packages;
  cout << "Введите дату поставки (день месяц год): ";
  cin >> day >> month >> year;

  product.initialize(itemsPer, packages, name, day, month, year);

  int choice;

  do {
    cout << "\n=== Меню задания 2 ===" << endl;
    cout << "1 — Ручной режим" << endl;
    cout << "2 — testPackaged1" << endl;
    cout << "3 — testPackaged2" << endl;
    cout << "4 — testPackaged3" << endl;
    cout << "0 — Вернуться в главное меню" << endl;
    cout << "Выбор: ";
    cin >> choice;

    switch (choice) {
    case 1: {
      int c;
      do {
        cout << "\n--- Операции ---" << endl;
        cout << "1 - Продать 1 шт." << endl;
        cout << "2 - Продать произвольное количество" << endl;
        cout << "3 - Списать 1 шт." << endl;
        cout << "4 - Списать произвольное количество" << endl;
        cout << "5 - Продать упаковку" << endl;
        cout << "6 - Продать несколько упаковок" << endl;
        cout << "7 - Показать остаток" << endl;
        cout << "8 - Показать полный отчёт" << endl;
        cout << "0 - Выход из ручного режима" << endl;
        cout << "Выбор: ";
        cin >> c;

        int amount;
        switch (c) {
        case 1:
          product.sell();
          break;
        case 2:
          cout << "Введите количество: ";
          cin >> amount;
          product.sell(amount);
          break;
        case 3:
          product.writeOff();
          break;
        case 4:
          cout << "Введите количество: ";
          cin >> amount;
          product.writeOff(amount);
          break;
        case 5:
          product.sellPackage();
          break;
        case 6:
          cout << "Введите количество упаковок: ";
          cin >> amount;
          product.sellPackage(amount);
          break;
        case 7:
          product.showRemainder();
          break;
        case 8:
          product.showFullReport();
          break;
        }
      } while (c != 0);
      break;
    }

    case 2:
      testPackaged1(product);
      product.showFullReport();
      break;

    case 3:
      testPackaged2(product);
      product.showFullReport();
      break;

    case 4:
      testPackaged3(product);
      product.showFullReport();
      break;

    case 0:
      break;

    default:
      cout << "Неверный выбор" << endl;
    }

  } while (choice != 0);
}

void task3() {
  cout << "\nЗадание 3: Безопасный упакованный товар\n" << endl;

  SafePackagedProduct product;
  product.initialize(10, 10, "Тестовый товар", 1, 12, 2024);

  int choice;

  do {
    cout << "\n=== Меню тестов задания 3 ===" << endl;
    cout << "1 — errorTest1" << endl;
    cout << "2 — errorTest2" << endl;
    cout << "3 — errorTest3" << endl;
    cout << "4 — errorTest4" << endl;
    cout << "0 — Вернуться в главное меню" << endl;
    cout << "Выбор: ";
    cin >> choice;

    switch (choice) {
    case 1:
      errorTest1(product);
      product.showFullReport();
      break;
    case 2:
      errorTest2(product);
      product.showFullReport();
      break;
    case 3:
      errorTest3(product);
      product.showFullReport();
      break;
    case 4:
      errorTest4(product);
      product.showFullReport();
      break;
    case 0:
      break;
    default:
      cout << "Неверный номер теста" << endl;
    }

  } while (choice != 0);
}
