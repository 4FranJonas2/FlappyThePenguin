#include "game.h"

#include "raylib.h"

//#include "scene/menuScene.h"

namespace gameLoop
{
	bool menuOn = true;
	bool controlsOn = false;
	bool creditsOn = false;
	bool creditsOn2 = false;
	bool exitOn = false;
	bool gameOver = false;
	bool pauseOn = false;
	bool musicPause = false;
	float timePlayed = 0.0f;

	void run()
	{
		Initialization();
		PlayMusicStream(menuMusic);
		PlayMusicStream(gamePlayMusic);

		while (!WindowShouldClose() && !endGame)
		{
			update();
			draw();
		}

		unloadGame();

		close();
	}

	static void Initialization()
	{
		InitWindow(screenWidth, screenHeight, "Flappt The Penguin");

		InitAudioDevice();
		menuMusic = LoadMusicStream("res/sound/menuMusic.mp3");
		gamePlayMusic = LoadMusicStream("res/sound/gamePlayMusic.mp3");
		jumpSound = LoadSound("res/sound/flySound.wav");
		buttonSound = LoadSound("res/sound/overButSound.wav");
		impactSound = LoadSound("res/sound/iceImpact.wav");
		impactGround = LoadSound("res/sound/impactGround.wav");
		gameOverSound = LoadSound("res/sound/ gameOverSound.wav");

		gamePlay::initGameplay();

		initMenu();

		gamePlay::loadGameplay();
	}

	static void update()
	{
		if (menuOn || creditsOn || controlsOn)
		{
			UpdateMusicStream(menuMusic);

			if (IsKeyPressed(KEY_P))
			{
				musicPause = !musicPause;

				if (musicPause) PauseMusicStream(menuMusic);
				else ResumeMusicStream(menuMusic);
			}

			timePlayed = GetMusicTimePlayed(menuMusic) / GetMusicTimeLength(menuMusic);

			if (timePlayed > 1.0f) timePlayed = 1.0f;
		}

		if (!menuOn && !gameOver && !creditsOn && !creditsOn2 && !controlsOn && !pauseOn)
			gamePlay::updateGameplay(menuOn, gameOver);

	}

	static void draw()
	{
		BeginDrawing();

		if (menuOn)
		{
			gamePlay::drawParalaxBackgournd();
			drawMenu(menuOn, controlsOn, creditsOn);

		}
		else if (controlsOn)
		{
			gamePlay::drawParalaxBackgournd();
			drawConstrols(menuOn, controlsOn);
		}
		else if (creditsOn)
		{
			gamePlay::drawParalaxBackgournd();
			drawCredits(menuOn, creditsOn);
		}
		else if (gameOver)
		{
			gamePlay::drawParalaxBackgournd();
			drawGameOver(menuOn, gameOver);

		}
		else if (pauseOn)
		{
			gamePlay::drawParalaxBackgournd();
			drawPause(menuOn, pauseOn);

		}
		else
		{
			gamePlay::drawGameplay(menuOn, pauseOn);
		}

		EndDrawing();
	}

	static void unloadGame()
	{
		
		gamePlay::unloadGameplay();
		UnloadMusicStream(menuMusic);
		UnloadMusicStream(gamePlayMusic);
		UnloadSound(jumpSound);
		UnloadSound(buttonSound);
		UnloadSound(impactSound);
		UnloadSound(impactGround);
		UnloadSound(gameOverSound);
	}

	static void close()
	{
		CloseAudioDevice();
		CloseWindow();
	}
}
