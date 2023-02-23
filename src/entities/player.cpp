#include "player.h"

Player::Player()
    : position(0, 0)
    , direction(0, 1)
{
    speed = 1;
}

Vector2D<double> Player::GetPosition()
{
    return position;
}

Vector2D<double> Player::GetDirection()
{
    return direction;
}

void Player::Move(MovementDirection mov)
{
    switch (mov) {
    case Forwards:
        position = position + speed * direction;
        break;
    case Backwards:
        position = position - speed * direction;
        break;
    case Left:
        position = position + speed * direction.rotate(DegreesToRadians(90));
        break;
    case Right:
        position = position + speed * direction.rotate(DegreesToRadians(-90));
        break;
    default:
        break;
    }
}

void Player::Rotate(const double theta)
{
    direction = direction.rotate(DegreesToRadians(theta));
}
