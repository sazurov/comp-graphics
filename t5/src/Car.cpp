#include "../include/Car.h"
#include <iostream>

Car::Car(const std::string &name, double speed) : name(name), speed(speed) {}

std::string Car::getName() const { return name; }

double Car::getSpeed() const { return speed; }

void Car::setName(const std::string &name) { this->name = name; }

void Car::setSpeed(double speed) { this->speed = speed; }

bool Car::operator==(const Car &other) const {
  return (name == other.name && speed == other.speed);
}

bool Car::operator<(const Car &other) const { return speed < other.speed; }

bool Car::operator>(const Car &other) const { return speed > other.speed; }

void Car::display() const {
  std::cout << "Машина: " << name << ", Скорость: " << speed << " км/ч"
            << std::endl;
}
