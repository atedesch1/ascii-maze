#pragma once
#include "../common/common.h"
#include "../common/vectors.h"

enum Direction {
    Forwards,
    Backwards,
    Left,
    Right,
};

class Player {
    Vector2D<double> position;
    Vector2D<double> direction;
    double runningSpeed;
    double turningSpeed;

public:
    Player();

    Vector2D<double> GetPosition();

    Vector2D<double> GetDirection();

    void Move(Direction mov);

    void Rotate(Direction rot);

    Vector3D<double> ToMapVectorSystem(Vector3D<double> v);
};
