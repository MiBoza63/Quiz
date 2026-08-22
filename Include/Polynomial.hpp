#ifndef Polynomial_hpp
#define Polynomial_hpp

#include <vector>
#include <iostream>
using std::cout;
using std::move;
using std::vector;
using std::initializer_list;

class Polynomial{
private:
	vector<float> coefficients;
	void Simplify();
	void push_back(float x);

public:
	int size() const;
	float operator[](int x) const;
	float Eval(float f);
	Polynomial();
	Polynomial(float x);
	Polynomial(initializer_list<float> l);
	Polynomial(vector<float> v);
	Polynomial(const Polynomial& poly);
	Polynomial(Polynomial&& poly);
	Polynomial operator+(const Polynomial& B);
	Polynomial operator*(const Polynomial& B);
	void operator=(const Polynomial& poly);
	void operator=(Polynomial&& poly);
	void operator+=(Polynomial& A);
	void operator*=(Polynomial& A);
	void operator/=(float f);
};

Polynomial Zeros_To_Poly(initializer_list<float> list);
void Print_Polynomial(const char* msg, const Polynomial& A);

#endif	//Polynomial_hpp

// int main(){
// 	int x = -10;
// 	Polynomial a = {0.0833334, -1.125, 5.91667, -10};
// 	Polynomial b = {4, -5, -2};
// 	Polynomial c = Zeros_To_Poly({1, 0, -1});
// 	a.Print("a = ");
// 	b.Print("b = ");
// 	c.Print("c = ");
// 	cout<<"a.Eval("<<x<<") = "<<a.Eval(x)<<'\n';
//
// 	return 0;
// }
