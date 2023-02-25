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
