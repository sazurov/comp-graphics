#include "../include/SafePackagedProduct.h"
#include <iostream>

using namespace std;

SafePackagedProduct::SafePackagedProduct() : PackagedProduct() {}

void SafePackagedProduct::sell(int amount) {
  cout << "Вызов: sell(" << amount << ") с проверкой" << endl;

  if (amount <= 0) {
    cout << "ОШИБКА: количество для продажи должно быть положительным числом!"
         << endl;
    return;
  }

  int remainder = getRemainder();
  if (amount > remainder) {
    cout << "ОШИБКА: недостаточно товара для продажи!" << endl;
    cout << "Запрошено: " << amount << " шт., доступно: " << remainder << " шт."
         << endl;
    return;
  }

  soldQuantity += amount;
  cout << "Продано: " << amount << " шт." << endl;
}

void SafePackagedProduct::writeOff(int amount) {
  cout << "Вызов: writeOff(" << amount << ") с проверкой" << endl;

  if (amount <= 0) {
    cout << "ОШИБКА: количество для списания должно быть положительным числом!"
         << endl;
    return;
  }

  int remainder = getRemainder();
  if (amount > remainder) {
    cout << "ОШИБКА: недостаточно товара для списания!" << endl;
    cout << "Запрошено: " << amount << " шт., доступно: " << remainder << " шт."
         << endl;
    return;
  }

  writtenOffQuantity += amount;
  cout << "Списано: " << amount << " шт." << endl;
}

void SafePackagedProduct::sellPackage(int packageCount) {
  cout << "Вызов: sellPackage(" << packageCount << ") с проверкой" << endl;

  if (packageCount <= 0) {
    cout << "ОШИБКА: количество упаковок должно быть положительным числом!"
         << endl;
    return;
  }

  int remainder = getRemainder();
  int fullPackages = remainder / itemsPerPackage;

  if (fullPackages < packageCount) {
    cout << "ОШИБКА: недостаточно целых упаковок для продажи!" << endl;
    cout << "Запрошено: " << packageCount
         << " упак., доступно: " << fullPackages << " упак." << endl;
    return;
  }

  soldQuantity += packageCount * itemsPerPackage;
  cout << "Продано упаковок: " << packageCount << endl;
}
