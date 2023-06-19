#include "ExplosionFigure.h"
#include "ExplosionFigure.h"


void ExplosionFigure::move() {
	this->_x += this->_dx;
	this->_y += this->_dy;
}

void ExplosionFigure::draw(Graphics^ graphics) {
	SolidBrush brush(Color::FromArgb(rand() % 256, rand() % 256, rand() % 256));
	array<Point>^ points = gcnew array<Point>(12);
	for (int i = 0; i < 12; i++) {
		int r = 4;
		if (i % 2 == 1) r = 2;
		points[i] = Point(
			this->_x + r * cos(M_PI / 6 * i),
			this->_y + r * sin(M_PI / 6 * i)
		);
	}
	graphics->FillPolygon(% brush, points);
}

ExplosionFigure::ExplosionFigure(int x, int y) {
	this->_x = x + (rand() % 40 - 20);
	this->_y = y + (rand() % 40 - 20);
	do {
		this->_dx = rand() % 10 - 5;
		this->_dy = rand() % 10 - 5;
	} while (this->_dx == 0 && this->_dy == 0);
}
