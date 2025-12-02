#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
private:
  std::string name;
  double speed;

public:
  Car(const std::string &name, double speed);

  std::string getName() const;
  double getSpeed() const;

  void setName(const std::string &name);
  void setSpeed(double speed);

  bool operator==(const Car &other) const;
  bool operator<(const Car &other) const;
  bool operator>(const Car &other) const;

  void display() const;
};

#endif // CAR_H
