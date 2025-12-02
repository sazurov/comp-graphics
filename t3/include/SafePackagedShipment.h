#ifndef SAFE_PACKAGED_SHIPMENT_H
#define SAFE_PACKAGED_SHIPMENT_H

#include "PackagedShipment.h"

class SafePackagedShipment : public PackagedShipment {
public:
  SafePackagedShipment();

  void sell(int count = 1) override;
  void writeOff(int count = 1) override;
  void sellPack(int packs) override;

private:
  bool checkNegative(int value, const char *action) const;
  bool checkZero(int value, const char *action) const;
  bool checkEnough(int value, const char *action) const;
};

#endif
