#ifndef IPHONE_H
#define IPHONE_H

#include <string>

class IPhone {
private:
  double diagonal;
  double cpuFrequency;

public:
  IPhone(double diagonal, double cpuFrequency);

  std::string ShowIphone() const;
};

#endif // IPHONE_H
