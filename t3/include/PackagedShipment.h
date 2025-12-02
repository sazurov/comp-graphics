#ifndef PACKAGED_SHIPMENT_H
#define PACKAGED_SHIPMENT_H

#include "Shipment.h"

class PackagedShipment : public Shipment {
protected:
  int perPack;

public:
  PackagedShipment();
  PackagedShipment(const std::string &name, int perPack, int packs, int d,
                   int m, int y);

  void init(const std::string &name, int perPack, int packs, int d, int m,
            int y);

  virtual void sellPack(int packs);
  void sell(int count = 1) override;
  void writeOff(int count = 1) override;

  void printRest() const override;
  void printReport() const override;
};

#endif
