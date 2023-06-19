#include "Bullet.h"
#include "Zombie.h"
#include "Manager.h"
#include "Explosion.h"
#include "Dead.h"
extern Manager* manager;

void Bullet::interact(PopObject* object) {
	if (typeid(*object) == typeid(Zombie)) {
		float x = object->getX();
		float y = object->getY();
		manager->remove(object);
		manager->add(new Explosion(this->_frameWidth, this->_frameHeight, x, y));
	}
}

void Bullet::draw(Graphics^ graphics) {
	SolidBrush brush(Color::FromArgb(rand() % 256, rand() % 256, rand() % 256));
	array<Point>^ points = gcnew array<Point>(12);
	for (int i = 0; i < 12; i++) {
		int r = 15;
		if (i % 2 == 1) r = 2;
		points[i] = Point(
			this->_x + r * cos(M_PI / 6 * i),
			this->_y + r * sin(M_PI / 6 * i)
		);
	}
	graphics->FillPolygon(% brush, points);
}

Bullet::Bullet(int frameWidth, int frameHeight, float x1, float y1, float x2, float y2) : Mover(frameWidth, frameHeight) {
	this->_size = 1;
	float d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	this->_x = x1 + (40 / d) * (x2 - x1);
	this->_y = y1 + (40 / d) * (y2 - y1);
	this->_frameWidth = frameWidth;
	this->_frameHeight = frameHeight;
	this->_dx = 10;
	this->_dy = 10;
	followTo(x2, y2);
}
