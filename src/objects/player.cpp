#include "objects/player.h"

bool onePlayerGame;
Player player;
Player player2;
Sound jumpSound;
Sound impactGround;
float playerTimer = 0.0f;
float playerResetTimer = 1.5f;

void initPlayer(Player& actualPlayer)
{
	actualPlayer.position = { static_cast<float>(screenWidthMin) + 200,
		   static_cast<float>(screenHeight) / 2.0f };

	actualPlayer.speed = { 0.0f, 0.0f };

	actualPlayer.radius = 20.0f;
	actualPlayer.isActive = true;
	actualPlayer.life = 3;
	actualPlayer.isHit = false;
	actualPlayer.isInmune = false;

	actualPlayer.points = 0;
	actualPlayer.isAlive = true;
	actualPlayer.grvity = 500;
	
	actualPlayer.currentFrame = 0;
	actualPlayer.framesCounter = 0;
	actualPlayer.framesSpeed = 8;
	actualPlayer.frameTimeAccum = 0.0f;
	
	actualPlayer.frameRec = { 0.0f, 0.0f, 64.0f, 64.0f };
}

void loadPlayer(Player& actualPlayer)
{
	actualPlayer.texture = LoadTexture("res/spritesheet.png");
}

void updatePlayer(Player& actualPlayer)
{
	if (actualPlayer.isAlive)
	{
		if (actualPlayer.isHit)
		{
			playerTimer -= (GetFrameTime() < playerTimer) ? GetFrameTime() : playerTimer;

			if (playerTimer <= 0)
			{
				actualPlayer.isHit = false;
				actualPlayer.isInmune = false;
				playerTimer = playerResetTimer;
			}
			else
			{
				actualPlayer.isInmune = true;
			}
		}

		actualPlayer.speed.y += actualPlayer.grvity * GetFrameTime();

		actualPlayer.position.y += actualPlayer.speed.y * GetFrameTime();


		if (IsKeyPressed(KEY_SPACE) && actualPlayer.isPlayer1)
		{
			PlaySound(jumpSound);
			actualPlayer.speed.y = -200.f;
		}

		else if (IsKeyPressed(KEY_UP) && !actualPlayer.isPlayer1)
		{
			PlaySound(jumpSound);
			actualPlayer.speed.y = -200.f;
		}

		actualPlayer.framesCounter++;

		if (((actualPlayer.framesCounter / 720) % 2) == 1 && actualPlayer.life > 0)
		{
			actualPlayer.points += 1 ;

			actualPlayer.framesCounter = 0;
		}

		if (actualPlayer.position.y > screenHeight)
		{
			actualPlayer.life--;

			actualPlayer.position = { static_cast<float>(screenWidthMin) + 200,
			   static_cast<float>(screenHeight) / 2.0f };
			PlaySound(impactGround);
			actualPlayer.speed = { 0.0f, 0.0f };
		}

		if (actualPlayer.position.y < screenHeightMin + actualPlayer.radius)
		{
			actualPlayer.position.y = static_cast<float>(screenHeightMin) + actualPlayer.radius;
		}

		actualPlayer.frameTimeAccum += GetFrameTime();

		if (actualPlayer.frameTimeAccum >= (1.0f / actualPlayer.framesSpeed))
		{

			actualPlayer.frameTimeAccum = 0.0f;

			actualPlayer.currentFrame++;

			if (actualPlayer.currentFrame > 3)
				actualPlayer.currentFrame = 0;

			actualPlayer.frameRec.y = static_cast<float>(actualPlayer.currentFrame) * 64.0f;
		}

	}
	if (actualPlayer.life <= 0)
	{
		actualPlayer.isAlive = false;
	}
}

void drawPlayer(Player actualPlayer)
{
	if (actualPlayer.isAlive)
	{
		float p1TextPosXCorrect = 10.0f;
		float p1TextPosYCorrect = 55.0f;

		DrawCircle(static_cast<int>(actualPlayer.position.x), static_cast<int>(actualPlayer.position.y), actualPlayer.radius, BLUE);

		if (actualPlayer.isPlayer1)
			DrawText("P1", static_cast<int> (actualPlayer.position.x - p1TextPosXCorrect), static_cast<int> (actualPlayer.position.y - p1TextPosYCorrect), 20, ORANGE);
		if (!actualPlayer.isPlayer1)
			DrawText("P2", static_cast<int> (actualPlayer.position.x - p1TextPosXCorrect), static_cast<int> (actualPlayer.position.y - p1TextPosYCorrect), 20, RED);

		DrawTextureRec(actualPlayer.texture, actualPlayer.frameRec,
			{ actualPlayer.position.x - actualPlayer.frameRec.width / 2,
			  actualPlayer.position.y - actualPlayer.frameRec.height / 2 }, WHITE);
	}
}

void unloadPlayer(Player& actualPlayer)
{
	UnloadTexture(actualPlayer.texture);
}