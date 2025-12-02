#include "../include/SafeTests.h"
#include <iostream>

void safeTest1(SafePackagedShipment &p) {
  std::cout << "\n[SafeTest1 — отрицательная покупка]\n";
  p.sell(-5);
}

void safeTest2(SafePackagedShipment &p) {
  std::cout << "\n[SafeTest2 — нулевая покупка]\n";
  p.sell(0);
}

void safeTest3(SafePackagedShipment &p) {
  std::cout << "\n[SafeTest3 — покупка больше остатка]\n";
  p.sell(10000);
}

void safeTest4(SafePackagedShipment &p) {
  std::cout << "\n[SafeTest4 — отрицательное списание]\n";
  p.writeOff(-3);
}

void safeTest5(SafePackagedShipment &p) {
  std::cout << "\n[SafeTest5 — продажа упаковок с отрицанием]\n";
  p.sellPack(-2);
}

void safeTest6(SafePackagedShipment &p) {
  std::cout << "\n[SafeTest6 — продажа упаковок без остатка]\n";
  p.sellPack(100);
}

void safeTest7(SafePackagedShipment &p) {
  std::cout << "\n[SafeTest7 — списание больше остатка]\n";
  p.writeOff(9999);
}
