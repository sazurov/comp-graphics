#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <string>

class Shipment {
protected:
  std::string name;
  int quantity;
  int sold;
  int writtenOff;
  int day, month, year;

public:
  Shipment() : quantity(0), sold(0), writtenOff(0), day(0), month(0), year(0) {}
  virtual ~Shipment() = default;

  virtual void init(const std::string &n, int q, int d, int m, int y);

  virtual void sell(int count = 1);
  virtual void writeOff(int count = 1);
  virtual void printRest() const;
  virtual void printReport() const;
};

#endif
