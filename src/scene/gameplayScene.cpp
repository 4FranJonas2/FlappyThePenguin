#include "scene/gameplayScene.h"

Player player;
Player player2;
Obstacle obstacle;

static Texture2D background;
static Texture2D waterReflection;
static Texture2D clouds;
static Texture2D moon;

static float scrollingBack = 0.0f;
static float scrollingMidBack = 0.0f;
static float scrollingMid = 0.0f;
static float scrollingFront = 0.0f;

void initGameplay()
{
	initBackground();
	player.isPlayer1 = true;
	player2.isPlayer1 = false;
	initPlayer(player);
	initPlayer(player2);
	initObstacle(obstacle);
}



void loadGameplay()
{
	loadPlayer(player);
	loadPlayer(player2);
}

void updateGameplay(bool& menuOn, bool& gameOver)
{
	updatePlayer(player);
	updatePlayer(player2);
	updateObstacle(obstacle);

	checkCollision(player);
	checkCollision(player2);

	if (player.life <= 0)
	{
		gameOver = true;
		drawGameOver(menuOn, gameOver);
	}

	updateBackground();
}

void checkCollision(Player& actualPlayer)
{
	bool collisionTop = (actualPlayer.position.x + actualPlayer.radius >= obstacle.position.x &&
		actualPlayer.position.x - actualPlayer.radius <= obstacle.position.x + obstacle.width &&
		actualPlayer.position.y + actualPlayer.radius >= 0 &&
		actualPlayer.position.y - actualPlayer.radius <= obstacle.topHeight);

	bool collisionBottom = (actualPlayer.position.x + actualPlayer.radius >= obstacle.position.x &&
		actualPlayer.position.x - actualPlayer.radius <= obstacle.position.x + obstacle.width &&
		actualPlayer.position.y + actualPlayer.radius >= obstacle.topHeight + obstacle.gap &&
		actualPlayer.position.y - actualPlayer.radius <= obstacle.topHeight + obstacle.gap + obstacle.bottomHeight);
		
	if (collisionTop || collisionBottom)
	{
		initObstacle(obstacle); 
		actualPlayer.life--;
	}

}

void drawGameplay(bool& menuOn, bool& pauseOn)
{
	drawParalaxBackgournd();
	ClearBackground(GREEN);
	drawPlayer(player);
	drawPlayer(player2);
	drawObstacle(obstacle);

	drawButton(pauseGame);
	//drawPauseButtonTitle();

	if (isButtonPressed(pauseGame))
	{
		pauseOn = true;
		menuOn = false;
	}

	DrawText(TextFormat(" Life %01i", player.life), screenWidthMin , screenHeightMin , 30, RED);
}

void initBackground()
{
	background = LoadTexture("res/Ocean_6/backgorund.png");
	waterReflection = LoadTexture("res/Ocean_6/reflection.png");
	clouds = LoadTexture("res/Ocean_6/clouds.png");
	moon = LoadTexture("res/Ocean_6/moon.png");
}

void updateBackground()
{
	scrollingBack -= 100.0f * GetFrameTime();
	scrollingMidBack -= 100.0f * GetFrameTime();
	scrollingMid -= 150.0f * GetFrameTime();
	scrollingFront -= 150.0f * GetFrameTime();

	if (scrollingBack <= -background.width * 2) scrollingBack = static_cast<float>(screenWidthMin);
	if (scrollingMidBack <= -waterReflection.width * 2) scrollingBack = static_cast<float>(screenWidthMin);
	if (scrollingMid <= -clouds.width * 2) scrollingMid = static_cast<float>(screenWidthMin);
	if (scrollingFront <= -moon.width * 2) scrollingFront = static_cast<float>(screenWidthMin);
}

void drawParalaxBackgournd()
{
	DrawTextureEx(background, Vector2{ scrollingBack, static_cast<float>(screenHeightMin) }, 0.0f, 2.5f, WHITE);
	DrawTextureEx(background, Vector2{ background.width * 2 + scrollingBack, static_cast<float>(screenHeightMin) }, 0.0f, 2.5f, WHITE);

	DrawTextureEx(waterReflection, Vector2{ scrollingMidBack, static_cast<float>(screenHeightMin) }, 0.0f, 2.5f, WHITE);
	DrawTextureEx(waterReflection, Vector2{ waterReflection.width * 2 + scrollingMidBack, static_cast<float>(screenHeightMin) }, 0.0f, 2.5f, WHITE);

	DrawTextureEx(moon, Vector2{ scrollingFront, static_cast<float>(screenHeightMin) + 20 }, 0.0f, 2.5f, WHITE);
	DrawTextureEx(moon, Vector2{ moon.width * 2 + scrollingFront, static_cast<float>(screenHeightMin) + 20 }, 0.0f, 2.5f, WHITE);

	DrawTextureEx(clouds, Vector2{ scrollingMid, static_cast<float>(screenHeightMin)}, 0.0f, 2.0f, WHITE);
	DrawTextureEx(clouds, Vector2{ clouds.width * 2 + scrollingMid, static_cast<float>(screenHeightMin)}, 0.0f, 2.0f, WHITE);	
}

void unloadGameplay()
{
	UnloadTexture(background);
	UnloadTexture(clouds);
	UnloadTexture(moon);
}
