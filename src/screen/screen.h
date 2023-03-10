#pragma once
#include <ncurses.h>
#include <string.h>

class Screen {
    WINDOW* window;
    int width, height;
    char** buffer;

public:
    Screen(int width, int height);
    ~Screen();

    void SetBuffer(int i, int j, char c);

    void ClearBuffer();

    int GetInput();

    void PrintScreen();

    int GetWidth();
    
    int GetHeight();
};
