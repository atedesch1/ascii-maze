#pragma once
#include "../common/vectors.h"
#include "../common/common.h"

enum MovementDirection {
    Forwards,
    Backwards,
    Left,
    Right,
};

class Player {
    Vector2D<double> position;
    Vector2D<double> direction;
    double speed;

public:
    Player();

    Vector2D<double> GetPosition();

    Vector2D<double> GetDirection();

    void Move(MovementDirection mov);

    void Rotate(const double theta);
};
