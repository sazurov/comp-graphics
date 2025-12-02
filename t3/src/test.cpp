#include "../include/Tests.h"
#include <iostream>

using namespace std;

// Shipment
void runTest1(Shipment &s) {
  cout << "[Тест 1]\n";
  s.sell(3);
  s.writeOff(2);
}
void runTest2(Shipment &s) {
  cout << "[Тест 2]\n";
  s.sell();
  s.sell(5);
  s.writeOff();
}
void runTest3(Shipment &s) {
  cout << "[Тест 3]\n";
  s.writeOff(10);
  s.sell(4);
}

// PackagedShipment
void runPackagedTest1(PackagedShipment &p) {
  cout << "[Тест фас. 1]\n";
  p.sellPack(1);
  p.sell(3);
}
void runPackagedTest2(PackagedShipment &p) {
  cout << "[Тест фас. 2]\n";
  p.sell(5);
  p.writeOff(2);
  p.sellPack(2);
}
void runPackagedTest3(PackagedShipment &p) {
  cout << "[Тест фас. 3]\n";
  p.sellPack(2);
  p.sell(7);
  p.writeOff(3);
}
