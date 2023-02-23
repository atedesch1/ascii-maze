#include <ncurses.h>
#include <thread>
#include <string.h>

class Screen {
    WINDOW* window;
    int width, height;
    char** buffer;

public:
    Screen(int width, int height)
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
        refresh(); // Refresh screen
    }

    void PrintScreen()
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
};

class Game {
    Screen screen;

public:
    Game()
        : screen(100, 100)
    {
    }

    void Init() {
        while (true) {
            Render();
            screen.PrintScreen();
        }
    }

    void Render() { }

    void ProcessEvents() { }
};

int main()
{
    auto game = Game();
    game.Init();
}
