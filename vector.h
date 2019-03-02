#include <iostream>
class Vector{
	private:
		static unsigned int total;
		const unsigned int DIMENSION;
		double * data;
	public:
		Vector(const unsigned int &d);
		void outOfBoundsError const ();
		double getNthValue const (const unsigned int &n);
		void setNthValue(const unsigned int &n, const double &newValue);
		unsigned int getDimension const();
		bool isSameDimension const (const Vector &second);
		void incompatibleError const ();
		Vector& operator= (const Vector &second);
		Vector& operator>> const (Vector &second);
		Vector& operator+ const (const Vector &second);
		Vector& operator+=(const Vector &second);
		Vector& operator- const (const Vector &second);
		Vector& operator-=(const Vector &second);
		Vector& operator* const (const Vector &second);
		bool operator== const (const Vector &second);
		bool operator!= const (const Vector &second);
		friend ostream& operator<< const (std::ostream &os, const Vector &vect);	
		~Vector();
};
