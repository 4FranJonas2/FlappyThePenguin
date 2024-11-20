#include "objects/buttons.h"

#include "raylib.h"

Button onePlayer;
Button twoPlayer;
Button controls;
Button credits;
Button backToMenu;
Button exitGame;
Button pauseGame;
Button resumeGame;
Button playAgain;
Sound buttonSound;
bool isOnButton = false;

void initButton(Button& b, int xPos, int yPos)
{
	b.posX = xPos;
	b.posY = yPos;
	b.width = buttonWidth;
	b.height = buttonHeight;
}

void drawButton(Button& b)
{
	bool mouseOverButton = CheckCollisionPointRec(GetMousePosition(), Rectangle{ static_cast<float>(b.posX), static_cast<float>(b.posY),
		static_cast<float>(b.width), static_cast<float>(b.height) });
	Color buttonColor;

	if (mouseOverButton)
	{
		buttonColor = DARKGRAY;
	}
	else
	{
		buttonColor = LIGHTGRAY;
	}
	
	if (mouseOverButton && isOnButton)
	{
		PlaySound(buttonSound);
		isOnButton = false;
	}
	

	isOnButton = mouseOverButton;

	DrawRectangle(b.posX, b.posY, b.width, b.height, buttonColor);
}

bool isButtonPressed(Button& b)
{
	return CheckCollisionPointRec(GetMousePosition(),
		Rectangle{ static_cast<float>(b.posX), static_cast<float>(b.posY),
		static_cast<float>(b.width), static_cast<float>(b.height) }) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void drawPlayTitle()
{
	DrawText(TextFormat("1 PLAYER"), screenWidth / 2 - 70, 210, fontSize, RED);
}

void drawPlayTitle2()
{
	DrawText(TextFormat("2 PLAYERS"), screenWidth / 2 - 85, 310, fontSize, RED);
}

void drawControlTitle()
{
	DrawText(TextFormat("CONTROLS"), screenWidth / 2 - 80, 410, fontSize, RED);
}

void drawCreditsTitle()
{
	DrawText(TextFormat("CREDITS"), screenWidth / 2 - 70, 510, fontSize, RED);
}

void drawExitTitle()
{
	DrawText(TextFormat("EXIT"), screenWidth / 2 - 40, 660, fontSize, RED);
}

void drawBackToMenuTitle()
{
	DrawText(TextFormat("Back Menu"), screenWidth - 200, screenHeight - 50, fontSize, RED);
}

void drawPauseButtonTitle()
{
	DrawText(TextFormat("PAUSE"), screenWidth - 150, 560, fontSize, RED);
}

void drawResumeGameTitle()
{
	DrawText(TextFormat("RESUME"), screenWidth / 2 - 160, 510, fontSize, RED);
}

void drawPlayAgainTitle()
{
	DrawText(TextFormat("PLAY AGAIN"), screenWidth / 2 - 90, 510, fontSize, RED);
}

