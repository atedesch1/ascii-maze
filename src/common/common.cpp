#include "common.h"

double GetShade(const double value)
{
    return shade[(int)(value * (sizeof(shade) - 1))];
}

double DegreesToRadians(const double theta)
{
    return M_PI * theta / 180;
}

double RadiansToDegrees(const double theta)
{
    return 180 * theta / M_PI;
}

Vector3D<double> ConvertVectorSystem(Vector2D<double>& direction, Vector3D<double>& v)
{
    return Vector3D<double>(
        v.x * direction.x - v.y * direction.y,
        v.x * direction.y + v.y * direction.x,
        v.z);
}
