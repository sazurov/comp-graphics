#include "../include/Menu.h"
#include "../include/SafePackagedShipment.h"
#include "../include/SafeTests.h"
#include "../include/Tests.h"

#include <algorithm> // std::replace
#include <iostream>
#include <limits>  // std::numeric_limits
#include <sstream> // std::istringstream

// ==================== Задание 1 ====================
void task1Menu() {
  std::string name;
  int d, m, y, qty;

  std::cout << "Введите наименование: ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                  '\n'); // очистка буфера
  std::getline(std::cin, name);

  std::cout << "Введите количество: ";
  std::cin >> qty;

  std::cout << "Введите дату (д м г или д/м/г): ";
  std::string dateStr;
  std::cin.ignore();
  std::getline(std::cin, dateStr);

  std::replace(dateStr.begin(), dateStr.end(), '/',
               ' '); // меняем '/' на пробел
  std::istringstream iss(dateStr);
  iss >> d >> m >> y;

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
    }

    s.printRest();
    s.printReport();
  }
}

// ==================== Задание 2 ====================
void task2Menu() {
  std::string name;
  int pp, packs, d, m, y;

  std::cout << "Введите наименование: ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(std::cin, name);

  std::cout << "Штук в упаковке: ";
  std::cin >> pp;
  std::cout << "Количество упаковок: ";
  std::cin >> packs;

  std::cout << "Введите дату (д м г или д/м/г): ";
  std::string dateStr;
  std::cin.ignore();
  std::getline(std::cin, dateStr);

  std::replace(dateStr.begin(), dateStr.end(), '/', ' ');
  std::istringstream iss(dateStr);
  iss >> d >> m >> y;

  PackagedShipment p;
  p.init(name, pp, packs, d, m, y);

  while (true) {
    std::cout << "\nВыберите действие:\n"
                 "1 — Продать 1 шт\n"
                 "2 — Продать N шт\n"
                 "3 — Списать 1 шт\n"
                 "4 — Списать N шт\n"
                 "5 — Продать упаковку\n"
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
    default:
      std::cout << "Неверный выбор!\n";
    }

    p.printRest();
  }
}

// ==================== Задание 3 ====================
void task3Menu() {
  std::string name;
  int pp, packs, d, m, y;

  std::cout << "Введите наименование: ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(std::cin, name);

  std::cout << "Штук в упаковке: ";
  std::cin >> pp;
  std::cout << "Количество упаковок: ";
  std::cin >> packs;

  std::cout << "Введите дату (д м г или д/м/г): ";
  std::string dateStr;
  std::cin.ignore();
  std::getline(std::cin, dateStr);

  std::replace(dateStr.begin(), dateStr.end(), '/', ' ');
  std::istringstream iss(dateStr);
  iss >> d >> m >> y;

  SafePackagedShipment p;
  p.init(name, pp, packs, d, m, y);

  while (true) {
    std::cout << "\nВыберите тест ошибки (1–7)\n0 — Выход\n> ";
    int t;
    std::cin >> t;

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
    }

    p.printRest();
    p.printReport();
  }
}
