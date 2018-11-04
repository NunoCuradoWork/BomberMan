#pragma once
#include "ECS.h"

class PositionComponent : public Component
{
private:
	int xpos;
	int ypos;

public:

	int getXposition() const { return xpos; }
	int getYposition() const { return ypos; }

	void setPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}

	void init() override
	{
		xpos = 0;
		ypos = 0;
	}

	void update() override
	{
		xpos++;
		ypos++;
	}
};