#include "scene/gameplayScene.h"

Music gamePlayMusic;
Sound impactSound;
Sound gameOverSound;

namespace gamePlay
{
	bool musicPause = false;
	float timePlayed = 0.0f;

	void initGameplay()
	{
		initBackground();
		player.isPlayer1 = true;
		player2.isPlayer1 = false;
		initPlayer(player);
		if (!onePlayerGame)
			initPlayer(player2);
		initObstacle(obstacle);

		initButton(pauseGame, screenWidth / 2 + 300, 700);
	}

	void loadGameplay()
	{
		loadPlayer(player);
		if (!onePlayerGame)
			loadPlayer(player2);

	}

	void updateGameplay(bool& menuOn, bool& gameOver)
	{
		if (!menuOn || gameOver)
		{
			UpdateMusicStream(gamePlayMusic);

			if (IsKeyPressed(KEY_P))
			{
				musicPause = !musicPause;

				if (musicPause) PauseMusicStream(gamePlayMusic);
				else ResumeMusicStream(gamePlayMusic);
			}

			timePlayed = GetMusicTimePlayed(gamePlayMusic) / GetMusicTimeLength(gamePlayMusic);

			if (timePlayed > 1.0f) timePlayed = 1.0f;
		}

		updatePlayer(player);
		if (!onePlayerGame)
			updatePlayer(player2);
		updateObstacle(obstacle);

		checkCollision(player);
		if (!onePlayerGame)
			checkCollision(player2);

		if (!onePlayerGame)
		{
			if (player.life <= 0 && player2.life <= 0)
			{
				gameOver = true;
				drawGameOver(menuOn, gameOver);
			}
		}
		else
		{
			if (player.life <= 0)
			{
				gameOver = true;
				PlaySound(gameOverSound);
				drawGameOver(menuOn, gameOver);
			}
		}

		updateBackground();
	}

	void checkCollision(Player& actualPlayer)
	{
		for (int i = 0; i < maxObstacles; i++)
		{
			if (actualPlayer.isAlive && !actualPlayer.isInmune)
			{
				bool collisionTop = (actualPlayer.position.x + actualPlayer.radius >= obstacle[i].position.x &&
					actualPlayer.position.x - actualPlayer.radius <= obstacle[i].position.x + obstacle[i].width &&
					actualPlayer.position.y + actualPlayer.radius >= 0 &&
					actualPlayer.position.y - actualPlayer.radius <= obstacle[i].topHeight);

				bool collisionBottom = (actualPlayer.position.x + actualPlayer.radius >= obstacle[i].position.x &&
					actualPlayer.position.x - actualPlayer.radius <= obstacle[i].position.x + obstacle[i].width &&
					actualPlayer.position.y + actualPlayer.radius >= obstacle[i].topHeight + obstacle[i].gap &&
					actualPlayer.position.y - actualPlayer.radius <= obstacle[i].topHeight + obstacle[i].gap + obstacle[i].bottomHeight);

				if (collisionTop || collisionBottom && !actualPlayer.isHit)
				{
					PlaySound(impactSound);
					actualPlayer.life--;
					actualPlayer.isHit = true;
					break;
				}
			}
		}
	}

	void drawGameplay(bool& menuOn, bool& pauseOn)
	{
		drawParalaxBackgournd();
		ClearBackground(GREEN);
		drawPlayer(player);
		if (!onePlayerGame)
			drawPlayer(player2);
		drawObstacle(obstacle);

		drawButton(pauseGame);
		drawPauseButtonTitle();

		if (isButtonPressed(pauseGame))
		{
			pauseOn = true;
			menuOn = false;
		}

		DrawText(TextFormat(" Life %01i", player.life), screenWidthMin, screenHeightMin, 30, ORANGE);
		DrawText(TextFormat(" P1 Points %i", player.points), screenWidthMin + 120, screenHeightMin, 30, ORANGE);

		if (!onePlayerGame)
		{
			DrawText(TextFormat(" Life %01i", player2.life), screenWidth - 100, screenHeightMin, 30, RED);
			DrawText(TextFormat(" P2 Points %i", player.points), screenWidth - 350, screenHeightMin, 30, RED);
		}

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

		DrawTextureEx(clouds, Vector2{ scrollingMid, static_cast<float>(screenHeightMin) }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(clouds, Vector2{ clouds.width * 2 + scrollingMid, static_cast<float>(screenHeightMin) }, 0.0f, 2.0f, WHITE);
	}

	void unloadGameplay()
	{
		UnloadTexture(background);
		UnloadTexture(clouds);
		UnloadTexture(moon);
	}
}

