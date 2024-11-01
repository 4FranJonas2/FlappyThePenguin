#pragma once

#include "raylib.h"

#include "objects/player.h"

struct Obstacle
{
    Vector2 position;
    Vector2 speed;
    int width;
    int height;
};

 

//extern Sound loseSfx;
//extern Sound boostSfx;

void initObstacle(Obstacle& o);
void loadObstacle();
void updateObstacle(Obstacle& o);
void drawObstacle(Obstacle& o);
void unloadObstacle();