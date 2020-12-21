#ifndef VECTOR_H
#define VECTOR_H

#include <ostream>

class Vector
{
public:
    Vector();
    Vector(double x, double y, double z);

    double length() const;
    double dot(const Vector& b) const;
    Vector normalized() const;

    double m_v[3];
};

// operators
Vector operator+(const Vector& a, const Vector& b);
Vector operator-(const Vector& a, const Vector& b);
Vector operator*(double a, const Vector&b);
std::ostream& operator<<(std::ostream& os, const Vector& a);

// free functions
double distance(const Vector& a, const Vector& b);

#endif
