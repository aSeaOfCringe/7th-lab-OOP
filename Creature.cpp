#include "Creature.h"

void Creature::move(PopObject* popObject) {
	Mover::move(popObject);
	if (this->_x + this->_dx < -40 || this->_x + this->_dx > this->_frameWidth - 40) {
		this->_dx = -this->_dx;
	}
	if (this->_y + this->_dy < 0 || this->_y + this->_dy > this->_frameHeight - 40)
		this->_dy = -this->_dy;

	this->_x += this->_dx;
	this->_y += this->_dy;
	setPos(this->_x, this->_y);
}