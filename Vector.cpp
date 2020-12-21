#include <cmath>
#include <Vector.h>

Vector::Vector()
{
    m_v[0] = 0;
    m_v[1] = 0;
    m_v[2] = 0;
}

Vector::Vector(double x, double y, double z)
{
    m_v[0] = x;
    m_v[1] = y;
    m_v[2] = z;
}

double
Vector::length() const
{
    const Vector& a = *this;
    return std::sqrt(a.dot(a));
}

double
Vector::dot(const Vector& b) const
{
    const Vector& a = *this;
    return a.m_v[0]*b.m_v[0] + a.m_v[1]*b.m_v[1] + a.m_v[2]*b.m_v[2];
}

Vector
Vector::normalized() const
{
    double a = 1.0/length();
    return a*(*this);
}

Vector
operator+(const Vector& a, const Vector& b)
{
    return Vector(
        a.m_v[0] + b.m_v[0],
        a.m_v[1] + b.m_v[1],
        a.m_v[2] + b.m_v[2]);
}

Vector
operator-(const Vector& a, const Vector& b)
{
    return Vector(
        a.m_v[0] - b.m_v[0],
        a.m_v[1] - b.m_v[1],
        a.m_v[2] - b.m_v[2]);
}

Vector
operator*(double a, const Vector&b)
{
    return Vector(
        a*b.m_v[0],
        a*b.m_v[1],
        a*b.m_v[2]);
}

std::ostream&
operator<<(std::ostream& os, const Vector& a)
{
    os << "("
       << a.m_v[0] << ", "
       << a.m_v[1] << ", "
       << a.m_v[2] << ")";
    return os;
}

double
distance(const Vector& a, const Vector& b)
{
    return (a - b).length();
}
