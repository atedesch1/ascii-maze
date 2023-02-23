#pragma once
#include <thread>
#include "../entities/player.h"
#include "../screen/screen.h"
#include "map.h"

class Game {
    Screen screen;
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
