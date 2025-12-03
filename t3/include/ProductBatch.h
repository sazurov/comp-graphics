#ifndef PRODUCTBATCH_H
#define PRODUCTBATCH_H

#include <string>

class ProductBatch {
protected:
  int quantity;
  std::string productName;
  int day;
  int month;
  int year;
  int soldQuantity;
  int writtenOffQuantity;

public:
  ProductBatch();

  void initialize(int qty, const std::string &name, int d, int m, int y);
  virtual void sell(int amount = 1);
  virtual void writeOff(int amount = 1);
  void showRemainder() const;
  virtual void showFullReport() const;

  int getRemainder() const;
};

#endif // PRODUCTBATCH_H
