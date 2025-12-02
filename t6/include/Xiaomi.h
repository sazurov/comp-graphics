#ifndef XIAOMI_H
#define XIAOMI_H

#include <string>

class Xiaomi {
private:
  double diagonal;
  double cpuFrequency;

public:
  Xiaomi(double diagonal, double cpuFrequency);

  std::string ShowXiaomi() const;
};

#endif // XIAOMI_H
