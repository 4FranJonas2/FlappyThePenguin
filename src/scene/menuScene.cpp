#include "scene/menuScene.h"

//#include "scene/gameplayScene.h"

//extern Texture2D background;
//extern Music menuMusic;
bool endGame;

void initMenu()
{
	//background = LoadTexture("res/background.png");
	//
	//menuMusic = LoadMusicStream("res/menuMusic.mp3");
	//
	//SetMusicVolume(menuMusic, 0.5f);
	//
	//PlayMusicStream(menuMusic);
	int midScreenX = screenWidth / 2;
	endGame = false;

	initButton(onePlayer, midScreenX - 100, 200);
	initButton(twoPlayer, midScreenX - 100, 300);
	initButton(controls, midScreenX - 100, 400);
	initButton(credits, midScreenX - 100, 500);
	initButton(exitGame, midScreenX - 100, 650);

	initButton(backToMenu, screenWidth - 220, screenHeight - 60);
	initButton(resumeGame, midScreenX - 200, 500);
	initButton(playAgain, midScreenX - 100, 500);
}

void drawMenu(bool& menuOn, bool& controlsOn, bool& creditsOn)
{
	//UpdateMusicStream(menuMusic);

	//DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

	
	ClearBackground(BLACK);

	DrawText(TextFormat("Flappy The Penguin"), screenWidth / 2 - 250, screenHeightMin + 50, 50, RED);

	drawButton(onePlayer);
	drawButton(twoPlayer);
	drawButton(controls);
	drawButton(credits);
	drawButton(exitGame);

	drawPlayTitle();
	drawPlayTitle2();
	drawControlTitle();
	drawCreditsTitle();
	drawExitTitle();

	if (isButtonPressed(onePlayer))
	{
		menuOn = false;
		onePlayerGame = true;
		resetGame();
	}

	if (isButtonPressed(twoPlayer))
	{
		menuOn = false;
		onePlayerGame = false;
		resetGame();
	}

	if (isButtonPressed(controls))
	{
		controlsOn = true;
		menuOn = false;
	}

	if (isButtonPressed(credits))
	{
		creditsOn = true;
		menuOn = false;
	}

	if (isButtonPressed(exitGame))
	{
		//StopMusicStream(menuMusic);
		endGame = true;
	}

	if (isButtonPressed(backToMenu))
	{
		menuOn = true;
		creditsOn = false;
		controlsOn = false;
	}

	DrawText("0.4", screenWidth - 50, screenHeight - 50, 30, RED);
}

void drawConstrols(bool& menuOn, bool& controlsOn)
{
	//DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

	//UpdateMusicStream(menuMusic);

	ClearBackground(BLACK);

	DrawText("CONTROLS", screenWidth / 2 - 100, 100, 40, WHITE);

	DrawText("Player 1 Spacebar: ", screenWidth / 2 - 220, 250, 30, WHITE);

	DrawText("Jump", screenWidth / 2 + 100, 250, 30, WHITE);

	DrawText("Player 2 Up Key: ", screenWidth / 2 - 220, 350, 30, WHITE);

	DrawText("Jump", screenWidth / 2 + 100, 350, 30, WHITE);

	drawBackToMenu(menuOn, controlsOn);

}

void drawCredits(bool& menuOn, bool& creditsOn)
{
	//DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

	//UpdateMusicStream(menuMusic);

	ClearBackground(BLACK);

	DrawText(TextFormat("CREDITS"), screenWidth / 2 - 60, 50, 30, WHITE);

	DrawText("Developer: ", screenWidth / 2 - 250, 150, 30, WHITE);

	DrawText("Valentin Villar / Tronik in ITCH.IO", screenWidth / 2 -50, 150, 25, WHITE);
	DrawText("Francisco Jonas / 4FranJonas2 in ITCH.IO", screenWidth / 2-50 , 180, 25, WHITE);

	DrawText("Background By: ", screenWidth / 2 - 250, 250, 30, WHITE);

	DrawText(" in ITCH.IO", screenWidth / 2 + 50, 250, 30, WHITE);

	DrawText("Player By: ", screenWidth / 2 - 250, 350, 30, WHITE);

	DrawText("Valentin Villar with Piskel", screenWidth / 2 + 50, 350, 30, WHITE);

	DrawText("Obstacle By: ", screenWidth / 2 - 250, 450, 30, WHITE);

	DrawText(" in ITCH.IO", screenWidth / 2 + 50, 450, 30, WHITE);

	DrawText("Library: ", screenWidth / 2 - 250, 550, 30, WHITE);

	DrawText("Raylib", screenWidth / 2 + 50, 550, 30, WHITE);

	drawBackToMenu(menuOn, creditsOn);

}

void drawBackToMenu(bool& boolTrue, bool& boolFalse)
{
	ClearBackground(BLACK);

	drawButton(backToMenu);

	drawBackToMenuTitle();

	if (isButtonPressed(backToMenu))
	{
		boolTrue = true;
		boolFalse = false;
	}
}

void drawPause(bool& menuOn, bool& pauseOn)
{
	//DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

	//UpdateMusicStream(menuMusic);

	ClearBackground(BLACK);

	DrawText(TextFormat("Pause game"), screenWidth / 2 - 150, screenHeight / 2 - 100, 50, WHITE);

	DrawText(TextFormat("What Will You Do"), screenWidth / 2 - 200, screenHeight / 2 - 30, 50, WHITE);

	drawButton(resumeGame);
	drawResumeGameTitle();

	if (isButtonPressed(resumeGame))
		pauseOn = false;

	drawBackToMenu(menuOn, pauseOn);
}

void drawGameOver(bool& menuOn, bool& gameOver)
{
	//DrawTextureEx(background, Vector2{ 0,0 }, 0.0f, 5.0f, WHITE);

	//UpdateMusicStream(menuMusic); 

	ClearBackground(BLACK);

	DrawText(TextFormat("Game Over"), screenWidth / 2 - 150, screenHeight / 2 - 100, 50, WHITE);

	DrawText(TextFormat("What Will You Do"), screenWidth / 2 - 200, screenHeight / 2 - 30, 50, WHITE);

	drawButton(playAgain);
	drawPlayAgainTitle();

	if (isButtonPressed(playAgain))
	{
		gameOver = false;
		resetGame();
	}

	drawBackToMenu(menuOn, gameOver);
}

void resetGame()
{
	initPlayer(player);
	initPlayer(player2);
	initObstacle(obstacle);
}

void unloadMenu()
{
	//UnloadTexture(background);
	//UnloadMusicStream(menuMusic);
}


