#include "../include/Shipment.h"
#include <iostream>

void Shipment::init(const std::string &n, int q, int d, int m, int y) {
  name = n;
  quantity = q;
  sold = 0;
  writtenOff = 0;
  day = d;
  month = m;
  year = y;
  std::cout << "[Инициализация] " << name << ", количество=" << quantity
            << "\n";
}

void Shipment::sell(int count) {
  sold += count;
  std::cout << "[Продажа] " << count << " шт\n";
}

void Shipment::writeOff(int count) {
  writtenOff += count;
  std::cout << "[Списание] " << count << " шт\n";
}

void Shipment::printRest() const {
  std::cout << "[Остаток] " << name << ": " << (quantity - sold - writtenOff)
            << " шт\n";
}

void Shipment::printReport() const {
  std::cout << "[Отчёт] " << name << "\n"
            << "Поставлено: " << quantity << "\n"
            << "Продано: " << sold << "\n"
            << "Списано: " << writtenOff << "\n";
}
