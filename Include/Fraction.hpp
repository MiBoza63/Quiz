#ifndef Fraction_hpp
#define Fraction_hpp

struct Fraction{
	int num, den;

	Fraction(int a);
	Fraction(int a, int b);
};

bool operator==(const Fraction& u, const Fraction& v);
void Print(const char* msg, const Fraction& A);
Fraction operator+(const Fraction& A, const Fraction& B);
Fraction operator*(const Fraction& A, const Fraction& B);

#endif // Fraction_hpp
