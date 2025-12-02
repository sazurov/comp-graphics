#ifndef SAFE_TESTS_H
#define SAFE_TESTS_H

#include "SafePackagedShipment.h"

void safeTest1(SafePackagedShipment &p); // отрицательная продажа
void safeTest2(SafePackagedShipment &p); // нулевая продажа
void safeTest3(SafePackagedShipment &p); // продажа больше остатка
void safeTest4(SafePackagedShipment &p); // списание отрицательное
void safeTest5(SafePackagedShipment &p); // продажа упаковок отрицательная
void safeTest6(SafePackagedShipment &p); // продажа упаковок при нехватке
void safeTest7(SafePackagedShipment &p); // списание больше остатка

#endif
