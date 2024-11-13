#include "objects/obstacle.h"

Obstacle obstacle;

void initObstacle(Obstacle& o)
{
	o.position = { static_cast<float>(screenWidth),
				   static_cast<float>(screenHeightMin) };

	o.speed = { 200.0f, 0.0f };

	o.width = 30;

	o.gap = 100;

	o.topHeight = GetRandomValue(50, screenHeight - o.gap - 50);  
	o.bottomHeight = screenHeight - o.topHeight - o.gap;  
}

void loadObstacle()
{
}

void updateObstacle(Obstacle& o)
{
	if (o.position.x < static_cast<float>(screenWidthMin))
	{
		o.position.x = static_cast<float>(screenWidth);
		o.topHeight = GetRandomValue(50, screenHeight - o.gap - 50);
		o.bottomHeight = screenHeight - o.topHeight - o.gap;
	}

	o.position.x -= o.speed.x * GetFrameTime();
}

void drawObstacle(Obstacle& o)
{
	DrawRectangle(static_cast<int>(o.position.x), 0, o.width, o.topHeight, RED);

	DrawRectangle(static_cast<int>(o.position.x), static_cast<int>(o.topHeight + o.gap), o.width, o.bottomHeight, RED);
}

void unloadObstacle()
{
}
