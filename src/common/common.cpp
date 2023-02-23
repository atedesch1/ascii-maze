#include "common.h"

double DegreesToRadians(const double theta)
{
    return M_PI * theta / 180;
}

double RadiansToDegrees(const double theta)
{
    return 180 * theta / M_PI;
}
