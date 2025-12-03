#ifndef PACKAGEDPRODUCT_H
#define PACKAGEDPRODUCT_H

#include "ProductBatch.h"

class PackagedProduct : public ProductBatch {
protected:
  int itemsPerPackage;
  int totalPackages;

public:
  PackagedProduct();

  void initialize(int itemsPer, int packages, const std::string &name, int d,
                  int m, int y);
  void sellPackage(int packageCount = 1);
  void showRemainder() const;
  void showFullReport() const override;
};

#endif // PACKAGEDPRODUCT_H
