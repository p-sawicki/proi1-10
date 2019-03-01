class Vector{
	private:
		const unsigned int DIMENSION;
		double * data;
	public:
		Vector(const unsigned int D);
		double getNthValue const (const unsigned int n);
		void setNthValue(const unsigned int n, const double newValue);
		int minDimension const (const Vector second);
		void operator>> const (Vector second);
		Vector & operator+ const (const Vector second);
		Vector & operator+=(const Vector second);
		Vector & operator- const (const Vector second);
		Vector & operator-=(const Vector second);
		Vector & operator*(const Vector second);
		bool operator==(const Vector second);
		bool operator!=(const Vector second);
		~Vector();
};
