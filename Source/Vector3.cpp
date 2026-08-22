#include <iostream>
#include <cmath>
#include "Vector3.hpp"
using std::ostream;

Vector3 Vector3::cross(const Vector3& v) const{
    Vector3 result;
    result.x = y*v.z - z*v.y;
    result.y = z*v.x - x*v.z;
    result.z = x*v.y - y*v.x;

    return result;
}

float Magnitude(const Vector3& u){
    return sqrt( pow(u.x,2) + pow(u.y,2) + pow(u.z,2) );
}

float Phi(const Vector3& u){
    float r0 = sqrt( pow(u.x, 2) + pow(u.y, 2) );

    if(u.z == 0)
        return M_PI/2;
    else
        return atan(u.z/r0);
}

float Theta(const Vector3& u){
    if(u.x == 0)
        return M_PI/2;
    else if(u.x < 0)
        return atan(u.y/u.x) + M_PI;
    else
        return atan(u.y/u.x);
}

float Phi_Deg(const Vector3& u){
    return 180*Phi(u)/M_PI;
}

float Theta_Deg(const Vector3& u){
    return 180*Theta(u)/M_PI;
}

float operator*(const Vector3& u, const Vector3& v){
    return u.x*v.x + u.y*v.y + u.z*v.z;
}

Vector3 Sphere_Constructor(float Magnitude, float theta, float phi){
    Vector3 result;

    float r0 = Magnitude*sin(phi);
    result.x = r0*cos(theta);
    result.y = r0*sin(theta);
    result.z = Magnitude*cos(phi);

    return result;
}

Vector3 Sphere_Deg_Constructor(float Magnitude, float theta, float phi){
    const float conversion_factor = 180/M_PI;
    theta *= conversion_factor;
    phi *= conversion_factor;
    Vector3 result = Sphere_Constructor(Magnitude, theta, phi);

    return result;
}

Vector3 operator+(const Vector3& u, const Vector3& v){
    Vector3 result = {u.x + v.x, u.y + v.y, u.z + v.z};
    return result;
}
Vector3 operator-(const Vector3& u, const Vector3& v){
    Vector3 result = {u.x - v.x, u.y - v.y, u.z - v.z};
    return result;
}

void Print_Vector3(const char* msg, const Vector3& u){
    std::cout<<msg<<'['<<u.x<<", "<<u.y<<", "<<u.z<<"]\n";
}
