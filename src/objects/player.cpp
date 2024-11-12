#include "objects/player.h"

#include "objects/utils.h"

//Sound loseSfx;
//Sound boostSfx;

void initPlayer(Player& player)
{
	player.position = { static_cast<float>(screenWidthMin) + 200,
		   static_cast<float>(screenHeight) / 2.0f };

	player.speed = { 0.0f, 0.0f };

	player.radius = 20.0f;
	player.isActive = true;
	player.life = 3;

	player.point = 0;

	player.grvity = 500;

	player.currentFrame = 0;
	player.framesCounter = 0;
	player.framesSpeed = 8;
	player.frameTimeAccum = 0.0f;

	player.frameRec = { 0.0f, 0.0f, 64.0f, 64.0f };
}

void loadPlayer(Player& player)
{
	player.texture = LoadTexture("res/spritesheet.png");
}

void updatePlayer(Player& player)
{
	player.speed.y += player.grvity * GetFrameTime();

	player.position.y += player.speed.y * GetFrameTime();

	if (IsKeyDown(KEY_SPACE) && player.isPlayer1)
		player.speed.y = -200.f;

	else if (IsKeyDown(KEY_UP) && !player.isPlayer1)
		player.speed.y = -200.f;

	if (player.position.y > screenHeight)
	{
		player.life--;

		player.position = { static_cast<float>(screenWidthMin) + 200,
		   static_cast<float>(screenHeight) / 2.0f };

		player.speed = { 0.0f, 0.0f };
	}

	if (player.position.y < screenHeightMin + player.radius)
	{
		player.position.y = static_cast<float>(screenHeightMin) + player.radius;
	}

	player.frameTimeAccum += GetFrameTime();

	if (player.frameTimeAccum >= (1.0f / player.framesSpeed))
	{
		player.frameTimeAccum = 0.0f;

		player.currentFrame++;

		if (player.currentFrame > 3)
			player.currentFrame = 0;

		player.frameRec.y = static_cast<float>(player.currentFrame) * 64.0f;
	}
}

void drawPlayer(Player player)
{
	float p1TextPosXCorrect = 10.0f;
	float p1TextPosYCorrect = 55.0f;

	DrawCircle(static_cast<int>(player.position.x), static_cast<int>(player.position.y), player.radius, BLUE);

	if (player.isPlayer1)
		DrawText("P1", static_cast<int> (player.position.x- p1TextPosXCorrect), static_cast<int> (player.position.y- p1TextPosYCorrect), 20, ORANGE);
	if (!player.isPlayer1)
		DrawText("P2", static_cast<int> (player.position.x- p1TextPosXCorrect), static_cast<int> (player.position.y- p1TextPosYCorrect), 20, RED);

	DrawTextureRec(player.texture, player.frameRec,
		{ player.position.x - player.frameRec.width / 2,
		  player.position.y - player.frameRec.height / 2 }, WHITE);
}

void unloadPlayer(Player& player)
{
	UnloadTexture(player.texture);
}
