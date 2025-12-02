#ifndef SAFE_PACKAGED_SHIPMENT_H
#define SAFE_PACKAGED_SHIPMENT_H

#include "PackagedShipment.h"

class SafePackagedShipment : public PackagedShipment {
private:
  bool checkNegative(int value, const char *action) const;
  bool checkZero(int value, const char *action) const;
  bool checkEnough(int value, const char *action) const;

public:
  SafePackagedShipment() : PackagedShipment() {}

  void sell(int count = 1) override;
  void writeOff(int count = 1) override;
  void sellPack(int packs) override;
};

#endif
