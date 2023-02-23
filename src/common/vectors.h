#pragma once
#include <cmath>

template <typename T>
class Vector2D {
public:
    T x, y;

    Vector2D(T x, T y)
    {
        this->x = x;
        this->y = y;
    }

    T dot(const Vector2D<T>& v)
    {
        return x * v.x + y * v.y;
    }

    double abs()
    {
        return sqrt(x * x + y * y);
    }

    Vector2D<T> rotate(const double theta)
    {
        double sinTheta = std::sin(theta);
        double cosTheta = std::cos(theta);
        return Vector2D<T>(
            x * cosTheta - y * sinTheta,
            x * sinTheta + y * cosTheta);
    }
};

template <typename T>
Vector2D<T> operator+(const Vector2D<T>& v, const Vector2D<T>& w)
{
    return Vector2D<T>(v.x + w.x, v.y + w.y);
}

template <typename T>
Vector2D<T> operator-(const Vector2D<T>& v, const Vector2D<T>& w)
{
    return Vector2D<T>(v.x - w.x, v.y - w.y);
}

template <typename T>
Vector2D<T> operator*(T& a, const Vector2D<T>& v)
{
    return Vector2D<T>(a * v.x, a * v.y);
}

template <typename T>
Vector2D<T> operator*(const Vector2D<T>& v, T& a)
{
    return Vector2D<T>(a * v.x, a * v.y);
}

template <typename T>
class Vector3D {
public:
    T x, y, z;

    Vector3D(T x, T y, T z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    T dot(const Vector3D<T>& v)
    {
        return x * v.x + y * v.y + z * v.z;
    }

    double abs()
    {
        return sqrt(x * x + y * y + z * z);
    }

    Vector3D<T> rotate(const double thetax, const double thetay, const double thetaz)
    {
    }
};

template <typename T>
Vector3D<T> operator+(const Vector3D<T>& v, const Vector3D<T>& w)
{
    return Vector3D<T>(v.x + w.x, v.y + w.y, v.z + w.z);
}

template <typename T>
Vector3D<T> operator-(const Vector3D<T>& v, const Vector3D<T>& w)
{
    return Vector3D<T>(v.x - w.x, v.y - w.y, v.z - w.z);
}

template <typename T>
Vector3D<T> operator*(T& a, const Vector3D<T>& v)
{
    return Vector3D<T>(a * v.x, a * v.y, a * v.z);
}
template <typename T>
Vector3D<T> operator*(const Vector3D<T>& v, T& a)
{
    return Vector3D<T>(a * v.z, a * v.y, a * v.z);
}
