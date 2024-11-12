#include "objects/buttons.h"

#include "raylib.h"

#include "utils.h"

void initButton(Button& b, int xPos, int yPos)
{
	b.posX = xPos;
	b.posY = yPos;
	b.width = 200;
	b.height = 50;
}

void drawButton(Button& b)
{
	Color buttonColor = CheckCollisionPointRec(GetMousePosition(),
		Rectangle{ static_cast<float>(b.posX), static_cast<float>(b.posY),
		static_cast<float>(b.width), static_cast<float>(b.height) }) ? DARKGRAY : LIGHTGRAY;

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
	DrawText(TextFormat("PLAY"), screenWidth / 2 - 40, 210, 30, RED);
}

void drawControlTitle()
{
	DrawText(TextFormat("CONTROLS"), screenWidth / 2 - 80, 310, 30, RED);
}

void drawCreditsTitle()
{
	DrawText(TextFormat("CREDITS"), screenWidth / 2 - 70, 410, 30, RED);
}

void drawExitTitle()
{
	DrawText(TextFormat("EXIT"), screenWidth / 2 - 40, 510, 30, RED);
}

void drawBackToMenuTitle()
{
	DrawText(TextFormat("Back Menu"), screenWidth - 200, screenHeight -50, 30, RED);
}

void drawPauseButtonTitle()
{
	DrawText(TextFormat("PAUSE"), screenWidth - 150, 560, 30, RED);
}

void drawResumeGameTitle()
{
	DrawText(TextFormat("RESUME"), screenWidth / 2 - 160, 510, 30, RED);
}

void drawPlayAgainTitle()
{
	DrawText(TextFormat("PLAY AGAIN"), screenWidth / 2 - 190, 510, 30, RED);
}

