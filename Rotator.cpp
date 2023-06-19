#include "Rotator.h"

void Rotator::move(PopObject* popObject) {
	Mover::move(popObject);
	this->alpha_ = this->alpha_ + this->dAlpha_;

	Rotator::wallInteraction();
}

void Rotator::wallInteraction() {
	if (this->_x + this->_dx < this->_size / 2 ||
		this->_x + this->_dx > this->_frameWidth - this->_size / 2 ||
		this->_y + this->_dy < this->_size / 2 ||
		this->_y + this->_dy > this->_frameHeight - this->_size / 2)

		this->dAlpha_ = -this->dAlpha_;
}

Rotator::Rotator(int frameWidth, int frameHeight) : Mover(frameWidth, frameHeight) {
	this->alpha_ = 0;
	this->dAlpha_ = 0.1;
}
