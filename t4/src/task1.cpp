#include "../include/tasks.h"
#include <iostream>
#include <string>

using namespace std;

void task1() {
  cout << "=== Задание 1: Поиск символа в строке ===" << endl;

  string str;
  char symbol;

  cout << "Введите строку: ";
  getline(cin, str);

  cout << "Введите символ для поиска: ";
  cin >> symbol;
  cin.ignore();

  int count = 0;
  for (char c : str) {
    if (c == symbol) {
      count++;
    }
  }

  if (count > 0) {
    cout << "Данный символ встречается в строке (" << count << ") раз" << endl;
  } else {
    cout << "Строка не содержит символ" << endl;
  }
}
