#pragma once
#include "Creature.h"

class Hunter : public Creature
{
private: int nr;
public:
	void interact(PopObject* object);
	void draw(Graphics^ graphics);
	void doCommand(int command);
	explicit Hunter(int frameWidth, int frameHeight);

};

