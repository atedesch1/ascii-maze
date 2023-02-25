#pragma once
#include "../common/vectors.h"
#include <fstream>
#include <ios>
#include <cmath>

#define MAP_LENGTH 8

static Vector3D<double> tileNormals[4] = {
    Vector3D<double>(-1, 0, 0),
    Vector3D<double>(1, 0, 0),
    Vector3D<double>(0, -1, 0),
    Vector3D<double>(0, 1, 0),
};

class Map {
    char** map;
    double tileSize;

public:
    Map(const char* mapFileName);
    ~Map();
    void LoadMap(const char* mapFileName);
    char** GetMap();
    bool IsWall2D(Vector2D<double>& position);
    bool IsWall3D(Vector3D<double>& position);
    double GetTileSize();
    Vector3D<double> GetClosestWallNormal(Vector2D<double>& position);
};
