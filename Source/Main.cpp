#include <gtest/gtest.h>
#include <Equations.hpp>
#include <Fraction.hpp>
#include "Vector2.hpp"
// #include "Vector3.hpp"
using std::pair;

// Function to solve numerically
float f(float x){
	return (x-1)*x-1;
}

// Derivative of f with respect to x
float fp(float x){
	return 2*x-1;
}

TEST(Maths, Test_Equations){
    pair<float, float> analytic_answer = Quadratic(-1, 1, 1);
    EXPECT_EQ(analytic_answer.first, 1.61803) << "Quadratic Solver";
    EXPECT_EQ(analytic_answer.second, -0.618034) << "Quadratic Solver";

    float result;
    const float tol = 5e-4;
    result = Newton_Raphson(1, tol);
    EXPECT_EQ(result, 1.61803) << "Newton Raphson";

    result = Secant(1, 2, tol);
    EXPECT_EQ(result, 1.61798) << "Secant";
}

TEST(Maths, Test_Fraction){
    Fraction a(4, 3);
    Fraction b({2, 3});
    Fraction fraction;

    fraction = a*b;
    EXPECT_EQ(fraction.num, 8); << "Multiplication";
    EXPECT_EQ(fraction.den, 9); << "Multiplication";

    fraction = a*b + 4*c;
    EXPECT_EQ(fraction, {360, 81}) << "Arithmetic";
}

TEST(Maths, Test_Vector2){
    Vector2 a = {-4, 4};
    Vector2 b = {-6, 8};
    Vector2 zero = {0, 0};
    Vector2 vector;
    float scalar;

    vector = Normalise(a);
    EXPECT_EQ(vector, {-0.707107, 0.707107}) << "Normalise";
    scalar = Angle(b);
    EXPECT_EQ(scalar, 2.2143) << "Angle";
    scalar = Angle_Deg(a);
    EXPECT_EQ(scalar, 135) << "Angle_Deg";
    scalar = Magnitude_Squared(b);
    EXPECT_EQ(scalar, 100) << "Magnitude_Squared";
    scalar = Magnitude(a);
    EXPECT_EQ(scalar, 5.65685) << "Magnitude";
    scalar = a*b;
    EXPECT_EQ(scalar, 56) << "Multiplication";
    EXPECT_EQ(Is_Zero(zero), 1) << "Is_Zero";
    EXPECT_EQ(Not_Zero(zero), 0) << "Not_Zero";

    vector = Degree_Constructor(10, -45);
    Vector2 c(vector);
    EXPECT_EQ(vector, {7.07107, -7.07107}) << "Degree_Constructor";
    vector = Polar_Constructor(10, -45);
    Vector2 d(vector);
    EXPECT_EQ(vector, {5.25322, -8.50904}) << "Polar_Constructor";
    vector = c+d;
    EXPECT_EQ(vector, {12.3243, -15.5801}) << "Addition";
    vector = c-d;
    EXPECT_EQ(vector, {1.81785, 1.43797}) << "Subtraction";
    vector = 5*c;
    EXPECT_EQ(vector, {35.3553, -35.3553}) << "Scalar-Vector Multiplication";
    vector = d*8;
    EXPECT_EQ(vector, {42.0258, -68.0723}) << "Vector-Scalar Multiplication";
    vector = c/10;
    EXPECT_EQ(vector, {0.707107, -0.707107}) << "Vector Division";
    c += a;
    EXPECT_EQ(c, {3.07107, -3.07107}) << "+=";
    d -= b;
    EXPECT_EQ(d, {11.2532, -16.509}) << "-=";
    c *= 5;
    EXPECT_EQ(d, {15.3553, -15.3553}) << "*=";
    d /= 8;
    EXPECT_EQ(d, {1.40665, -2.06363}) << "/=";
}

// void Test_Vector3(){
//     cout<<"\nTest_Vector3\n";
//     Vector3 a = {2, 5, 8};
//     Vector3 b = {4, 3, -1};
//
//     Print_Vector3("a = ", a);
//     Print_Vector3("b = ", b);
//     Print_Vector3("a.cross(b) = ", a.cross(b) );
//     cout<<"Magnitude(a) = "<<Magnitude(a)<<'\n';
//     cout<<"Phi(b) = "<<Phi(b)<<'\n';
//     cout<<"Phi_Deg(a) = "<<Phi_Deg(a)<<'\n';
//     cout<<"Theta(b) = "<<Theta(b)<<'\n';
//     cout<<"Theta_Deg(a) = "<<Theta_Deg(a)<<'\n';
//     cout<<"a*b = "<<a*b<<'\n';
//     Vector3 c = Sphere_Constructor(12, 45, -45);
//     Vector3 d = Sphere_Deg_Constructor(12, 45, -45);
//     Print_Vector3("c = Sphere_Constructor(12, 45, -45) = ", c);
//     Print_Vector3("d = Sphere_Deg_Constructor(12, 45, -45) = ", d);
//     Print_Vector3("c+d = ", c+d);
//     Print_Vector3("c-d = ", c-d);
// }
