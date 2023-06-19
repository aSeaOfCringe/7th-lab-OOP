#include "Star.h"
#include "Explosion.h"
#include "Manager.h"
#include "Bullet.h"
#define _USE_MATH_DEFINES
#include <cmath>
#define M_PI 3.14
extern Manager* manager;

void Star::draw(Graphics^ graphics) {
	SolidBrush brush(Color::FromArgb(this->_color));
	array<Point>^ points = gcnew array<Point>(10);
	for (int i = 0; i < 10; i++) {
		int r = _size / 2;
		if (i % 2 == 1) r = _size / 6;
		points[i] = Point(
			_x + r * cos(alpha_ + 2 * M_PI / 10 * i),
			_y + r * sin(alpha_ + 2 * M_PI / 10 * i)
		);
	}
	graphics->FillPolygon(% brush, points);
}

void Star::interact(PopObject* object) {
	if (typeid(*object) == typeid(Bullet)) manager->remove(object);
}

