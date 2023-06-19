#pragma once
#include "Mover.h"
using namespace System::Drawing;

class Ball : public Mover
{

public:
	void draw(Graphics^ graphics);
	void interact(PopObject* object);
	explicit Ball(int frameWidth, int frameHeight) : Mover(frameWidth, frameHeight) {};

};

