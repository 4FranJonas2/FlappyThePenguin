#pragma once

struct Button
{
	int width;
	int height;
	int posX;
	int posY;
};

Button onePlayer;
Button twoPlayer;
Button controls;
Button credits;
Button backToMenu;
Button exitGame;
Button pauseGame;
Button resumeGame;
Button playAgain;

void initButton(Button& b, int xPos, int yPos);
void drawButton(Button& b);
bool isButtonPressed(Button& b);

void drawPlayTitle();
void drawControlTitle();
void drawCreditsTitle();
void drawExitTitle();
void drawBackToMenuTitle();
void drawPauseButtonTitle();
void drawResumeGameTitle();
void drawPlayAgainTitle();