#include "player.h"
#include <cmath>

Player::Player()
    : position(40, 40)
    , direction(1, 0)
{
    direction = direction.ToUnit();
    runningSpeed = 1;
    turningSpeed = DegreesToRadians(5);
}

Vector2D<double> Player::GetPosition()
{
    return position;
}

Vector2D<double> Player::GetDirection()
{
    return direction;
}

void Player::Move(Direction mov)
{
    switch (mov) {
    case Forwards:
        position = position + runningSpeed * direction;
        break;
    case Backwards:
        position = position - runningSpeed * direction;
        break;
    case Left:
        position = position + runningSpeed * direction.Rotate(DegreesToRadians(90));
        break;
    case Right:
        position = position - runningSpeed * direction.Rotate(DegreesToRadians(90));
        break;
    default:
        break;
    }
}

void Player::Rotate(Direction rot)
{
    switch (rot) {
    case Left:
        direction = direction.Rotate(turningSpeed);
        break;
    case Right:
        direction = direction.Rotate(-turningSpeed);
        break;
    default:
        break;
    }
}

Vector3D<double> Player::ToMapVectorSystem(Vector3D<double> v)
{
    return Vector3D<double>(
        v.x * direction.x - v.y * direction.y,
        v.x * direction.y + v.y * direction.x,
        v.z);
}
