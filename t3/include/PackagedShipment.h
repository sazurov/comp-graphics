#ifndef PACKAGED_SHIPMENT_H
#define PACKAGED_SHIPMENT_H

#include "Shipment.h"
#include <string>

class PackagedShipment : public Shipment {
protected:
  int perPack;

public:
  PackagedShipment();
  PackagedShipment(const std::string &n, int pp, int packs, int d, int m,
                   int y);

  void init(const std::string &n, int pp, int packs, int d, int m, int y);

  void sell(int count = 1) override;
  void writeOff(int count = 1) override;
  void printRest() const override;
  void printReport() const override;

  virtual void sellPack(int packs);
};

#endif
