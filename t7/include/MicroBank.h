#ifndef MICROBANK_H
#define MICROBANK_H

#include "Bank.h"
#include <string>

class MicroBank : public Bank {
private:
  double microPercent;

public:
  MicroBank(double microPercent, double bankPercent);

  void GetPercent(double sum) const override;
};

#endif // MICROBANK_H
