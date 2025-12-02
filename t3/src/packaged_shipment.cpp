#include "../include/PackagedShipment.h"
#include <iostream>

PackagedShipment::PackagedShipment() : Shipment(), perPack(1) {}

PackagedShipment::PackagedShipment(const std::string &n, int pp, int packs,
                                   int d, int m, int y) {
  init(n, pp, packs, d, m, y);
}

void PackagedShipment::init(const std::string &n, int pp, int packs, int d,
                            int m, int y) {
  name = n;
  perPack = pp;
  quantity = pp * packs;
  sold = 0;
  writtenOff = 0;
  day = d;
  month = m;
  year = y;
  std::cout << "[Инициализация упаковок] " << name << ", в упаковке=" << perPack
            << ", упаковок=" << packs << "\n";
}

void PackagedShipment::sell(int count) {
  sold += count;
  std::cout << "[Продажа] " << count << " шт\n";
}

void PackagedShipment::writeOff(int count) {
  writtenOff += count;
  std::cout << "[Списание] " << count << " шт\n";
}

void PackagedShipment::sellPack(int packs) {
  int need = packs * perPack;
  if (need > (quantity - sold - writtenOff)) {
    std::cout << "Ошибка: недостаточно товара для продажи упаковок\n";
    return;
  }
  sold += need;
  std::cout << "[Продажа] " << packs << " упаковок (" << need << " шт)\n";
}

void PackagedShipment::printRest() const {
  int rest = quantity - sold - writtenOff;
  std::cout << "[Остаток] " << name << ": " << rest << " шт, " << rest / perPack
            << " целых упаковок\n";
}

void PackagedShipment::printReport() const {
  std::cout << "[Отчёт] " << name << "\n"
            << "Поставлено: " << quantity << "\n"
            << "Продано: " << sold << "\n"
            << "Списано: " << writtenOff << "\n";
}
