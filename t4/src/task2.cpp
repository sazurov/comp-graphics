#include "../include/tasks.h"
#include <iostream>
#include <string>

using namespace std;

void task2() {
  cout << "\nЗадание 2: Замена символа в строке" << endl;

  string str;
  char symbol1, symbol2;

  cout << "Введите строку: ";
  getline(cin, str);

  cout << "Введите символ для поиска: ";
  cin >> symbol1;

  cout << "Введите символ для замены: ";
  cin >> symbol2;
  cin.ignore();

  bool found = false;
  for (char &c : str) {
    if (c == symbol1) {
      c = symbol2;
      found = true;
    }
  }

  if (found) {
    cout << "Символ заменен" << endl;
    cout << "Результат: " << str << endl;
  } else {
    cout << "Символ не найден" << endl;
  }
}
