#pragma once

#include "scene/menuScene.h"

extern Music gamePlayMusic;
extern Sound impactSound;
extern Sound impactGround;
extern Sound gameOverSound;


namespace gamePlay
{
	static Texture2D background;
	static Texture2D waterReflection;
	static Texture2D clouds;
	static Texture2D moon;

	static float scrollingBack = 0.0f;
	static float scrollingMidBack = 0.0f;
	static float scrollingMid = 0.0f;
	static float scrollingFront = 0.0f;

	void initGameplay();

	void loadGameplay();

	void updateGameplay(bool& menuOn, bool& gameOver);

	void checkCollision(Player& actualPlayer);

	void drawGameplay(bool& menuOn, bool& pauseOn);

	void initBackground();

	void updateBackground();

	void drawParalaxBackgournd();

	void unloadGameplay();
}

