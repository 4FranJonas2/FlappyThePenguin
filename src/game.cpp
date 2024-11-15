#include "game.h"

#include "raylib.h"

//#include "scene/menuScene.h"

namespace gameLoop
{
	/*int screenWidth = 1024;
	int screenHeight = 768;
	int screenWidthMin = 0;
	int screenHeightMin = 0;*/

	bool menuOn = true;
	bool controlsOn = false;
	bool creditsOn = false;
	bool creditsOn2 = false;
	bool exitOn = false;
	bool gameOver = false;
	bool pauseOn = false;

	//Music menuMusic;
	//Music gameplayMusic;

	void run()
	{
		Initialization();

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

		//InitAudioDevice();

		gamePlay::initGameplay();

		initMenu();

		gamePlay::loadGameplay();
	}

	static void update()
	{
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
		unloadMenu();
		gamePlay::unloadGameplay();
	}

	static void close()
	{
		CloseAudioDevice();
		CloseWindow();
	}
}
