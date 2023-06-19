#pragma once
#include "Mover.h"

class Rotator : public Mover
{
protected:
	float alpha_;
	float dAlpha_;
public:
	void move(PopObject* popObject);
	void wallInteraction();
	Rotator(int frameWidth, int frameHeight);
};


