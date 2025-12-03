#include "../include/ProductBatch.h"
#include <iostream>

using namespace std;

ProductBatch::ProductBatch()
    : quantity(0), productName(""), day(0), month(0), year(0), soldQuantity(0),
      writtenOffQuantity(0) {}

void ProductBatch::initialize(int qty, const string &name, int d, int m,
                              int y) {
  cout << "Вызов: initialize(" << qty << ", \"" << name << "\", " << d << "."
       << m << "." << y << ")" << endl;
  quantity = qty;
  productName = name;
  day = d;
  month = m;
  year = y;
  soldQuantity = 0;
  writtenOffQuantity = 0;
}

void ProductBatch::sell(int amount) {
  cout << "Вызов: sell(" << amount << ")" << endl;
  soldQuantity += amount;
}

void ProductBatch::writeOff(int amount) {
  cout << "Вызов: writeOff(" << amount << ")" << endl;
  writtenOffQuantity += amount;
}

void ProductBatch::showRemainder() const {
  cout << "Вызов: showRemainder()" << endl;
  int remainder = quantity - soldQuantity - writtenOffQuantity;
  cout << "Остаток товара \"" << productName << "\": " << remainder << " шт."
       << endl;
}

void ProductBatch::showFullReport() const {
  cout << "Вызов: showFullReport()" << endl;
  cout << "\n--- Полный отчёт по партии ---" << endl;
  cout << "Наименование: " << productName << endl;
  cout << "Дата поставки: " << day << "." << month << "." << year << endl;
  cout << "Количество в партии: " << quantity << " шт." << endl;
  cout << "Продано: " << soldQuantity << " шт." << endl;
  cout << "Списано: " << writtenOffQuantity << " шт." << endl;
  cout << "Остаток: " << getRemainder() << " шт." << endl;
}

int ProductBatch::getRemainder() const {
  return quantity - soldQuantity - writtenOffQuantity;
}
