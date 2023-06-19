#pragma once
#include "Rotator.h"
using namespace System::Drawing;

class Rect : public Rotator
{
public:
	void draw(Graphics^ graphics);
	void interact(PopObject* object);
	Rect(int frameWidth, int frameHeight) : Rotator(frameWidth, frameHeight) {};
};


