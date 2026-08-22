#include <Equations.hpp>
#include <iostream>
#include <cmath>
using pair = std::pair<float, float>;
using std::ostream;
using std::cout;

float Abs(float x){
    return x > 0 ? x : -x;
}

pair Quadratic(float a, float b, float c){
    float determinant = b*b - 4*a*c;
    if(determinant < 0)
        cout<<"Error. Determinant = "<<determinant<<'\n';
    float sqrt_determinant = sqrt(determinant);
    float x1 = (-b - sqrt_determinant)/2/a;
    float x2 = (-b + sqrt_determinant)/2/a;
    pair result = {x1, x2};
    return result;
}

//Solve f(x) = 0 numerically
float Newton_Raphson(float x, float tol, float max_iter){
    float y = f(x);
    for(int iter = 1; iter <= max_iter && Abs(y) > tol; iter++){
        x -= y/fp(x);
        y = f(x);
    }
    return x;
}

float Secant(float x1, float x2, float tol, float max_iter){
    using std::swap;
    pair p1( {x1, f(x1)} );
    pair p2( {x2, f(x2)} );
    if( Abs(p2.second) < Abs(p1.second) )
        swap(p1, p2);
    for(int iter = 1; (iter <= max_iter) && (Abs(p1.second) > tol); iter++){
        float next = p2.first + p2.second*(p2.first - p1.first)/(p1.second - p2.second);
        p2 = {next, f(next)};
        if( Abs(p2.second) < Abs(p1.second) )
            swap(p1, p2);
    }

    return p1.first;
}
