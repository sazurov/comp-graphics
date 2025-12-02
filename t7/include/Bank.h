#ifndef BANK_H
#define BANK_H

class Bank {
protected:
  double bankPercent;

public:
  Bank(double bankPercent);
  virtual ~Bank() = default;

  virtual void GetPercent(double sum) const;
};

#endif // BANK_H
