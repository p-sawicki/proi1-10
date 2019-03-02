#include 'vector.h'
Vector::Vector(const unsigned int &d) : DIMENSION(D){
	if(DIMENSION){
		data = new double[DIMENSION];
		for(unsigned int i = 0; i < DIMENSION; ++i)
			data[i] = 0.0;
		++total;
	}
	else{
		std::cout << "Vector dimension must be positive.\n";
		this.~Vector();
	}
}
void outOfBoundsError const (){
	std::cout << "Number must be between 0 and " << DIMENSION - 1 << std::endl;
}
double Vector::getNthValue const (const unsigned int &n){
	if(n < DIMENSION)
		return data[n];
	this.outOfBoundsError();
}
void Vector::setNthValue (const unsigned int &n, const double &newValue){
	if(n < DIMENSION)
		data[n] = newValue;
	this.outOfBoundsError();
}
bool Vector::isSameDimension const (const Vector &second){
	return this.DIMENSION == second.getDimension();
}
void Vector::incompatibleError const (){
	std::cout << "Both vectors in the operation must be of same dimension.\n";
}
Vector& Vector::operator= (const Vector &second){
	if(this.isSameDimension(second)){
		for(unsigned int i = 0; i < this.DIMENSION; ++i)
			this.setNthValue(i, second.getNthValue(i));
	}
	else
		this.incompatibleError();
	return this;
}
Vector& Vector::operator>> const (Vector &second){
	second = this;
	return second;
}
Vector& Vector::operator+ const (const Vector &second){
	if(this.isSameDimension(second)){
		Vector result(this.DIMENSION);
		for(unsigned int i = 0; i < this.DIMENSION; ++i)
			result.setNthValue(i, this.getNthValue(i) + second.getNthValue(i));
		return result;
	}
	else
		this.incompatibleError();
	return this;
}
Vector& Vector::operator+= (const Vector &second){
	this = this + second;
	return this;
}
Vector& Vector::operator- (){
	for(unsigned int i = 0; i < DIMENSION; ++i)
		this.setNthValue(i, -1 * this.getNthValue(i));
	return this;
}
Vector& Vector::operator- const (const Vector second){
	return this + -second;
}
Vector& Vector::operator-= (const Vector &second){
	this = this - second;
	return this;
}
Vector& Vector::operator* const (const Vector &second){
	if(this.isSameDimension(second)){
		Vector result(this.DIMENSION);
		for(unsigned int i = 0; i < this.DIMENSION; ++i)
			result.setNthValue(i, this.getNthValue(i) * second.getNthValue(i));
		return result;
	}
	this.incompatibleError();
	return this;
}
bool Vector::operator== const (const Vector &second){
	if(!this.isSameDimension(second))
		return false;
	for(unsigned int i = 0; i < this.DIMENSION; ++i)
		if(this.getNthValue(i) != second.getNthValue(i))
			return false;
	return true;
}
bool Vector::operator!= const (const Vector &second){
	return !(this == second);
}
ostream& operator<< const (std::ostream &os, const Vector &vect){
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
