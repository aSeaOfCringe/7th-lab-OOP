#pragma once
#include "Mover.h"
#include "ExplosionFigure.h"
#include <typeinfo>
using namespace System::Drawing;
#define EXPL_FIG_COUNT 30


class Explosion : public Mover
{
protected:
	ExplosionFigure* explosionFigures[EXPL_FIG_COUNT];
public:
	void draw(Graphics^ graphics);
	void move(PopObject* popObject);
	bool interactable(PopObject* popObject);
	explicit Explosion(int frameWidth, int frameHeight, int x, int y);
};
