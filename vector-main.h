#ifndef VECTOR_MAIN_H
#define VECTOR_MAIN_H
#include <iostream>
#include "vector.h"
void readValue(const Vector& vect, const unsigned int &n);
void setValue(Vector& vect, const unsigned int &n);
void loadVector(Vector& vect);
void addVectors(Vector& v1, Vector& v2, Vector& result);
void subtractVectors(Vector& v1, Vector& v2, Vector& result);
void dotProduct(const Vector& v1, const Vector &v2);
void compareVectors(const Vector& v1, const Vector &v2);
void printVector(const Vector& vect);
void cantGetError();
bool getUnsignedInt(unsigned int* data, const unsigned int& howMany, const std::string& input);
bool getDouble(double* data, const unsigned int& howMany, const std::string& input);
#endif
