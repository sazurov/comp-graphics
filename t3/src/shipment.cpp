#include "../include/Shipment.h"

Shipment::Shipment()
    : quantity(0), name(""), day(0), month(0), year(0), sold(0), writtenoff(0) {
}

Shipment::Shipment(const std::string &n, int q, int d, int m, int y)
    : quantity(q), name(n), day(d), month(m), year(y), sold(0), writtenoff(0) {}

void Shipment::init(const std::string &n, int q, int d, int m, int y) {
  std::cout << "[Инициализация] " << n << ", количество=" << q << "\n";
  name = n;
  quantity = q;
  day = d;
  month = m;
  year = y;
  sold = writtenoff = 0;
}

void Shipment::sell(int count) {
  std::cout << "[Продажа] шт=" << count << "\n";
  if (count > quantity)
    count = quantity;
  quantity -= count;
  sold += count;
}

void Shipment::writeOff(int count) {
  std::cout << "[Списание] шт=" << count << "\n";
  if (count > quantity)
    count = quantity;
  quantity -= count;
  writtenoff += count;
}

void Shipment::printRest() const {
  std::cout << "[Остаток] " << name << ": " << quantity << " шт\n";
}

void Shipment::printReport() const {
  std::cout << "\n[Отчёт по партии]\n"
            << "Наименование: " << name << "\n"
            << "Дата поставки: " << day << "." << month << "." << year << "\n"
            << "Остаток: " << quantity << "\n"
            << "Продано: " << sold << "\n"
            << "Списано: " << writtenoff << "\n";
}
