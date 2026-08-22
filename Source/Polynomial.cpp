#include "Polynomial.hpp"

Polynomial::Polynomial(){}
Polynomial::Polynomial(initializer_list<float> l):
	coefficients(l){
	Simplify();
}

Polynomial::Polynomial(vector<float> v):
	coefficients(v){
	Simplify();
}

Polynomial::Polynomial(const Polynomial& poly):
	coefficients(poly.coefficients){
	Simplify();
}

Polynomial::Polynomial(Polynomial&& poly):
	coefficients( move(poly.coefficients) ){
	Simplify();
}

void Polynomial::operator=(const Polynomial& poly){
	coefficients = poly.coefficients;
}

void Polynomial::operator=(Polynomial&& poly){
	coefficients = move(poly.coefficients);
}

Polynomial::Polynomial(float x){
	coefficients.push_back(x);
}

float Polynomial::Eval(float f){
	float result = 0;
	for(int i = 0; i < size()-1; i++){
		result += coefficients[i];
		result *= f;
	}
	result += coefficients.back();

	return result;
}

void Polynomial::Simplify(){
	if(coefficients.front() != 0)
		return;

	vector<float> simplified;
	typename vector<float>::const_iterator it = coefficients.begin();

	// Search for first non zeron coefficient
	for(; it != coefficients.end(); ++it){
		if(*it != 0)
			break;
	}

	// Copy all following coefficients
	for(it; it != coefficients.end(); ++it)
		simplified.push_back(*it);

	coefficients = move(simplified);
	if(coefficients.size() == 0)
		coefficients.push_back(0);
}

void Print_Polynomial(const char* msg, const Polynomial& A){
	cout<<msg;

	int power = A.size()-1;
	float num = A[0];
	if(num == -1)
		cout<<'-';
	else if(num != 1)
		cout<<num;
	if(power == 0){
		cout<<'\n';
		return;
	}
	if(power > 0)
		cout<<"x";
	if(power > 1)
		cout<<"^"<<power;

	int iterations = power;
	for(int i = 1; i <= iterations; i++){
		num = A[i];
		power--;
		if(num < 0){
			cout<<" - ";
			num *= -1;
		}
		else if(num == 0)
			continue;
		else
			cout<<" + ";
		if(num != 1)
			cout<<num;
		if(power > 0)
			cout<<"x";
		if(power > 1)
			cout<<"^"<<power;
	}
	if(num == 1)
		cout<<num;
	cout<<'\n';
}

void Polynomial::operator+=(Polynomial& A){
	Polynomial result = (*this)+A;
	*this = move(result);
}

void Polynomial::operator*=(Polynomial& A){
	Polynomial result = (*this)*A;
	*this = move(result);
}

void Polynomial::operator/=(float f){
	for(float& c : coefficients)
		c /= f;
}

void Polynomial::push_back(float x){
	coefficients.push_back(x);
}

float Polynomial::operator[](int x) const{
	return coefficients[x];
}

int Polynomial::size() const{
	return coefficients.size();
}

Polynomial Zeros_To_Poly(initializer_list<float> list){
	Polynomial result(1);

	for(float f : list){
		Polynomial temp = {1, -f};
		result *= temp;
	}

	return result;
}

Polynomial Polynomial::operator+(const Polynomial& poly){
	Polynomial result;
	const Polynomial *longer_p, *shorter_p;

	if(size() > poly.size()){
		longer_p = this;
		shorter_p = &poly;
	}
	else{
		shorter_p = this;
		longer_p = &poly;
	}

	const Polynomial& longer = *longer_p;
	const Polynomial& shorter = *shorter_p;

	const int longer_len = longer.size();
	const int diff_len = longer_len-shorter.size();

	for(int i = 0; i < diff_len; i++)
		result.push_back( longer[i] );

	for(int i = diff_len; i < longer_len; i++)
		result.push_back( longer[i] + shorter[i-diff_len] );

	return result;
}

Polynomial Polynomial::operator*(const Polynomial& B){
	const Polynomial& A = *this;
	Polynomial result;
	int A_len = A.size();
	int B_len = B.size();
	int total_len = A_len + B_len;

	for(int i = 0; i < total_len - 1; ++i){
		float temp = 0;
		int shift = i - B_len + 1;
		shift = shift > 0 ? shift : 0;
		for(int a = shift, b = i-shift; a < A_len && b >= 0; a++, b--)
			temp += A[a]*B[b];

		result.push_back(temp);
	}
	return result;
}
