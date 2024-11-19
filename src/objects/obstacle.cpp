#include "objects/obstacle.h"

Obstacle obstacle[maxObstacles];
float timer = 0.0f;
float resetTimer = 3.0f;

void initObstacle(Obstacle obst[])
{
	for (int i = 0; i < maxObstacles; i++)
	{
		obst[i].position = { static_cast<float>(screenWidth + 100),
					   static_cast<float>(screenHeightMin) };

		obst[i].isActive = false;
		obst[i].speed = { 200.0f, 0.0f };

		obst[i].width = 30;

		obst[i].gap = 100;

		obst[i].topHeight = GetRandomValue(50, screenHeight - obst[i].gap - 50);
		obst[i].bottomHeight = screenHeight - obst[i].topHeight - obst[i].gap;
	}
}

void loadObstacle()
{
}

void updateObstacle(Obstacle obst[])
{
	timer -= (GetFrameTime() < timer) ? GetFrameTime() : timer;

	if (timer <= 0)
	{
		for (int i = 0; i < maxObstacles; i++)
		{
			if (!obst[i].isActive)
			{
				obst[i].isActive = true;
				timer = resetTimer;
				break;
			}
		}
	}

	for (int i = 0; i < maxObstacles; i++)
	{

		if (obst[i].isActive)
		{
			if (obst[i].position.x < static_cast<float>(screenWidthMin))
			{
				obst[i].position.x = static_cast<float>(screenWidth);
				obst[i].topHeight = GetRandomValue(50, screenHeight - obst[i].gap - 50);
				obst[i].bottomHeight = screenHeight - obst[i].topHeight - obst[i].gap;
				obst[i].isActive = false;
			}

			obst[i].position.x -= obst[i].speed.x * GetFrameTime();
		}
	}
}

void drawObstacle(Obstacle obst[])
{
	for (int i = 0; i < maxObstacles; i++)
	{
		DrawRectangle(static_cast<int>(obst[i].position.x), 0, obst[i].width, obst[i].topHeight, RED);

		DrawRectangle(static_cast<int>(obst[i].position.x), static_cast<int>(obst[i].topHeight + obst[i].gap), obst[i].width, obst[i].bottomHeight, RED);
	}
}

void unloadObstacle()
{
}
