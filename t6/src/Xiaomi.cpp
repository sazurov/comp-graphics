#include "../include/Xiaomi.h"
#include <sstream>

using namespace std;

Xiaomi::Xiaomi(double diagonal, double cpuFrequency)
    : diagonal(diagonal), cpuFrequency(cpuFrequency) {}

string Xiaomi::ShowXiaomi() const {
  ostringstream oss;
  oss << "Тип телефона: Xiaomi с диагональю " << diagonal
      << " дюймов и частотой процессора " << cpuFrequency << " ГГц";
  return oss.str();
}
