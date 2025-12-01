#include "../include/math_fns.h"
#include <cmath>
#include <stdexcept>

namespace MathFns {

double f1(double x) { return -sin(x - 5); }

double f2(double x) {
  if (x == 0) {
    throw std::runtime_error("Логарифм от 0 не определён!");
  }
  return log(x * x);
}

double f3(double x) { return sin(x - 5); }

double f4(double x) { return pow(2, x); }

double f5(double x) {
  double cosValue = cos(x + 5);
  return cosValue * cosValue;
}

double recursiveSum(int var, double x1, double x2, int currentStep) {
  if (currentStep >= 2) {
    return 0;
  }

  double currentX = (currentStep == 0) ? x1 : x2;
  double currentResult;

  switch (var) {
  case 1:
    currentResult = f1(currentX);
    break;
  case 2:
    currentResult = f2(currentX);
    break;
  case 3:
    currentResult = f3(currentX);
    break;
  case 4:
    currentResult = f4(currentX);
    break;
  case 5:
    currentResult = f5(currentX);
    break;
  default:
    currentResult = 0;
  }

  return currentResult + recursiveSum(var, x1, x2, currentStep + 1);
}

} // namespace MathFns
