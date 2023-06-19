#pragma once
using namespace System::Drawing;
#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>
#include<ctime>
#define M_PI 3.14

class ExplosionFigure
{
private:
	float _x, _y;
	float _dx, _dy;
public:
	void move();
	void draw(Graphics^ graphics);
	ExplosionFigure(int x, int y);
};