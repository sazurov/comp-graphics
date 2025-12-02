#include "../include/SafeTests.h"
#include <iostream>

void safeTest1(SafePackagedShipment &p) {
  std::cout << "[Тест ошибки 1: отрицательная продажа]\n";
  p.sell(-5);
}
void safeTest2(SafePackagedShipment &p) {
  std::cout << "[Тест ошибки 2: продажа 0]\n";
  p.sell(0);
}
void safeTest3(SafePackagedShipment &p) {
  std::cout << "[Тест ошибки 3: списание отрицательного]\n";
  p.writeOff(-2);
}
void safeTest4(SafePackagedShipment &p) {
  std::cout << "[Тест ошибки 4: списание 0]\n";
  p.writeOff(0);
}
void safeTest5(SafePackagedShipment &p) {
  std::cout << "[Тест ошибки 5: продажа больше остатка]\n";
  p.sell(10000);
}
void safeTest6(SafePackagedShipment &p) {
  std::cout << "[Тест ошибки 6: продажа упаковок больше остатка]\n";
  p.sellPack(1000);
}
void safeTest7(SafePackagedShipment &p) {
  std::cout << "[Тест 7: корректная продажа]\n";
  p.sell(2);
  p.writeOff(1);
  p.sellPack(1);
}
