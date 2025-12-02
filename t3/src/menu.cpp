#include "../include/Menu.h"
#include "../include/PackagedShipment.h"
#include "../include/SafePackagedShipment.h"
#include "../include/SafeTests.h"
#include "../include/Tests.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

bool parseDate(const std::string &input, int &d, int &m, int &y) {
  char sep1, sep2;
  std::istringstream iss(input);
  if (!(iss >> d >> sep1 >> m >> sep2 >> y) || sep1 != '/' || sep2 != '/')
    return false;
  return true;
}

void task1Menu() {
  std::string name, dateStr;
  int d, m, y, qty;

  std::cout << "Введите наименование: ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(std::cin, name);

  std::cout << "Введите количество: ";
  std::cin >> qty;

  std::cout << "Введите дату (д/м/г): ";
  std::cin.ignore();
  std::getline(std::cin, dateStr);

  if (!parseDate(dateStr, d, m, y)) {
    std::cout << "Неверный формат даты! Используйте д/м/г\n";
    return;
  }

  Shipment s;
  s.init(name, qty, d, m, y);

  while (true) {
    std::cout << "\nВыберите тест (1–3)\n0 — Выход\n> ";
    int choice;
    std::cin >> choice;
    switch (choice) {
    case 0:
      return;
    case 1:
      runTest1(s);
      break;
    case 2:
      runTest2(s);
      break;
    case 3:
      runTest3(s);
      break;
    default:
      std::cout << "Неверный выбор!\n";
      continue;
    }
    s.printRest();
    s.printReport();
  }
}

void task2Menu() {
  std::string name, dateStr;
  int pp, packs, d, m, y;

  std::cout << "Введите наименование: ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(std::cin, name);

  std::cout << "Штук в упаковке: ";
  std::cin >> pp;
  std::cout << "Количество упаковок: ";
  std::cin >> packs;

  std::cout << "Введите дату (д/м/г): ";
  std::cin.ignore();
  std::getline(std::cin, dateStr);

  if (!parseDate(dateStr, d, m, y)) {
    std::cout << "Неверный формат даты! Используйте д/м/г\n";
    return;
  }

  PackagedShipment p;
  p.init(name, pp, packs, d, m, y);

  while (true) {
    std::cout << "\nВыберите действие:\n"
                 "1 — Продать 1 шт\n"
                 "2 — Продать N шт\n"
                 "3 — Списать 1 шт\n"
                 "4 — Списать N шт\n"
                 "5 — Продать упаковку\n"
                 "6 — Тест фас. 1\n"
                 "7 — Тест фас. 2\n"
                 "8 — Тест фас. 3\n"
                 "0 — Выход\n> ";
    int c;
    std::cin >> c;
    switch (c) {
    case 0:
      return;
    case 1:
      p.sell();
      break;
    case 2: {
      int n;
      std::cin >> n;
      p.sell(n);
      break;
    }
    case 3:
      p.writeOff();
      break;
    case 4: {
      int n;
      std::cin >> n;
      p.writeOff(n);
      break;
    }
    case 5: {
      int n;
      std::cin >> n;
      p.sellPack(n);
      break;
    }
    case 6:
      runPackagedTest1(p);
      break;
    case 7:
      runPackagedTest2(p);
      break;
    case 8:
      runPackagedTest3(p);
      break;
    default:
      std::cout << "Неверный выбор!\n";
      continue;
    }
    p.printRest();
  }
}

void task3Menu() {
  std::string name, dateStr;
  int pp, packs, d, m, y;

  std::cout << "Введите наименование: ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(std::cin, name);

  std::cout << "Штук в упаковке: ";
  std::cin >> pp;
  std::cout << "Количество упаковок: ";
  std::cin >> packs;

  std::cout << "Введите дату (д/м/г): ";
  std::cin.ignore();
  std::getline(std::cin, dateStr);

  if (!parseDate(dateStr, d, m, y)) {
    std::cout << "Неверный формат даты! Используйте д/м/г\n";
    return;
  }

  while (true) {
    std::cout << "\nВыберите тест ошибки (1–7)\n0 — Выход\n> ";
    std::string line;
    std::getline(std::cin, line);
    if (line.empty())
      continue;

    std::istringstream iss(line);
    int t;
    if (!(iss >> t)) {
      std::cout << "Неверный выбор!\n";
      continue;
    }

    SafePackagedShipment p;
    p.init(name, pp, packs, d, m, y);

    switch (t) {
    case 0:
      return;
    case 1:
      safeTest1(p);
      break;
    case 2:
      safeTest2(p);
      break;
    case 3:
      safeTest3(p);
      break;
    case 4:
      safeTest4(p);
      break;
    case 5:
      safeTest5(p);
      break;
    case 6:
      safeTest6(p);
      break;
    case 7:
      safeTest7(p);
      break;
    default:
      std::cout << "Неверный выбор!\n";
      continue;
    }

    p.printRest();
    p.printReport();
  }
}
