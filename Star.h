#pragma once
#include"Rotator.h"

class Star : public Rotator
{
public:
	void draw(Graphics^ graphics);
	void interact(PopObject* object);
	Star(int frameWidth, int frameHeight) : Rotator(frameWidth, frameHeight) {};
};


