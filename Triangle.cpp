#include "Triangle.h"
#include "Explosion.h"
#include "Manager.h"
#include "Bullet.h"
#define _USE_MATH_DEFINES
#include <cmath>
#define M_PI 3.14
extern Manager* manager;

void Triangle::draw(Graphics^ graphics) {
	SolidBrush brush(Color::FromArgb(this->_color));
	array<Point>^ points = gcnew array<Point>(3);
	for (int i = 0; i < 3; i++) {
		points[i] = Point(
			_x + _size / 2 * cos(alpha_ + 2 * M_PI / 3 * i),
			_y + _size / 2 * sin(alpha_ + 2 * M_PI / 3 * i)
		);
	}
	graphics->FillPolygon(% brush, points);
}

void Triangle::interact(PopObject* object) {
	if (typeid(*object) == typeid(Bullet)) manager->remove(object);
}
