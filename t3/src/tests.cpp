#include "../include/tests.h"
#include <iostream>

using namespace std;

// Тесты для базового класса
void test1(ProductBatch &batch) {
  cout << "\n=== Тест 1 ===" << endl;
  batch.sell(10);
  batch.writeOff(5);
  batch.sell(3);
}

void test2(ProductBatch &batch) {
  cout << "\n=== Тест 2 ===" << endl;
  batch.sell(20);
  batch.sell();
  batch.writeOff(10);
}

void test3(ProductBatch &batch) {
  cout << "\n=== Тест 3 ===" << endl;
  batch.writeOff(15);
  batch.sell(25);
  batch.writeOff();
}

// Тесты для упакованного товара
void testPackaged1(PackagedProduct &product) {
  cout << "\n=== Тест упакованного товара 1 ===" << endl;
  product.sellPackage(2);
  product.sell(5);
  product.writeOff(3);
}

void testPackaged2(PackagedProduct &product) {
  cout << "\n=== Тест упакованного товара 2 ===" << endl;
  product.sell(7);
  product.sellPackage(1);
  product.writeOff(2);
}

void testPackaged3(PackagedProduct &product) {
  cout << "\n=== Тест упакованного товара 3 ===" << endl;
  product.sellPackage(3);
  product.sell(10);
  product.sellPackage(1);
}

// Тесты ошибок
void errorTest1(SafePackagedProduct &product) {
  cout << "\n=== Тест ошибки 1: Отрицательное количество ===" << endl;
  product.sell(-5);
}

void errorTest2(SafePackagedProduct &product) {
  cout << "\n=== Тест ошибки 2: Продажа больше остатка ===" << endl;
  product.sell(1000);
}

void errorTest3(SafePackagedProduct &product) {
  cout << "\n=== Тест ошибки 3: Списание больше остатка ===" << endl;
  product.writeOff(500);
}

void errorTest4(SafePackagedProduct &product) {
  cout << "\n=== Тест ошибки 4: Продажа упаковок при недостатке ===" << endl;
  product.sell(95);
  product.sellPackage(1);
}
