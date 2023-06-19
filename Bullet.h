#pragma once
#include "Mover.h"
#define M_PI 3.14

class Bullet : public Mover
{
public:
	void interact(PopObject* object);
	void draw(Graphics^ graphics);
	explicit Bullet(int frameWidth, int frameHeight, float x1, float y1, float x2, float y2);

};

