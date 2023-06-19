#pragma once
#include "Rotator.h"

class Weapon : public Rotator
{
protected:
	float alpha_;
	float dAlpha_;
	float pointingX;
	float pointingY;
public:
	void move(PopObject* popObject);
	void draw(Graphics^ graphics);
	void interact(PopObject* object);
	void setDirection(float x, float y);
	Weapon(int frameWidth, int frameHeight, float x, float y);
};

