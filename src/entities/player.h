#pragma once
#include "../common/common.h"

class Player {
    Position position;

public:
    Player();

    Position GetPosition();

    void Move(int dx, int dy);
};

