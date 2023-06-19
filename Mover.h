#pragma once
#include "PopObject.h"
#include<typeinfo>

class Mover : public PopObject
{
protected:
	float _x, _y;
	float _dx, _dy;
	int _size;
	int _color;
	int _frameWidth;
	int _frameHeight;
	int stepsCount;
public:
	void setPos(int x, int y);
	float getX();
	float getY();
	float getdX();
	float getdY();
	void setdX(float dx);
	void setdY(float dy);
	void setX(float x);
	void setY(float y);
	int getSize();
	void move(PopObject* popObject);
	void followTo(float x, float y);
	void followAway(int x, int y);
	void interact(PopObject* object);
	bool checkInteraction(PopObject* popObject);
	bool interactable(PopObject* popObject);
	int getStepsCount();
	void setDirection(float x, float y);
	void doCommand(int command);
	explicit Mover(int frameWidth, int frameHeight);
};
