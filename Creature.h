#pragma once
#include "Mover.h"

class Creature : public Mover
{
public:
	void move(PopObject* popObject);
	explicit Creature(int frameWidth, int frameHeight) : Mover(frameWidth, frameHeight) {};
};

