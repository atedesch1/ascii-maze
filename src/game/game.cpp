#include "game.h"

Game::Game()
    : screen(100, 100)
{
    fov = 80;
}

void Game::Init()
{
    std::thread eventHandler(&Game::ProcessEvents, this);
    while (true) {
        Render();
        screen.PrintScreen();
    }
    eventHandler.join();
}

void Game::Render()
{
    Position playerPos = player.GetPosition();
    screen.ClearBuffer();
    screen.SetBuffer(playerPos.y, playerPos.x, 'x');
}

void Game::ProcessEvents()
{
    while (true) {
        switch (screen.GetInput()) {
        case KEY_UP:
            player.Move(0, 1);
            break;
        case KEY_DOWN:
            player.Move(0, -1);
            break;
        case KEY_RIGHT:
            player.Move(1, 0);
            break;
        case KEY_LEFT:
            player.Move(-1, 0);
            break;
        default:
            break;
        }
    }
}
