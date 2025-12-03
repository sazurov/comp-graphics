#ifndef SAFEPACKAGEDPRODUCT_H
#define SAFEPACKAGEDPRODUCT_H

#include "PackagedProduct.h"

class SafePackagedProduct : public PackagedProduct {
public:
  SafePackagedProduct();

  void sell(int amount = 1) override;
  void writeOff(int amount = 1) override;
  void sellPackage(int packageCount = 1);
};

#endif // SAFEPACKAGEDPRODUCT_H
