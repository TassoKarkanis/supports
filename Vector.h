#ifndef VECTOR_H
#define VECTOR_H

#include <ostream>

// Represents a point or a vector with 3D Cartesian coordinates.
class Vector
{
public:
    Vector();
    Vector(double x, double y, double z);

    // Returns the length of the vector.
    double length() const;

    // Returns the dot product of this vector with another one.
    double dot(const Vector& b) const;

    // Returns a new vector with the same direction but having length 1.
    Vector normalized() const;

    // The coordinates of the vector are public.
    double m_v[3];
};

//
// operators and free functions
//

// Vector addition
Vector operator+(const Vector& a, const Vector& b);

// Vector subtraction
Vector operator-(const Vector& a, const Vector& b);

// Scalar/vector multiplication.
Vector operator*(double a, const Vector&b);

// Output the std::ostream for debugging.
std::ostream& operator<<(std::ostream& os, const Vector& a);

// Returns distance between two points.
double distance(const Vector& a, const Vector& b);

#endif
