#include "../include/Menu.h"
#include <iostream>

using namespace std;

int main() {
  while (true) {
    cout << "\nВыберите задание (1, 2 или 3, 0 — выход): ";
    int t;
    cin >> t;
    switch (t) {
    case 0:
      return 0;
    case 1:
      task1Menu();
      break;
    case 2:
      task2Menu();
      break;
    case 3:
      task3Menu();
      break;
    default:
      cout << "Неверное значение!\n";
    }
  }
}
