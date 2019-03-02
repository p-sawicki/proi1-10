#include <iostream>
class Vector{
	private:
		static unsigned int total;
		const unsigned int DIMENSION;
		double * data;
	public:
		Vector(const unsigned int &d);
		void outOfBoundsError() const; 
		double getNthValue(const unsigned int &n) const;
		void setNthValue(const unsigned int &n, const double &newValue);
		unsigned int getDimension() const;
		bool isSameDimension(const Vector &second) const;
		void incompatibleError() const;
		static int getTotal();
		Vector& operator=(const Vector &second);
		Vector& operator>>(Vector &second) const;
		friend Vector operator+(Vector first, const Vector &second);
		Vector& operator+=(const Vector &second);
		Vector operator-() const;
		friend Vector operator-(Vector first, const Vector &second);
		Vector& operator-=(const Vector &second);
		Vector operator*(const Vector &second) const;
		bool operator==(const Vector &second) const;
		bool operator!=(const Vector &second) const;
		friend std::ostream& operator<<(std::ostream &os, const Vector &vect);	
		~Vector();
};
