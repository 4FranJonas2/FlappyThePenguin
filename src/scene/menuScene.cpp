#include "scene/menuScene.h"

bool endGame;
Music menuMusic;

void initMenu()
{
	SetMusicVolume(menuMusic, 0.5f);
	
	int midScreenX = screenWidth / 2;
	endGame = false;

	initButton(onePlayer, midScreenX - 100, 200);
	initButton(twoPlayer, midScreenX - 100, 300);
	initButton(controls, midScreenX - 100, 400);
	initButton(credits, midScreenX - 100, 500);
	initButton(exitGame, midScreenX - 100, 650);

	initButton(backToMenu, screenWidth - 220, screenHeight - 60);
	initButton(resumeGame, midScreenX - 200, 500);
	initButton(playAgain, midScreenX +50, 500);
}

void drawMenu(bool& menuOn, bool& controlsOn, bool& creditsOn)
{
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
		endGame = true;
	}

	if (isButtonPressed(backToMenu))
	{
		menuOn = true;
		creditsOn = false;
		controlsOn = false;
	}

	DrawText("1.0", screenWidth - 50, screenHeight - 50, 30, RED);
}

void drawConstrols(bool& menuOn, bool& controlsOn)
{
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
	ClearBackground(BLACK);

	DrawText(TextFormat("CREDITS"), screenWidth / 2 - 60, 20, 30, WHITE);

	DrawText("Developer: ", 100, 80, 30, WHITE);

	DrawText("Valentin Villar / Tronik in ITCH.IO", screenWidth / 2 -50, 60, 25, WHITE);
	DrawText("Francisco Jonas / 4FranJonas2 in ITCH.IO", screenWidth / 2-50 , 80, 25, WHITE);

	DrawText("Background By: ", 100, 140, 30, WHITE);

	DrawText(" https://free-game-assets.itch.io/ocean-and-clouds-free-pixel-art-backgrounds", 400, 130, 15, WHITE);

	DrawText("Player By: ", 100, 200, 30, WHITE);

	DrawText("Valentin Villar with Piskel", 400, 200, 30, WHITE);

	DrawText("Sounds Effects By: ", 100, 260, 30, WHITE);

	DrawText(" https://kenney.nl/assets/interface-sounds / https://kenney.nl/assets/impact-sounds", 400, 270, 12, WHITE);

	DrawText("Menu Music by: ", 100, 320, 30, WHITE);

	DrawText("https://pixabay.com/sound-effects/game-music-loop-7-145285/", 400, 330, 12, WHITE);

	DrawText("Game Music by: ", 100, 380, 30, WHITE);

	DrawText("https://pixabay.com/sound-effects/cinematic-music-sketches-11-cinematic-percussion-sketch-116186/", 400, 390, 12, WHITE);

	DrawText("Library: ", 100, 560, 30, WHITE);

	DrawText("Raylib", 300, 560, 30, WHITE);

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
	UpdateMusicStream(menuMusic);

	ClearBackground(BLACK);

	DrawText(TextFormat("Pause game"), screenWidth / 2 - 150, screenHeight / 2 - 100, 50, WHITE);

	DrawText(TextFormat("What Will You Do"), screenWidth / 2 - 200, screenHeight / 2 - 30, 50, WHITE);

	drawButton(resumeGame);
	drawResumeGameTitle();

	drawButton(playAgain);
	drawPlayAgainTitle();

	if (isButtonPressed(resumeGame))
		pauseOn = false;

	if (isButtonPressed(playAgain))
	{
		pauseOn = false;
		resetGame();
	}

	drawBackToMenu(menuOn, pauseOn);
}

void drawGameOver(bool& menuOn, bool& gameOver)
{
	UpdateMusicStream(menuMusic); 

	ClearBackground(BLACK);

	DrawText(TextFormat("Game Over"), screenWidth / 2 - 150, screenHeight / 2 - 100, 50, WHITE);

	DrawText(TextFormat("What Will You Do"), screenWidth / 2 - 200, screenHeight / 2 - 30, 50, WHITE);
	DrawText(TextFormat(" P1 Points %i", player.points), screenWidthMin + 200, screenHeight / 2 + 50, 30, ORANGE);
	if (!onePlayerGame)
	{
		DrawText(TextFormat(" P2 Points %i", player.points), screenWidth - 400, screenHeight / 2 + 50, 30, RED);
	}
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


