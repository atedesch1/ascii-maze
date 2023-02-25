#pragma once
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

//static wchar_t shade[5] = {
//   ' ',
//   '░',
//   '▒',
//   '▓',
//   '█',
//};

double GetShade(const double shade);

double DegreesToRadians(const double theta);

double RadiansToDegrees(const double theta);
