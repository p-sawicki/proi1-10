//Author: Piotr Sawicki
#include "vector-test.h"
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
	assert(v1.isSameDimension(v2));
	std::cout << "test0 ended\n";
}
void test0DimVect(){
	std::cout << "Testing if error message appears correctly\n";
	Vector v(0);
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
	std::cout << "test1 ended \n";
}
void test2(){
	std::cout << "Test2\n";
	const unsigned int D = 5;
	Vector v1(D), v2(D);
	for(unsigned int i = 0; i < D; ++i)
		v1.setNthValue(i, 3.14 * i);
	std::cout << "Input v2 and a letter:\n";
	char c = 0;
	std::cin >> v2 >> c;
	std::cout << "v2: " << v2 << ", c: " << c << std::endl;
	std::cout << "test2 ended\n"; 
}
void test3(){
	std::cout << "test3\n";
	Vector v1(3), v2(3), v3(3), v4(3);
	for(unsigned int i = 0; i < 3; ++i){
		v1.setNthValue(i, i);
		v4.setNthValue(i, 2 * i);
	}
	v4 += v1 += v1;
	for(unsigned int i = 0; i < 3; ++i)
		assert(v4.getNthValue(i) == 2 * v1.getNthValue(i));
	v4 = v1 + v1 + v1;
	for(unsigned int i = 0; i < 3; ++i)
		assert(v4.getNthValue(i) == 3 * v1.getNthValue(i));
	v4 -= v1 -= v1;
	for(unsigned int i = 0; i < 3; ++i){
		assert(v1.getNthValue(i) == 0);
		v1.setNthValue(i, i);
	}
	v4 = v1 - v1 - v1;
	for(unsigned int i = 0; i < 3; ++i)
		assert(v4.getNthValue(i) == -v1.getNthValue(i));
	std::cout << "test3 ended\n";
}
void test4(){
	std::cout << "test4\n";
	const unsigned int D = 3;
	Vector v1(D), v2(D); 
	for(unsigned int i = 0; i < D; ++i)
		v1.setNthValue(i, i + 1);
	v2 = v1;
	double n = v2 * v1;
	assert(n == 14.0);
	assert(v2 == v1);
	assert(!(v2 != v1));
	std::cout << "v1: " << v1 << ", v2: " << v2 << std::endl;
	std::cout << "test4 ended\n";
}
