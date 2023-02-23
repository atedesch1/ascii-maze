#pragma once
#include "../common/common.h"

class Player {
    Position<float> position;

public:
    Player();

    Position<float> GetPosition();

    void Move(float dx, float dy);
};
