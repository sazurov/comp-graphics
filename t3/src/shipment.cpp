#include "../include/Shipment.h"
#include <iostream>

void Shipment::init(const string &n, int q, int d, int m, int y) {
  name = n;
  quantity = q;
  sold = 0;
  writtenOff = 0;
  day = d;
  month = m;
  year = y;
  cout << "[Инициализация] " << name << ", количество=" << quantity
            << "\n";
}

void Shipment::sell(int count) {
  sold += count;
  cout << "[Продажа] " << count << " шт\n";
}

void Shipment::writeOff(int count) {
  writtenOff += count;
  cout << "[Списание] " << count << " шт\n";
}

void Shipment::printRest() const {
  cout << "[Остаток] " << name << ": " << (quantity - sold - writtenOff)
            << " шт\n";
}

void Shipment::printReport() const {
  cout << "[Отчёт] " << name << "\n"
            << "Поставлено: " << quantity << "\n"
            << "Продано: " << sold << "\n"
            << "Списано: " << writtenOff << "\n";
}
