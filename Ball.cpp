#include "Ball.h"
#include "Mover.h"
#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include "Manager.h"
#include "Explosion.h"
#include "Bullet.h"
extern Manager* manager;
using namespace System::Drawing;

void Ball::draw(Graphics^ graphics) {
	SolidBrush brush(Color::FromArgb(this->_color));
	graphics->FillEllipse(% brush, (int)(this->_x - (this->_size / 2)),
		(int)(this->_y - (this->_size / 2)), (int)(this->_size), (int)(this->_size));
}

void Ball::interact(PopObject* object) {
	if (typeid(*object) == typeid(Bullet)) manager->remove(object);
}
