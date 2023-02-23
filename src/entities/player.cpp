#include "player.h"

Player::Player()
{
    position.x = 0;
    position.y = 0;
}

Position<float> Player::GetPosition()
{
    return position;
}

void Player::Move(float dx, float dy)
{
    position.x += dx;
    position.y += dy;
}
