#include "player.h"

Player::Player()
    : position(0, 0)
{
}

Vector2D<double> Player::GetPosition()
{
    return position;
}

void Player::Move(double dx, double dy)
{
    position.x += dx;
    position.y += dy;
}
