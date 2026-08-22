#include "Fraction.hpp"
#include <iostream>

Fraction::Fraction(int a):
	num(a), den(1){}

Fraction::Fraction(int a, int b):
	num(a), den(b){}

bool operator==(const Fraction& u, const Fraction& v){
    return (u.num == v.num) && (u.den == v.den);
}

void Print(const char* msg, const Fraction& A){
	std::cout<<msg<<A.num<<'/'<<A.den<<'\n';
}

Fraction operator+(const Fraction& A, const Fraction& B){
	int r_num = A.num*B.den + B.num*A.den;
	int r_den = A.den*B.den;

	Fraction result({r_num, r_den});
	return result;
}

Fraction operator*(const Fraction& A, const Fraction& B){
	int r_num = A.num*B.num;
	int r_den = A.den*B.den;

	Fraction result(r_num, r_den);

	return result;
}
