
#ifndef VECTOR_H
#define VECTOR_H

// Standard headers.
#include <math.h>
#include <iostream>


class vec3
{
  public:

    // Constructors.
    vec3() : v{0.0, 0.0, 0.0} {}
    vec3(double x) : v{x, x, x} {} 
    vec3(double x, double y, double z) : v{x, y, z} {}

    // Getters.
    double x() const { return v[0]; }
    double y() const { return v[1]; }
    double z() const { return v[2]; }

    // Functions.
    vec3 operator-() const { return vec3(-v[0], -v[1], -v[2]); }
    double operator[](int i) const { return v[i]; }
    double& operator[](int i) { return v[i]; }

    vec3& operator+=(const vec3 &c)
    {
        v[0] += c.x();
        v[1] += c.y();
        v[2] += c.z();
        return *this;
    }

    vec3& operator*=(const double c)
    {
        v[0] *= c;
        v[1] *= c;
        v[2] *= c;
        return *this;
    }

    void print_vec()
    {
        std::cerr<<"x "<<v[0]<<" "<<"y "<<v[1]<<" "<<"z "<<v[2]<<" "<<std::endl;
    }

    void print_vec() const
    {
        std::cerr<<"x "<<v[0]<<" "<<"y "<<v[1]<<" "<<"z "<<v[2]<<" "<<std::endl;
    }

    inline double length() const 
    {
        return std::sqrt(length_squared());
    }

    inline double length_squared() const
    {
        return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
    }

    // Attributes.
    double v[3];
    
};

// Functions.

inline vec3 operator*(double t, const vec3 &v)
{
    return vec3(t * v.x(), t * v.y(), t * v.z());
}

inline vec3 operator*(const vec3 &v, double t)
{
    return vec3(t * v.x(), t * v.y(), t * v.z());
}

inline vec3 operator*(const vec3 &u, const vec3 &v)
{
    return vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

inline vec3 operator+(const vec3 &u, const vec3  &v)
{
    return vec3(v.x() + u.x(), v.y() + u.y(), v.z() + u.z());
}

inline vec3 operator-(const vec3 &u, const vec3  &v)
{
    return vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

inline vec3 operator/(vec3 v, double t)
{
    return (1/t) * v;
}

inline vec3 normalize(vec3 v)
{
    return v / v.length();
}

inline double dot(const vec3 &u, const vec3 &v)
{
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z(); 
}

inline vec3 cross(const vec3 &u, const vec3& v)
{
    return vec3(u.y() * v.z() - u.z() * v.y(),
                u.z() * v.x() - u.x() * v.z(),
                u.x() * v.y() - u.y() * v.x());
}

inline vec3 floor(vec3 p)
{
    return vec3(
        floor(p.x()),
        floor(p.y()),
        floor(p.z()));
}


// Aliases.
using point3 = vec3; // 3D point
using color = vec3; // RGB color

#endif
