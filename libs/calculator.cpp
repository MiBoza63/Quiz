#include <iostream>
using namespace std;

double Add(double x, double y){
	return x+y;
}

double Subtract(double x, double y){
	return x-y;
}

double Multiply(double x, double y){
	return x*y;
}

double Divide(double x, double y){
	return x/y;
}

void Calculator(){
	int x, y, result;
	short op_code;

	cout<<"x = "; cin>>x;
	cout<<"y = "; cin>>y;

	cout<<"Choose operation:\n";
	cout<<"1. +\n";
	cout<<"2. -\n";
	cout<<"3. *\n";
	cout<<"4. /\n";
	cin>>op_code;

	switch (op_code) {
		case 1:
			result = Add(x, y);
			break;
		case 2:
			result = Subtract(x, y);
			break;
		case 3:
			result = Multiply(x, y);
			break;
		case 4:
			result = Divide(x, y);
			break;
		default:
			cout<<"Operation not recognised. Please enter number from 1 to 4.\n";
			return 1;
	}

	cout<<result<<'\n';
}
