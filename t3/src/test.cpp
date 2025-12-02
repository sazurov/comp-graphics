#include "../include/Tests.h"
#include <iostream>

void runTest1(Shipment &s) {
  std::cout << "[Тест 1]\n";
  s.sell(3);
  s.writeOff(2);
}

void runTest2(Shipment &s) {
  std::cout << "[Тест 2]\n";
  s.sell();
  s.sell(5);
  s.writeOff();
}

void runTest3(Shipment &s) {
  std::cout << "[Тест 3]\n";
  s.writeOff(10);
  s.sell(4);
}

void runPackagedTest1(PackagedShipment &p) {
  std::cout << "[Тест фас. 1]\n";
  p.sellPack(1);
  p.sell(3);
}

void runPackagedTest2(PackagedShipment &p) {
  std::cout << "[Тест фас. 2]\n";
  p.sell(5);
  p.writeOff(2);
  p.sellPack(2);
}
