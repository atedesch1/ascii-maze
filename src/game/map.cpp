#include "map.h"

Map::Map(const char* mapFileName)
{
    this->tileSize = 15;
    this->map = new char*[MAP_LENGTH];
    for (int i = 0; i < MAP_LENGTH; i++) {
        (this->map)[i] = new char[MAP_LENGTH];
    }
    LoadMap(mapFileName);
}

Map::~Map()
{
    for (int i = 0; i < MAP_LENGTH; i++) {
        delete[] (this->map)[i];
    }
    delete[] map;
}

void Map::LoadMap(const char* mapFileName)
{
    std::fstream mapFile;
    mapFile.open(mapFileName, std::ios::in);
    if (!mapFile) {
        throw std::ios_base::failure("map file doesnt exist");
    }

    char mapTile;
    for (int i = 0; i < MAP_LENGTH; i++) {
        for (int j = 0; j < MAP_LENGTH; j++) {
            mapFile >> mapTile;
            if (mapTile == '\n') {
                mapFile >> mapTile;
            }
            if (mapFile.eof()) {
                return;
            }
            map[i][j] = mapTile;
        }
    }
    mapFile.close();
}

char** Map::GetMap()
{
    return map;
}

bool Map::IsWall2D(Vector2D<double>& position)
{
    int i = position.x / tileSize;
    int j = position.y / tileSize;
    if (i < 0 || i >= MAP_LENGTH || j < 0 || j >= MAP_LENGTH) {
        return false;
    }

    return map[i][j] == '#';
}

bool Map::IsWall3D(Vector3D<double>& position)
{
    if (std::abs(position.z) > tileSize / 2) {
        return false;
    }

    auto position2D = position.To2D();
    return IsWall2D(position2D);
}

double Map::GetTileSize()
{
    return tileSize;
}

Vector3D<double> Map::GetClosestWallNormal(Vector2D<double>& position)
{
    double distances[4] = {
        position.x - std::floor(position.x),
        std::ceil(position.x) - position.x,
        position.y - std::floor(position.y),
        std::ceil(position.y) - position.y,
    };
    double smallestDistance = distances[0];
    int closestWallIndex = 0;
    for (int i = 1; i < 4; i++) {
        if (distances[i] < smallestDistance) {
            smallestDistance = distances[i];
            closestWallIndex = i;
        }
    }
    return tileNormals[closestWallIndex];
}
