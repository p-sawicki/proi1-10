#include "vector.h"
unsigned int Vector::total;
Vector::Vector(const unsigned int &d) : DIMENSION(d){
	if(DIMENSION){
		data = new double[DIMENSION];
		for(unsigned int i = 0; i < DIMENSION; ++i)
			data[i] = 0.0;
		++total;
	}
	else{
		std::cout << "Vector dimension must be positive.\n";
		this->~Vector();
	}
}
void Vector::outOfBoundsError() const {
	std::cout << "Number must be between 0 and " << DIMENSION - 1 << std::endl;
}
double Vector::getNthValue(const unsigned int &n) const {
	if(n < DIMENSION)
		return data[n];
	outOfBoundsError();
}
void Vector::setNthValue(const unsigned int &n, const double &newValue){
	if(n < DIMENSION)
		data[n] = newValue;
	outOfBoundsError();
}
unsigned int Vector::getDimension() const {
	return DIMENSION;
}
bool Vector::isSameDimension(const Vector &second) const {
	return (DIMENSION == second.getDimension());
}
void Vector::incompatibleError() const {
	std::cout << "Both vectors in the operation must be of same dimension.\n";
}
Vector& Vector::operator=(const Vector &second){
	if(isSameDimension(second)){
		for(unsigned int i = 0; i < DIMENSION; ++i)
			data[i] = second.getNthValue(i);
	}
	else
		incompatibleError();
	return *this;
}
Vector& Vector::operator>>(Vector &second) const {
	second = *this;
	return second;
}
Vector operator+(Vector first, const Vector &second){
	first += second;
	return first;
}
Vector& Vector::operator+=(const Vector &second){
	if(isSameDimension(second))
		for(unsigned int i = 0; i < DIMENSION; ++i)
			data[i] += second.getNthValue(i);
	else
		incompatibleError();
	return *this;
}
Vector Vector::operator-() const {
	Vector temp(DIMENSION);
	for(unsigned int i = 0; i < DIMENSION; ++i)
		temp.setNthValue(i, -1 * data[i]);
	return temp;
}
Vector operator-(Vector first, const Vector &second){
	first -= second;
	return first;
}
Vector& Vector::operator-=(const Vector &second){
	*this += -second;
	return *this;
}
Vector Vector::operator*(const Vector &second) const {
	if(isSameDimension(second)){
		Vector result(DIMENSION);
		for(unsigned int i = 0; i < DIMENSION; ++i)
			result.setNthValue(i, data[i] * second.getNthValue(i));
		return result;
	}
	incompatibleError();
	return *this;
}
bool Vector::operator==(const Vector &second) const {
	if(!isSameDimension(second))
		return false;
	for(unsigned int i = 0; i < DIMENSION; ++i)
		if(data[i] != second.getNthValue(i))
			return false;
	return true;
}
bool Vector::operator!=(const Vector &second) const {
	return !(*this == second);
}
std::ostream& operator<<(std::ostream &os, const Vector &vect){
	os << "[";
	for(unsigned int i = 0; i < vect.getDimension(); ++i){
		if(i)
			os << ", ";
		os << vect.getNthValue(i);
	}
	os << "]";
	return os;
}
Vector::~Vector(){
	delete[] data;
	--total;
}
