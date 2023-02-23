#pragma once
#include <cmath>

template <typename T>
class Vector2D {
public:
    T x, y;

    Vector2D<T>(T x, T y)
    {
        this->x = x;
        this->y = y;
    }

    Vector2D<T> operator+(const Vector2D<T>& v)
    {
        return Vector2D<T>(x + v.x, y + v.y);
    }
    Vector2D<T> operator-(const Vector2D<T>& v)
    {
        return Vector2D<T>(x - v.x, y - v.y);
    }
    T dot(const Vector2D<T>& v)
    {
        return x * v.x + y * v.y;
    }
    double abs()
    {
        return sqrt(x * x + y * y);
    }
    void rotate(const double theta)
    {
        double sinTheta = std::sin(theta);
        double cosTheta = std::cos(theta);
        x = x * cosTheta - y * sinTheta;
        y = x * sinTheta + y * cosTheta;
    }
};

template <typename T>
class Vector3D {
public:
    T x, y, z;

    Vector3D<T>(T x, T y, T z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector3D<T> operator+(const Vector3D<T>& v)
    {
        return Vector3D<T>(x + v.x, y + v.y, z + v.z);
    }
    Vector3D<T> operator-(const Vector3D<T>& v)
    {
        return Vector3D<T>(x - v.x, y - v.y, z - v.z);
    }
    T dot(const Vector3D<T>& v)
    {
        return x * v.x + y * v.y + z * v.z;
    }
    double abs()
    {
        return sqrt(x * x + y * y + z * z);
    }
    void rotate(const double thetax, const double thetay, const double thetaz)
    {
    }
};
