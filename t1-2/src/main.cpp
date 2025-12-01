#include "../include/cli.h"
#include "../include/math_fns.h"
#include <iostream>

using namespace std;
using namespace cli;
using namespace MathFns;

int main() {
  try {
    double x1, x2;
    int var;

    // Вызов функции коммуникации с пользователем
    getUserInput(x1, x2, var);

    // Определяем большее число
    double maxX = (x1 > x2) ? x1 : x2;
    double result;

    // Вычисляем значение функции для большего числа
    switch (var) {
    case 1:
      result = f1(maxX);
      break;
    case 2:
      result = f2(maxX);
      break;
    case 3:
      result = f3(maxX);
      break;
    case 4:
      result = f4(maxX);
      break;
    case 5:
      result = f5(maxX);
      break;
    }

    // Вывод результатов
    displayRes(x1, x2, maxX, result, var);

    cout << "\n--- Задание 3 (рекурсивная сумма) ---" << endl;
    double sum = recursiveSum(var, x1, x2);
    cout << "Сумма всех вычисленных значений: " << sum << endl;
    cout << "(F(" << x1 << ") + F(" << x2 << "))" << endl;

  } catch (const exception &e) {
    cerr << "Ошибка: " << e.what() << endl;
    return 1;
  }

  return 0;
}
