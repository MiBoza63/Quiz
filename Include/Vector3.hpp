#include <iostream>
#include <cmath>
using std::ostream;
using std::cout;

class Vector3{
public:
    float x, y, z;

    Vector3 cross(const Vector3& v) const;
};

float Magnitude(const Vector3& u);
float Phi(const Vector3& u);
float Theta(const Vector3& u);
float Phi_Deg(const Vector3& u);
float Theta_Deg(const Vector3& u);
float operator*(const Vector3& u, const Vector3& v);
Vector3 Sphere_Constructor(float Magnitude, float theta, float phi);
Vector3 Sphere_Deg_Constructor(float Magnitude, float theta, float phi);
Vector3 operator+(const Vector3& u, const Vector3& v);
Vector3 operator-(const Vector3& u, const Vector3& v);

void Print_Vector3(const char* msg, const Vector3& u);
