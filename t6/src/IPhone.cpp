#include "../include/IPhone.h"
#include <sstream>

using namespace std;

IPhone::IPhone(double diagonal, double cpuFrequency)
    : diagonal(diagonal), cpuFrequency(cpuFrequency) {}

string IPhone::ShowIphone() const {
  ostringstream oss;
  oss << "Тип телефона: iPhone с диагональю " << diagonal
      << " дюймов и частотой процессора " << cpuFrequency << " ГГц";
  return oss.str();
}
