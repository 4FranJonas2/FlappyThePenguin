#pragma once

#include "objects/player.h"

void initGameplay();

void loadGameplay();

void updateGameplay(bool& menuOn, bool& gameOver);

void checkCollision(Player& actualPlayer);

void drawGameplay(bool& menuOn, bool& pauseOn);

void initBackground();

void updateBackground();

void drawParalaxBackgournd();

void resetGame();

void unloadGameplay();
