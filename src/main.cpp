#include <curses.h>
#include <ncurses.h>
#include <string.h>
#include <thread>

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
        keypad(window, true);
        refresh(); // Refresh screen
    }

    void SetBuffer(int i, int j, char c) {
        buffer[i][j] = c;
    }

    void ClearBuffer() {
        for (int i = 0; i < height; i++) {
            memset((this->buffer)[i], ' ', width);
        }
    }

    int GetInput() {
        return wgetch(window);
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

struct Position {
    int x, y;
};

class Player {
    Position position;

public:
    Player()
    {
        position.x = 0;
        position.y = 0;
    }

    Position GetPosition() {
        return position;
    }

    void Move(int dx, int dy)
    {
        position.x += dx;
        position.y += dy;
    }
};

class Game {
    Screen screen;
    Player player;

public:
    Game()
        : screen(100, 100)
    {
    }

    void Init()
    {
        std::thread eventHandler(&Game::ProcessEvents, this);
        while (true) {
            Render();
            screen.PrintScreen();
        }
    }

    void Render() {
        Position playerPos = player.GetPosition();
        screen.ClearBuffer();
        screen.SetBuffer(playerPos.y, playerPos.x, 'x');
    }

    void ProcessEvents()
    {
        while (true) {
            int keyPressed = screen.GetInput(); 
            switch (keyPressed) {
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
};

int main()
{
    auto game = Game();
    game.Init();
}
