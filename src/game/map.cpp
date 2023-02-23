#include "map.h"

Map::Map(const char* mapFileName)
{
    this->map = new char*[MAP_LEGTH];
    for (int i = 0; i < MAP_LEGTH; i++) {
        (this->map)[i] = new char[MAP_LEGTH];
    }
    LoadMap(mapFileName);
}

Map::~Map()
{
    for (int i = 0; i < MAP_LEGTH; i++) {
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
    for (int i = 0; i < MAP_LEGTH; i++) {
        for (int j = 0; j < MAP_LEGTH; j++) {
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

