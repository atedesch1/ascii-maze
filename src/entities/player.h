#pragma once
#include "../common/common.h"

class Player {
    Vector2D<double> position;

public:
    Player();

    Vector2D<double> GetPosition();

    void Move(double dx, double dy);
};
