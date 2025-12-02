#include "../include/PackagedShipment.h"
#include <iostream>

PackagedShipment::PackagedShipment() : Shipment(), perPack(1) {}

PackagedShipment::PackagedShipment(const std::string &n, int pp, int packs,
                                   int d, int m, int y)
    : Shipment(n, pp * packs, d, m, y), perPack(pp) {}

void PackagedShipment::init(const std::string &n, int pp, int packs, int d,
                            int m, int y) {
  std::cout << "[Инициализация упаковок] " << n << ", в упаковке=" << pp
            << ", упаковок=" << packs << "\n";

  name = n;
  perPack = pp;
  quantity = pp * packs;
  day = d;
  month = m;
  year = y;
  sold = writtenoff = 0;
}

void PackagedShipment::sellPack(int packs) {
  std::cout << "[Продажа упаковкой] упаковок=" << packs << "\n";
  int need = packs * perPack;
  if (quantity < need) {
    std::cout << "Ошибка: недостаточно товара для продажи полной упаковки!\n";
    return;
  }
  quantity -= need;
  sold += need;
}

void PackagedShipment::sell(int count) {
  std::cout << "[Продажа поштучно] шт=" << count << "\n";
  Shipment::sell(count);
}

void PackagedShipment::writeOff(int count) {
  std::cout << "[Списание] шт=" << count << "\n";
  Shipment::writeOff(count);
}

void PackagedShipment::printRest() const {
  std::cout << "[Остаток] " << name << ": " << quantity << " шт, "
            << quantity / perPack << " упаковок\n";
}

void PackagedShipment::printReport() const {
  std::cout << "\n[Отчёт по фасованной партии]\n"
            << "Наименование: " << name << "\n"
            << "Штук в упаковке: " << perPack << "\n"
            << "Остаток (шт): " << quantity << "\n"
            << "Остаток (упаковки): " << quantity / perPack << "\n"
            << "Продано: " << sold << "\n"
            << "Списано: " << writtenoff << "\n";
}
