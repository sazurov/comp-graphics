#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <iostream>
#include <string>

class Shipment {
protected:
  int quantity;
  std::string name;
  int day, month, year;
  int sold;
  int writtenoff;

public:
  Shipment();
  Shipment(const std::string &name, int quantity, int d, int m, int y);

  void init(const std::string &name, int quantity, int d, int m, int y);
  virtual void sell(int count = 1);
  virtual void writeOff(int count = 1);

  virtual void printRest() const;
  virtual void printReport() const;

  virtual ~Shipment() = default;
};

#endif
