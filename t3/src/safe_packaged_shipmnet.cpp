#include "../include/SafePackagedShipment.h"
#include <iostream>

using namespace std;

bool SafePackagedShipment::checkNegative(int value, const char *action) const {
  if (value < 0) {
    cout << "Ошибка: отрицательное значение для " << action << "\n";
    return true;
  }
  return false;
}

bool SafePackagedShipment::checkZero(int value, const char *action) const {
  if (value == 0) {
    cout << "Ошибка: нулевое значение для " << action << "\n";
    return true;
  }
  return false;
}

bool SafePackagedShipment::checkEnough(int value, const char *action) const {
  if (value > (quantity - sold - writtenOff)) {
    cout << "Ошибка: недостаточно товара для " << action << "\n";
    return true;
  }
  return false;
}

void SafePackagedShipment::sell(int count) {
  if (checkNegative(count, "Продажа") || checkZero(count, "Продажа") ||
      checkEnough(count, "Продажа"))
    return;
  PackagedShipment::sell(count);
}

void SafePackagedShipment::writeOff(int count) {
  if (checkNegative(count, "Списание") || checkZero(count, "Списание") ||
      checkEnough(count, "Списание"))
    return;
  PackagedShipment::writeOff(count);
}

void SafePackagedShipment::sellPack(int packs) {
  if (checkNegative(packs, "Продажа упаковок") ||
      checkZero(packs, "Продажа упаковок"))
    return;
  int need = packs * perPack;
  if (need > (quantity - sold - writtenOff)) {
    cout << "Ошибка: недостаточно товара для продажи упаковок\n";
    return;
  }
  PackagedShipment::sellPack(packs);
}
