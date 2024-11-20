#pragma once

#include "scene/gameplayScene.h"

namespace gameLoop
{
	void run();
	static void Initialization();
	static void update();
	static void draw();
	static void unloadGame();
	static void close();
}