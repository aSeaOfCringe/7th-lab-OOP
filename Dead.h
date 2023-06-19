#pragma once
#include "Mover.h"

class Dead : public Mover
{
public:
	void draw(Graphics^ graphics);
	void move(PopObject* popObject);
	void interact(PopObject* object);
	explicit Dead(int frameWidth, int frameHeight, int x, int y);
};

