#pragma once

#include "raylib.h"

#include "objects/player.h"


struct Obstacle
{
    Vector2 position;
    Vector2 speed;
    bool isActive;
    int width;
    int topHeight;
    int gap;
    int bottomHeight;
};

extern Obstacle obstacle[maxObstacles];
//extern Sound loseSfx;
//extern Sound boostSfx;

void initObstacle(Obstacle obst[]);
void loadObstacle();
void updateObstacle(Obstacle obst[]);
void drawObstacle(Obstacle obst[]);
void unloadObstacle();