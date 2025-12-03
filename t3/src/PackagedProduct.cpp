#include "../include/PackagedProduct.h"
#include <iostream>

using namespace std;

PackagedProduct::PackagedProduct()
    : ProductBatch(), itemsPerPackage(0), totalPackages(0) {}

void PackagedProduct::initialize(int itemsPer, int packages, const string &name,
                                 int d, int m, int y) {
  cout << "Вызов: initialize(" << itemsPer << " шт/упак, " << packages
       << " упак, \"" << name << "\", " << d << "." << m << "." << y << ")"
       << endl;
  itemsPerPackage = itemsPer;
  totalPackages = packages;
  quantity = itemsPer * packages;
  productName = name;
  day = d;
  month = m;
  year = y;
  soldQuantity = 0;
  writtenOffQuantity = 0;
}

void PackagedProduct::sellPackage(int packageCount) {
  cout << "Вызов: sellPackage(" << packageCount << ")" << endl;
  int remainder = getRemainder();
  int fullPackages = remainder / itemsPerPackage;

  if (fullPackages < packageCount) {
    cout << "Ошибка: недостаточно целых упаковок для продажи!" << endl;
    cout << "Доступно целых упаковок: " << fullPackages << endl;
    return;
  }

  soldQuantity += packageCount * itemsPerPackage;
}

void PackagedProduct::showRemainder() const {
  cout << "Вызов: showRemainder()" << endl;
  int remainder = getRemainder();
  int fullPackages = remainder / itemsPerPackage;
  cout << "Остаток товара \"" << productName << "\": " << remainder << " шт."
       << endl;
  cout << "В том числе целых упаковок: " << fullPackages << endl;
}

void PackagedProduct::showFullReport() const {
  cout << "Вызов: showFullReport()" << endl;
  cout << "\n--- Полный отчёт по партии ---" << endl;
  cout << "Наименование: " << productName << endl;
  cout << "Дата поставки: " << day << "." << month << "." << year << endl;
  cout << "Товара в упаковке: " << itemsPerPackage << " шт." << endl;
  cout << "Всего упаковок: " << totalPackages << endl;
  cout << "Количество в партии: " << quantity << " шт." << endl;
  cout << "Продано: " << soldQuantity << " шт." << endl;
  cout << "Списано: " << writtenOffQuantity << " шт." << endl;
  int remainder = getRemainder();
  cout << "Остаток: " << remainder << " шт." << endl;
  cout << "Целых упаковок в остатке: " << (remainder / itemsPerPackage) << endl;
}
