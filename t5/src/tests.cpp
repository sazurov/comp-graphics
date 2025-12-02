#include "../include/tests.h"
#include "../include/Account.h"
#include "../include/Car.h"
#include <iostream>

using namespace std;

void testCar() {
  cout << "\n=== Задание 1: Класс Car ===" << endl;

  Car car1("Toyota Camry", 180.0);
  Car car2("BMW M5", 250.0);
  Car car3("Toyota Camry", 180.0);

  car1.display();
  car2.display();
  car3.display();

  cout << "\nСравнение car1 и car2:" << endl;
  if (car1 == car2) {
    cout << "car1 == car2" << endl;
  } else {
    cout << "car1 != car2" << endl;
  }

  if (car1 < car2) {
    cout << "car1 < car2 (по скорости)" << endl;
  }

  if (car2 > car1) {
    cout << "car2 > car1 (по скорости)" << endl;
  }

  cout << "\nСравнение car1 и car3:" << endl;
  if (car1 == car3) {
    cout << "car1 == car3 (оба параметра равны)" << endl;
  }
}

void testAccount() {
  cout << "\n=== Задание 2: Класс Account ===" << endl;

  Account acc("Основной счёт", 1000.0);

  cout << "\nНачальное состояние:" << endl;
  acc.display();

  cout << "\nИнкремент (++acc) - увеличение дохода:" << endl;
  ++acc;
  acc.display();

  cout << "\nДекремент (--acc) - увеличение расхода:" << endl;
  --acc;
  acc.display();

  cout << "\nДобавление положительного числа (acc + 500):" << endl;
  acc + 500.0;
  acc.display();

  cout << "\nДобавление отрицательного числа (acc + (-200)):" << endl;
  acc + (-200.0);
  acc.display();

  cout << "\nНесколько операций подряд:" << endl;
  ++acc;
  ++acc;
  --acc;
  acc + 300.0;
  acc + (-150.0);
  acc.display();
}
