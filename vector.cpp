#include "vector.h"
unsigned int Vector::total;
Vector::Vector(const unsigned int &d) : DIMENSION(d){
	++total;
	if(DIMENSION){
		data = new double[DIMENSION];
		for(unsigned int i = 0; i < DIMENSION; ++i)
			data[i] = 0.0;
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
	else
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
int Vector::getTotal(){
	return total;
}
Vector& Vector::operator=(Vector const& second){
	if(isSameDimension(second))
		for(unsigned int i = 0; i < DIMENSION; ++i)
			data[i] = second.getNthValue(i);
	else
		incompatibleError();
	return *this;
}
Vector Vector::operator+(const Vector& second) const {
	Vector temp(DIMENSION);
	if(isSameDimension(second))
		for(unsigned int i = 0; i < DIMENSION; ++i)
			temp.setNthValue(i, data[i] + second.getNthValue(i));
	else
		incompatibleError();
	return temp;
}
Vector& Vector::operator+=(const Vector& second){
	*this = *this + second;
	return *this;
}
Vector Vector::operator-() const {
	Vector temp(DIMENSION);
	for(unsigned int i = 0; i < DIMENSION; ++i)
		temp.setNthValue(i, -1 * data[i]);
	return temp;
}
Vector Vector::operator-(const Vector &second) const {
	Vector temp(DIMENSION);
	temp = *this + -second;
	return temp;
}
Vector& Vector::operator-=(const Vector &second){
	*this += -second;
	return *this;
}
double Vector::operator*(const Vector &second) const {
	double result = 0.0;
	if(isSameDimension(second))
		for(unsigned int i = 0; i < DIMENSION; ++i)
			result += data[i] * second.getNthValue(i);
	else
		incompatibleError();
	return result;
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
void Vector::incorrectlyFormatedError(){
	std::cout << "Input was not a correct vector. Try [";
	char letter = 'a';
	for(int i = 0; i < DIMENSION; ++i){
		std::cout << letter++;
		if(i == DIMENSION - 1)
			std::cout << "]";
		else
			std::cout << ", ";
	}
	std::cout << std::endl;
}
std::istream& operator>>(std::istream &is, Vector &vect){
	std::string input;
	std::getline(is, input);
	std::stringstream inputStream(input);
	char check = 0;
	inputStream >> check;
	bool isCorrectlyFormated = check == '[';
	const unsigned int dimension = vect.getDimension();
	Vector temp(dimension);
	for(int i = 0; i < dimension && isCorrectlyFormated; ++i){
		double number;
		inputStream >> number;
		if(inputStream.fail()){
			isCorrectlyFormated = false;
			break;
		}
		temp.setNthValue(i, number);
		inputStream >> check;
		if(i == dimension - 1)
			isCorrectlyFormated = check == ']';
		else
			isCorrectlyFormated = check == ',' || check == ';';
	}
	if(isCorrectlyFormated)
		vect = temp;
	else
		vect.incorrectlyFormatedError();
	return is;
}
Vector::~Vector(){
	delete[] data;
	--total;
}
