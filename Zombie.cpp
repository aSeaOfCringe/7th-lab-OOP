#include "Zombie.h"
#include "House.h"
#include "hunter.h"
#include "Bullet.h"
#include "manager.h"
#include "Pictures.h"
#include "Ball.h"
#include "Rect.h"
#include "Star.h"
#include "Triangle.h"
#include "Explosion.h"
#include "Dead.h"
#include "Weapon.h"
extern Manager* manager;

void Zombie::interact(PopObject* object) {
	Creature::interact(object);
	if (typeid(*object) == typeid(Hunter)) {
		PopObject* weapon = manager->findObject(&typeid(Weapon));
		manager->remove(weapon);
		float x = object->getX();
		float y = object->getY();
		manager->add(new Explosion(this->_frameWidth, this->_frameHeight, x, y));
		manager->remove(object);
		manager->add(new Dead(this->_frameWidth, this->_frameHeight, x, y));
	}
}

bool Zombie::interactable(PopObject* popObject) {
	if (typeid(*popObject) == typeid(Ball) || typeid(*popObject) == typeid(Rect) ||
		typeid(*popObject) == typeid(Star) || typeid(*popObject) == typeid(Triangle)
		|| typeid(*popObject) == typeid(Zombie))
		return false;
}

void Zombie::draw(Graphics^ graphics) {
	switch (this->nr) {
	case 0: {
		graphics->DrawImage(Pictures::zombie1, this->_x, this->_y, 40.0, 40.0);
		break;
	}
	case 1: {
		graphics->DrawImage(Pictures::zombie2, this->_x, this->_y, 40.0, 40.0);
		break;
	}
	case 2: {
		graphics->DrawImage(Pictures::zombie3, this->_x, this->_y, 40.0, 40.0);
		break;
	}
	case 3: {
		graphics->DrawImage(Pictures::zombie4, this->_x, this->_y, 40.0, 40.0);
		break;
	}
	case 4: {
		graphics->DrawImage(Pictures::zombie5, this->_x, this->_y, 40.0, 40.0);
		break;
	}
	}
}

void Zombie::move(PopObject* popObject) {
	Creature::move(popObject);
	if (this->stepsCount >= 100 && manager->findObject(&typeid(Hunter)) > 0) {
		PopObject* obj = manager->findObject(&typeid(Hunter));
		followTo(obj->getX(), obj->getY());
	}
}

void Zombie::setPos(int x, int y) {
	if (x < -10) this->_x = -10;
	else if (x > this->_frameWidth - 10)
		this->_x = this->_frameWidth - 10;
	else this->_x = x;

	if (y < 0) this->_y = 0;
	else if (y > this->_frameHeight - 40)
		this->_y = this->_frameHeight - 40;
	else this->_y = y;
}

Zombie::Zombie(int frameWidth, int frameHeight) : Creature(frameWidth, frameHeight) {
	this->nr = rand() % 5;
	this->stepsCount = 0;
	this->_size = 40;
	this->_x = rand() % (frameWidth - this->_size * 2) + this->_size;
	this->_y = rand() % (frameHeight - this->_size * 2) + this->_size;
	this->_frameWidth = frameWidth;
	this->_frameHeight = frameHeight;
	int dx = (rand() % 100 - 200) * 0.01, dy = (rand() % 100 - 200) * 0.01;
	while (dx == 0 && dy == 0) {
		dx = (rand() % 100 - 200) * 0.01, dy = (rand() % 100 - 200) * 0.01;
	}
	this->_dx = dx;
	this->_dy = dy;
}