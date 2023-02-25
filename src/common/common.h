#pragma once
#include "vectors.h"
#include <cmath>

static char shade[13] = {
    ' ',
    '.',
    ',',
    '-',
    '~',
    ':',
    ';',
    '=',
    '!',
    '*',
    '#',
    '$',
    '@',
};

// static wchar_t shade[5] = {
//    ' ',
//    '░',
//    '▒',
//    '▓',
//    '█',
// };

double GetShade(const double shade);

double DegreesToRadians(const double theta);

double RadiansToDegrees(const double theta);

Vector3D<double> ConvertVectorSystem(Vector2D<double>& direction,
    Vector3D<double>& v);
