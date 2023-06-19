#pragma once
#define MAX_OBJECTS 1000
#include "PopObject.h"
//#include "Ball.h"

class Manager
{
private:
	PopObject* popObjects_[MAX_OBJECTS];
	int frameWidth_;
	int frameHeight_;
public:
	void drawFrame(Graphics^ graphics);
	void move();
	void add(PopObject* popObject);
	void remove(PopObject* popObject);
	int countOf(const type_info* type);
	void place(PopObject* popObject);
	void destroyAll(int frameWidth, int frameHeight);
	void doCommand(int command);
	PopObject* search(int x, int y);
	PopObject* nearest(PopObject* popObject);
	PopObject* findObject(const type_info* type);
	Manager(int frameW, int frameH);
	~Manager();
};

extern Manager* manger;
