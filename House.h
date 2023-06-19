#pragma once
#include "Mover.h"

class House : public Mover
{
private:
	int nr=1;
public:
	void draw(Graphics^ graphics);
	void move(PopObject* popObject);
	void interact(PopObject* object);
	explicit House(int frameWidth, int frameHeight);
};

