#ifndef Vector2_hpp
#define Vector2_hpp

struct Vector2{
    float x, y;
};

float Angle(const Vector2& u);
float Angle_Deg(const Vector2& u);
float Ipow(float x, int y);
float Magnitude_Squared(const Vector2& u);
float Magnitude(const Vector2& u);
float operator*(const Vector2& u, const Vector2& v);
bool Is_Zero(const Vector2& u);
bool Not_Zero(const Vector2& u);
bool operator==(const Vector2& u, const Vector2& v);
Vector2 Degree_Constructor(float magnitude, float degrees);
Vector2 Normalise(const Vector2& u);
Vector2 Polar_Constructor(float magnitude, float angle);
Vector2 operator+(const Vector2& u, const Vector2& v);
Vector2 operator-(const Vector2& u, const Vector2& v);
Vector2 operator*(float A, const Vector2& u);
Vector2 operator*(const Vector2& u, float A);
Vector2 operator/(const Vector2& u, float A);
void operator+=(Vector2& u, const Vector2& v);
void operator-=(Vector2& u, const Vector2& v);
void operator*=(Vector2& u, float A);
void operator/=(Vector2& u, float A);
void Print_Vector2(const char* msg, const Vector2& u);

#endif //Vector2_hpp
