#pragma once
#include <typeinfo>
using namespace System::Drawing;
#define cmdStartUp 1
#define cmdStopUp 2
#define cmdStartDown 3
#define cmdStopDown 4
#define cmdStartRight 5
#define cmdStopRight 6
#define cmdStartLeft 7
#define cmdStopLeft 8

class PopObject
{
public:
	virtual void setPos(int x, int y) = 0;
	virtual float getX() = 0;
	virtual float getY() = 0;
	virtual float getdX() = 0;
	virtual float getdY() = 0;
	virtual void setdX(float dx) = 0;
	virtual void setdY(float dy) = 0;
	virtual void setX(float x) = 0;
	virtual void setY(float y) = 0;
	virtual int getSize() = 0;
	virtual void setDirection(float x, float y) = 0;
	virtual void draw(Graphics^ graphics) = 0;
	virtual void move(PopObject* popObject) = 0;
	virtual bool checkInteraction(PopObject* popObject) = 0;
	virtual void interact(PopObject* object) = 0;
	virtual void followTo(float x, float y) = 0;
	virtual void followAway(int x, int y) = 0;
	virtual bool interactable(PopObject* popObject) = 0;
	virtual int getStepsCount() = 0;
	virtual void doCommand(int command) = 0;
	//PopObject();
};
