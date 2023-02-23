#include "player.h"

Player::Player()
{
    position.x = 0;
    position.y = 0;
}

Position Player::GetPosition()
{
    return position;
}

void Player::Move(int dx, int dy)
{
    position.x += dx;
    position.y += dy;
}
