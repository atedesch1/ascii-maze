#include "game.h"
#include <curses.h>
#include <ncurses.h>

Game::Game()
    : screen(100, 100)
    , map("src/assets/map1.txt")
{
    fov = 80;
    running = false;
}

void Game::Init()
{
    running = true;
    std::thread eventHandler(&Game::ProcessEvents, this);
    while (running) {
        Render();
        screen.PrintScreen();
    }
    eventHandler.join();
}

void Game::Render()
{
    auto playerPos = player.GetPosition();
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
        case KEY_BACKSPACE:
            running = false;
            return;
            break;
        default:
            break;
        }
    }
}
