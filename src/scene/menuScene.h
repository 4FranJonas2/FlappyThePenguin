#pragma once

#include "objects/buttons.h"

extern bool endGame;
extern Music menuMusic;


void initMenu();

void drawMenu(bool& menuOn, bool& controlsOn, bool& creditsOn);

void drawConstrols(bool& menuOn, bool& controlsOn);

void drawCredits(bool& menuOn, bool& creditsOn);

void drawBackToMenu(bool& boolTrue, bool& boolFalse);

void drawPause(bool& menuOn, bool& pauseOn);

void drawGameOver(bool& menuOn, bool& gameOver);

void resetGame();


