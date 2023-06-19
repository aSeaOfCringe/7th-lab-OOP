#pragma once
#include "Creature.h"

class Zombie : public Creature
{
private:
	int nr = 1;
public:
	void interact(PopObject* object);
	void draw(Graphics^ graphics);
	void move(PopObject* popObject);
	void setPos(int x, int y);
	bool interactable(PopObject* popObject);
	explicit Zombie(int frameWidth, int frameHeight);
};

