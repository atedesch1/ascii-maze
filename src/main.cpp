#include <curses.h>
#include <ncurses.h>
#include <string.h>
#include <thread>
#include "./game/game.h"

int main()
{
    auto game = Game();
    game.Init();
}
