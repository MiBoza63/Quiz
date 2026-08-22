#ifndef Equations_hpp
#define Equations_hpp

#include <utility>

// ax^2 + bx + c = 0
std::pair<float, float> Quadratic(float a, float b, float c);

//Solve f(x) = 0 numerically
float Newton_Raphson(float x = 1, float tol = 1e-3, float max_iter = 10);
float Secant(float x = 1, float x2 = 2, float tol = 1e-3, float max_iter = 10);

float f(float x);   //Function to solve numerically
float fp(float x);  //Derivative of f with respect to x

#endif // Equations_hpp
