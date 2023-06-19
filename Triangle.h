#pragma once
#include "Rotator.h"
using namespace System::Drawing;

class Triangle : public Rotator
{
public:
	void draw(Graphics^ graphics);
	void interact(PopObject* object);
	Triangle(int frameWidth, int frameHeight) : Rotator(frameWidth, frameHeight) {};
};
