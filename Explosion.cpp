#include "Explosion.h"
#include <typeinfo>

Explosion::Explosion(int frameWidth, int frameHeight, int x, int y) : Mover(frameWidth, frameHeight) {
	this->_x = x;
	this->_y = y;
	for (int i = 0; i < EXPL_FIG_COUNT; i++) {
		explosionFigures[i] = new ExplosionFigure(this->getX(), this->getY());
	}
}

void Explosion::draw(Graphics^ graphics) {
	for (int i = 0; i < EXPL_FIG_COUNT; i++) {
		if (explosionFigures[i]) explosionFigures[i]->draw(graphics);
	}
}

void Explosion::move(PopObject* popObject) {
	for (int i = 0; i < EXPL_FIG_COUNT; i++) {
		if (explosionFigures[i]) explosionFigures[i]->move();
	}
}

bool Explosion::interactable(PopObject* popObject) {
	return false;
}