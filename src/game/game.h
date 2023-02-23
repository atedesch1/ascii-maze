#pragma once
#include <thread>
#include "../entities/player.h"
#include "../screen/screen.h"

class Game {
    Screen screen;
    Player player;
    float fov;

public:
    Game();

    void Init();

    void Render();

    void ProcessEvents();
};
