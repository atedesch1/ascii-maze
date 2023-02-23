#pragma once
#include <fstream>
#include <ios>

#define MAP_LEGTH 8

class Map {
    char** map;

public:
    Map(const char* mapFileName);
    ~Map();
    void LoadMap(const char* mapFileName);
    char** GetMap();
};
