#include "vector-test.h"
#include "vector.h"
void test0(){
	std::cout << "Test0\n";
	unsigned int d = 3;
	Vector v1(d);
	for(unsigned int i = 0; i < d; ++i)
		assert(v1.getNthValue(i) == 0.0);
	std::cout << "Testing error message\n";
	v1.getNthValue(d);
	v1.setNthValue(d, 20);
	std::cout << "Test ended\n";
	v1.setNthValue(d - 1, 3);
	assert(v1.getNthValue(d - 1) == 3.0);
	assert(v1.getDimension() == d);
	Vector v2(d);
	assert(Vector::getTotal() == 2);
	assert(v1.isSameDimension(v2));
}
void test0DimVect(){
	std::cout << "Testing if error message appears correctly\n";
	Vector v(0);
	assert(Vector::getTotal() == 0);
	std::cout << "Test ended\n";
}
void test1(){
	std::cout << "Test1\n";
	const unsigned int D = 4;
	Vector v1(D), v2(D);
	for(unsigned int i = 0; i < D; ++i)
		v1.setNthValue(i, i * i);
	v2 = v1;
	for(unsigned int i = 0; i < D; ++i)
		assert(v2.getNthValue(i) == v1.getNthValue(i));
	Vector v3(D + 1);
	v3 = v2;
	for(unsigned int i = 0; i < D + 1; ++i)
		assert(v3.getNthValue(i) == 0.0);
	Vector v4(D), v5(D);
	v5 = v4 = v2;
	for(unsigned int i = 0; i < D; ++i)
		assert(v5.getNthValue(i) == v2.getNthValue(i));
}
void test2(){
	std::cout << "Test2\n";
	const unsigned int D = 5;
	Vector v1(D), v2(D);
	for(unsigned int i = 0; i < D; ++i)
		v1.setNthValue(i, 3.14 * i);
	v1 >> v2;
	for(unsigned int i = 0; i < D; ++i)
		assert(v2.getNthValue(i) == v1.getNthValue(i));
	Vector v3(D), v4(D);
	v2 >> v3 >> v4;
	for(unsigned int i = 0; i < D; ++i)
		assert(v4.getNthValue(i) == v2.getNthValue(i));
	v4 = v2 + v3;
	std::cout << v2 << v3 << v4 << std::endl;
}
void test3(){
	std::cout << "test3\n";
}
