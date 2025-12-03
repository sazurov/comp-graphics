#ifndef TESTS_H
#define TESTS_H

#include "PackagedProduct.h"
#include "ProductBatch.h"
#include "SafePackagedProduct.h"

void test1(ProductBatch &batch);
void test2(ProductBatch &batch);
void test3(ProductBatch &batch);

void testPackaged1(PackagedProduct &product);
void testPackaged2(PackagedProduct &product);
void testPackaged3(PackagedProduct &product);

void errorTest1(SafePackagedProduct &product);
void errorTest2(SafePackagedProduct &product);
void errorTest3(SafePackagedProduct &product);
void errorTest4(SafePackagedProduct &product);

#endif // TESTS_H
