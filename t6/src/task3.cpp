#include "../include/IPhone.h"
#include "../include/Xiaomi.h"
#include "../include/tasks.h"
#include <iostream>

using namespace std;

void task3() {
  cout << "\nЗадание 3: Указатели на функции классов\n" << endl;

  IPhone iphone(6.1, 3.2);
  Xiaomi xiaomi(6.67, 2.84);

  string (IPhone::*ptrShowIphone)() const = &IPhone::ShowIphone;
  string (Xiaomi::*ptrShowXiaomi)() const = &Xiaomi::ShowXiaomi;

  cout << "Информация об iPhone:" << endl;
  cout << (iphone.*ptrShowIphone)() << endl;

  cout << "\nИнформация об Xiaomi:" << endl;
  cout << (xiaomi.*ptrShowXiaomi)() << endl;
}
