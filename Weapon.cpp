#include "Weapon.h"
#include "Manager.h"
#include "Hunter.h"
#define M_PI 3.14
extern Manager* manager;

void Weapon::move(PopObject* popObject) {
	Mover::move(popObject);
	this->_x = manager->findObject(&typeid(Hunter))->getX() + 20;
	this->_y = manager->findObject(&typeid(Hunter))->getY() + 15;
	this->alpha_ = atan2(this->pointingY - this->_y, this->pointingX - this->_x);
}

void Weapon::draw(Graphics^ graphics) {
	SolidBrush brush(Color::Black);
	array<Point>^ points = gcnew array<Point>{
			Point((_x + cos(alpha_)), (_y + sin(alpha_))),
			Point((_x + 40 * cos(alpha_)), (_y + 40 * sin(alpha_))),
			Point((_x + 40 * cos(alpha_ + 2 * M_PI / 60)), (_y + 40 * sin(alpha_ + 2 * M_PI / 60))),
			Point((_x + cos(alpha_ + 2 * M_PI / 60)), (_y + sin(alpha_ + 2 * M_PI / 60))),
			
	};
	
	graphics->FillPolygon(% brush, points);
}

void Weapon::setDirection(float x, float y) {
	this->pointingX = x;
	this->pointingY = y;
}

void Weapon::interact(PopObject* object) { }

Weapon::Weapon(int frameWidth, int frameHeight, float x, float y) : Rotator(frameWidth, frameHeight) {
	this->alpha_ = 0;
	this->_x = x + 20;
	this->_y = y + 15;
	this->_x = x;
	this->_y = y;
}