#pragma once

#include "objects/obstacle.h"

struct Button
{
	int width;
	int height;
	int posX;
	int posY;
};

extern Button onePlayer;
extern Button twoPlayer;
extern Button controls;
extern Button credits;
extern Button backToMenu;
extern Button exitGame;
extern Button pauseGame;
extern Button resumeGame;
extern Button playAgain;

void initButton(Button& b, int xPos, int yPos);
void drawButton(Button& b);
bool isButtonPressed(Button& b);

void drawPlayTitle();
void drawPlayTitle2();
void drawControlTitle();
void drawCreditsTitle();
void drawExitTitle();
void drawBackToMenuTitle();
//void drawPauseButtonTitle();
void drawResumeGameTitle();
void drawPlayAgainTitle();