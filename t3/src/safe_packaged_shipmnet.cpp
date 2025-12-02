#include "../include/SafePackagedShipment.h"
#include <iostream>

SafePackagedShipment::SafePackagedShipment() : PackagedShipment() {}

bool SafePackagedShipment::checkNegative(int value, const char *action) const {
  if (value < 0) {
    std::cout << "[Ошибка] " << action << ": отрицательное количество!\n";
    return true;
  }
  return false;
}

bool SafePackagedShipment::checkZero(int value, const char *action) const {
  if (value == 0) {
    std::cout << "[Предупреждение] " << action << ": количество равно 0.\n";
    return true;
  }
  return false;
}

bool SafePackagedShipment::checkEnough(int value, const char *action) const {
  if (value > quantity) {
    std::cout << "[Ошибка] " << action
              << ": недостаточно товара! Остаток = " << quantity << "\n";
    return true;
  }
  return false;
}

void SafePackagedShipment::sell(int count) {
  if (checkNegative(count, "Продажа"))
    return;
  if (checkZero(count, "Продажа"))
    return;
  if (checkEnough(count, "Продажа"))
    return;

  PackagedShipment::sell(count);
}

void SafePackagedShipment::writeOff(int count) {
  if (checkNegative(count, "Списание"))
    return;
  if (checkZero(count, "Списание"))
    return;
  if (checkEnough(count, "Списание"))
    return;

  PackagedShipment::writeOff(count);
}

void SafePackagedShipment::sellPack(int packs) {
  if (checkNegative(packs, "Продажа упаковок"))
    return;
  if (checkZero(packs, "Продажа упаковок"))
    return;

  int need = packs * perPack;

  if (quantity < need) {
    std::cout << "[Ошибка] Продажа упаковок: недостаточно товара. Остаток = "
              << quantity << "\n";
    return;
  }

  PackagedShipment::sellPack(packs);
}
