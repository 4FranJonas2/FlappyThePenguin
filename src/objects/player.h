#pragma once

#include "raylib.h"

#include "objects/utils.h"

extern bool onePlayerGame;

struct Player
{
    Vector2 position;
    Vector2 speed;

    bool matchStart;
    bool isPlayer1;

    float radius;
    bool isActive;
    int life;
    int point;
    int lastPoints;
    int grvity;
    int currentFrame;
    int framesCounter;
    int framesSpeed;
    float frameTimeAccum;

    Rectangle frameRec;
    Texture2D texture;
};

extern Player player;
extern Player player2;

//extern Sound loseSfx;
//extern Sound boostSfx;

void initPlayer(Player& player);
void loadPlayer(Player& player);
void updatePlayer(Player& player);
void drawPlayer(Player player);
void unloadPlayer(Player& player);