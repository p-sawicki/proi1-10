#include <iostream>
#include 'vector.h'
Vector::Vector(const unsigned int D) : DIMENSION(D){
	data = new double[DIMENSION];
	for(int i = 0; i < DIMENSION; ++i)
		data[i] = 0.0;
}
double Vector::getNthValue const (const unsigned int n){
	if(n < DIMENSION)
		return data[n];
	// TODO exception?
}
void Vector::setNthValue (const unsigned int n, const double newValue){
	if(n < DIMENSION)
		data[n] = newValue;
	// TODO
}
int Vector::minDimension const (const Vector second){
	return this.DIMENSION < second.DIMENSION ? this.DIMENSION : second.DIMENSION;
}
void Vector::operator>> const (Vector second){
	unsigned int min = minDimension(second);
	for(int i = 0; i < min; ++i)
		second.data[i] = this.data[i];
}
Vector & Vector::operator+ const (const Vector second);
	unsigned int min = minDimension(second);
	Vector result(min);
	for(int i = 0; i < min; ++i)
		result.data[i] = this.data[i] + second.data[i];
	return &result;
}
Vector & Vector::operator+= (const Vector second){
	unsigned int min = minDimension(second);
	for(int i = 0; i < min; ++i)
		this.data[i] += second.data[i];
	return this;
}
Vector & Vector::operator- const (const Vector second){
	unsigned int min = minDimension(second); 
	Vector result(min);
	for(int i = 0; i < min; ++i)
		result.data[i] = this.data[i] - second.data[i]; 
