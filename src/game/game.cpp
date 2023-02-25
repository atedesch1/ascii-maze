#include "game.h"

Game::Game()
    : screen(120, 25)
    , map("src/assets/map2.txt")
{
    pixelSize = 0.001;
    fov = DegreesToRadians(100);
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
    screen.ClearBuffer();
    double halfPixelSize = pixelSize / 2;
    double halfScreenWidth = screen.GetWidth() * halfPixelSize;
    double halfScreenHeight = screen.GetHeight() * halfPixelSize;
    double halfTileSize = map.GetTileSize() / 2;
    double screenDistance = halfScreenWidth / std::tan(fov / 2);
    auto playerPosition3D = player.GetPosition().To3D();
    auto playerDirection = player.GetDirection();
    double differentialFactor = .1;
    for (int i = 0; i < screen.GetHeight(); i++) {
        for (int j = 0; j < screen.GetWidth(); j++) {
            auto tPlayer = Vector3D<double>(
                screenDistance,
                halfScreenWidth - (1 + 2 * j) * halfPixelSize,
                halfScreenHeight - (1 + 2 * i) * halfPixelSize);
            auto t = ConvertVectorSystem(playerDirection, tPlayer);
            auto tUnit = t.ToUnit();
            auto dt = differentialFactor * tUnit;
            auto hitVector = playerPosition3D + t;

            while (
                std::abs(hitVector.z) <= halfTileSize
                && !map.IsWall3D(hitVector)) {
                hitVector = hitVector + dt;
            }

            if (map.IsWall3D(hitVector)) {
                auto hitVector2D = hitVector.To2D();
                auto normal = map.GetClosestWallNormal(hitVector2D);
                auto shadeFactor = -normal.Dot(tUnit);
                auto distance = t.Abs();
                auto distanceFactor = distance / (.08 * map.GetTileSize());
                if (distanceFactor > 1) {
                    shadeFactor /= distanceFactor * distanceFactor;
                }
                screen.SetBuffer(i, j, GetShade(shadeFactor));
            }
        }
    }
}

void Game::ProcessEvents()
{
    while (true) {
        switch (screen.GetInput()) {
        case KEY_UP:
            player.Move(Forwards);
            break;
        case KEY_DOWN:
            player.Move(Backwards);
            break;
        case KEY_RIGHT:
            player.Move(Right);
            break;
        case KEY_LEFT:
            player.Move(Left);
            break;
        case 'a':
            player.Rotate(Left);
            break;
        case 'd':
            player.Rotate(Right);
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
