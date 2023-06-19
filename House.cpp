#include "House.h"
#include "Pictures.h"
#include "Bullet.h"
#include "manager.h"
extern Manager* manager;

void House::draw(Graphics^ graphics) {
	switch (nr) {
	case 0: {
		graphics->DrawImage(Pictures::building1, this->_x, this->_y, 40.0, 40.0);
		break;
	}
	case 1: {
		graphics->DrawImage(Pictures::building2, this->_x, this->_y, 40.0, 40.0);
		break;
	}
	case 2: {
		graphics->DrawImage(Pictures::building3, this->_x, this->_y, 40.0, 40.0);
		break;
	}
	}
	
}

void House::move(PopObject* popObject) {

}

void House::interact(PopObject* object) {
	if (object && typeid(*object) == typeid(Bullet)) manager->remove(object);
}

House::House(int frameWidth, int frameHeight) : Mover(frameWidth, frameHeight) {
	this->nr = rand() % 3;
	this->stepsCount = 0;
	this->_size = 40;
	this->_x = rand() % (frameWidth - this->_size * 2) + this->_size;
	this->_y = rand() % (frameHeight - this->_size * 2) + this->_size;
	this->_frameWidth = frameWidth;
	this->_frameHeight = frameHeight;
	this->_dx = 0;
	this->_dy = 0;
}

