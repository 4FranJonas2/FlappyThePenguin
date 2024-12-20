#pragma once

#include "raylib.h"

#include "objects/utils.h"

extern bool onePlayerGame;
extern Sound jumpSound;

struct Player
{
    Vector2 position;
    Vector2 speed;

    bool matchStart;
    bool isPlayer1;

    float radius;
    bool isActive;
    bool isAlive;
    bool isHit;
    bool isInmune;
    int points;
    int life;
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

void initPlayer(Player& player);
void loadPlayer(Player& player);
void updatePlayer(Player& player);
void drawPlayer(Player player);
void unloadPlayer(Player& player);