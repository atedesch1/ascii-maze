#pragma once
#include <thread>
#include <curses.h>
#include <ncurses.h>
#include <cmath>
#include "../entities/player.h"
#include "../screen/screen.h"
#include "map.h"

class Game {
    Screen screen;
    double pixelSize;
    Player player;
    Map map;
    float fov;
    bool running;

public:
    Game();

    void Init();

    void Render();

    void ProcessEvents();
};
