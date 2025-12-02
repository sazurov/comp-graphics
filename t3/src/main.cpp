#include "../include/Menu.h"
#include <iostream>

int main() {
  while (true) {
    std::cout << "Выберите задание (1, 2 или 3, 0 — выход): ";
    int t;
    std::cin >> t;

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
      std::cout << "Неверное значение! Попробуйте снова.\n";
    }
  }
}
