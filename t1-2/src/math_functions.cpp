#include "../include/math_functions.h"
#include <cmath>
#include <iostream>

using namespace std;

double function1(double x) { return -sin(x - 5); }

double function2(double x) {
  if (x == 0) {
    cout << "Ошибка: ln(0) не определён" << endl;
    return 0;
  }
  return log(x * x);
}

double function3(double x) { return sin(x - 5); }

double function4(double x) { return pow(2, x); }

double function5(double x) {
  double cosValue = cos(x + 5);
  return cosValue * cosValue;
}

// Функция для выбора варианта и вычисления
double calculateFunction(int variant, double x) {
  switch (variant) {
  case 1:
    return function1(x);
  case 2:
    return function2(x);
  case 3:
    return function3(x);
  case 4:
    return function4(x);
  case 5:
    return function5(x);
  default:
    cout << "Неверный вариант функции" << endl;
    return 0;
  }
}

// Задание 2: Коммуникация с пользователем в отдельной функции
void userCommunication() {
  int variant;
  double x1, x2;

  cout << "\nВыберите вариант функции:" << endl;
  cout << "1. F(x) = -sin(x - 5)" << endl;
  cout << "2. F(x) = ln(x^2)" << endl;
  cout << "3. F(x) = sin(x - 5)" << endl;
  cout << "4. F(x) = 2^x" << endl;
  cout << "5. F(x) = cos^2(x + 5)" << endl;
  cout << "Ваш выбор: ";
  cin >> variant;

  if (variant < 1 || variant > 5) {
    cout << "Неверный вариант!" << endl;
    return;
  }

  cout << "Введите первое число: ";
  cin >> x1;
  cout << "Введите второе число: ";
  cin >> x2;

  double result1 = calculateFunction(variant, x1);
  double result2 = calculateFunction(variant, x2);

  cout << "\nРезультаты:" << endl;
  cout << "F(" << x1 << ") = " << result1 << endl;
  cout << "F(" << x2 << ") = " << result2 << endl;
}

// Задание 3: Рекурсивная функция коммуникации
double userCommunicationRecursive(int count, double sum) {
  if (count >= 2) {
    cout << "\nСумма всех вычисленных значений: " << sum << endl;
    return sum;
  }

  int variant;
  double x;

  if (count == 0) {
    cout << "\nВыберите вариант функции:" << endl;
    cout << "1. F(x) = -sin(x - 5)" << endl;
    cout << "2. F(x) = ln(x^2)" << endl;
    cout << "3. F(x) = sin(x - 5)" << endl;
    cout << "4. F(x) = 2^x" << endl;
    cout << "5. F(x) = cos^2(x + 5)" << endl;
    cout << "Ваш выбор: ";
    cin >> variant;

    if (variant < 1 || variant > 5) {
      cout << "Неверный вариант!" << endl;
      return sum;
    }
  }

  static int savedVariant = 0;
  if (count == 0) {
    savedVariant = variant;
  } else {
    variant = savedVariant;
  }

  cout << "Введите число " << (count + 1) << ": ";
  cin >> x;

  double result = calculateFunction(variant, x);
  cout << "F(" << x << ") = " << result << endl;

  return userCommunicationRecursive(count + 1, sum + result);
}
