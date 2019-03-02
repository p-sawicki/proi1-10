#include "vector-test.h"
#include "vector.h"
void test0(){
	unsigned int d = 3;
	Vector v1(d);
	for(unsigned int i = 0; i < d; ++i)
		assert(v1.getNthValue(i) == 0.0);
}
void test0DimVect(){
	std::cout << "Testing if error message appears correctly\n";
	Vector v(0);
	std::cout << "Test ended\n";
}
