#include "Dead.h"
#include "Pictures.h"

void Dead::draw(Graphics^ graphics) {
	graphics->DrawImage(Pictures::rip, this->_x, this->_y, 20.0, 20.0);
}

void Dead::move(PopObject* popObject) {}

void Dead::interact(PopObject* object) {}
Dead::Dead(int frameWidth, int frameHeight, int x, int y) : Mover(frameWidth, frameHeight) {
	this->_x = x;
	this->_y = y;
	this->_dx = 0;
	this->_dy = 0;
	this->stepsCount = 0;
	this->_frameWidth = frameWidth;
	this->_frameHeight = frameHeight;
	this->_size = 10;
}