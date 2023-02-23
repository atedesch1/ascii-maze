#include "screen.h"

Screen::Screen(int width, int height)
{
    this->width = width;
    this->height = height;
    this->buffer = new char*[height];
    for (int i = 0; i < height; i++) {
        (this->buffer)[i] = new char[width];
        memset((this->buffer)[i], '~', width);
    }
    initscr(); // Initialize screen
    curs_set(0); // Set cursor to invisible
    clear(); // Clear screen
    noecho(); // Input doesnt show
    cbreak(); // Get input without carriage return
    this->window = newwin(height, width, 0, 0);
    keypad(window, true);
    refresh(); // Refresh screen
}

void Screen::SetBuffer(int i, int j, char c)
{
    buffer[i][j] = c;
}

void Screen::ClearBuffer()
{
    for (int i = 0; i < height; i++) {
        memset((this->buffer)[i], ' ', width);
    }
}

int Screen::GetInput()
{
    return wgetch(window);
}

void Screen::PrintScreen()
{
    wclear(window);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            wprintw(window, "%c", buffer[i][j]);
        }
        wprintw(window, "\n");
    }
    wrefresh(window);
}
