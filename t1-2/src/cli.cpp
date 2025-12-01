#include "../include/cli.h"
#include <iostream>

#include <iomanip>

using namespace std;

namespace cli {

void getUserInput(double &x1, double &x2, int &var) {
  cout << "Калькулятор математических функций" << endl;
  cout << "\nВыберите вариант задания:" << endl;
  cout << "1. F(x) = -sin(x - 5)" << endl;
  cout << "2. F(x) = ln(x^2)" << endl;
  cout << "3. F(x) = sin(x - 5)" << endl;
  cout << "4. F(x) = 2^x" << endl;
  cout << "5. F(x) = cos^2(x + 5)" << endl;
  cout << "\nВведите номер варианта (1-5): ";
  cin >> var;

  if (var < 1 || var > 5) {
    throw invalid_argument("Неверный номер варианта!");
  }

  cout << "\nВведите первое число: ";
  cin >> x1;
  cout << "Введите второе число: ";
  cin >> x2;
}
void displayRes(double x1, double x2, double maxX, double result, int var) {
  cout << fixed << setprecision(6);
  cout << "\n--- Результаты ---" << endl;
  cout << "Первое число: " << x1 << endl;
  cout << "Второе число: " << x2 << endl;
  cout << "Большее число: " << maxX << endl;

  switch (var) {
  case 1:
    cout << "F(" << maxX << ") = -sin(" << maxX << " - 5) = " << result << endl;
    break;
  case 2:
    cout << "F(" << maxX << ") = ln(" << maxX << "^2) = " << result << endl;
    break;
  case 3:
    cout << "F(" << maxX << ") = sin(" << maxX << " - 5) = " << result << endl;
    break;
  case 4:
    cout << "F(" << maxX << ") = 2^" << maxX << " = " << result << endl;
    break;
  case 5:
    cout << "F(" << maxX << ") = cos^2(" << maxX << " + 5) = " << result
         << endl;
    break;
  }
}
} // namespace cli
