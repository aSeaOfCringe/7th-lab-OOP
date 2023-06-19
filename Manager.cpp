#include "Manager.h"
#include "Explosion.h"
#include <cstddef>
#include <math.h>
#include "Ball.h"
#include<iostream>
#include<cstdlib>
#include "Rect.h"
#include "Triangle.h"
#include "Star.h"
#include "Hunter.h"
#include "Bullet.h"
#include "Zombie.h"
using namespace System::Drawing;

Manager::Manager(int frameW, int frameH) {
	this->frameWidth_ = frameW;
	this->frameHeight_ = frameH;

	for (int i = 0; i < MAX_OBJECTS; i++) {
		this->popObjects_[i] = NULL;
	}
}

void Manager::drawFrame(Graphics^ graphics) {
	for (int i = 0; i < MAX_OBJECTS; i++) if (popObjects_[i]) {
		popObjects_[i]->draw(graphics);
	}
}

void Manager::move() {
	for (int i = 0; i < MAX_OBJECTS; i++) {
		bool zombieShot = false;
		if (popObjects_[i] && popObjects_[i]->getStepsCount() >= 100 && 
			typeid(*popObjects_[i]) == typeid(Explosion)) {
				remove(popObjects_[i]);
				continue;
		}
		if (popObjects_[i]) {
			for (int j = 0; j < MAX_OBJECTS; j++) {
				if (j != i && popObjects_[j] && popObjects_[i] && popObjects_[i]->checkInteraction(popObjects_[j])) {
					if (typeid(*popObjects_[i]) == typeid(Bullet) && typeid(*popObjects_[j]) == typeid(Zombie))
						zombieShot = true;
					popObjects_[i]->interact(popObjects_[j]);
					break;
				}
			}
			if (popObjects_[i]) {
				if (zombieShot) remove(popObjects_[i]);
				else {
					PopObject* popObject = nearest(popObjects_[i]);
					popObjects_[i]->move(popObject);
				}
			}
		}
	}
}

void Manager::add(PopObject* popObject) {
	for (int i = 0; i < MAX_OBJECTS; i++) if (!popObjects_[i]) {
		popObjects_[i] = popObject;
		break;
	}
}

void Manager::remove(PopObject* popObject) {
	for (int i = 0; i < MAX_OBJECTS; i++) if (popObjects_[i] == popObject) {
		popObjects_[i] = NULL;
		delete popObject;
		break;
	}
}

PopObject* Manager::search(int x, int y) {
	for (int i = 0; i < MAX_OBJECTS; i++) {
		if (popObjects_[i]) {
			float cx = popObjects_[i]->getX();
			float cy = popObjects_[i]->getY();
			float dist = sqrt(pow(x - cx, 2) + pow(y - cy, 2));
			if (dist <= popObjects_[i]->getSize() / 2) return popObjects_[i];
		}
	}
	return NULL;
}

int Manager::countOf(const type_info* type) {
	int count = 0;
	for (int i = 0; i < MAX_OBJECTS; i++) {
		if (popObjects_[i] && typeid(*popObjects_[i]) == *type)
			count++;
	}
	return count;
}

void Manager::place(PopObject* popObject) {
	int x = popObject->getX();
	int y = popObject->getY();
	for (int i = 0; i < MAX_OBJECTS; i++) {
		if (popObject && typeid(*popObject) == typeid(Explosion) && popObjects_[i] &&
			popObjects_[i]->getX() == x && popObjects_[i]->getY() == y) {
			remove(popObjects_[i]);
			popObjects_[i] = popObject;
			break;
		}
		else if (popObject && !popObjects_[i]) {
			bool owerlap = false;
			for (int j = 0; j < MAX_OBJECTS; j++) {
				if (popObjects_[j] && popObject->checkInteraction(popObjects_[j])) {
					owerlap = true;
					break;
				}
			}
			if (!owerlap) {
				popObjects_[i] = popObject;
			}
		}
	}
}

void Manager::destroyAll(int frameWidth, int frameHeight) {
	for (int i = 0; i < MAX_OBJECTS; i++) {
		if (popObjects_[i]) {
			delete popObjects_[i];
			popObjects_[i] = NULL;
		}
	}
}

PopObject* Manager::nearest(PopObject* popObject) {
	PopObject* nearest;
	int x = popObject->getX();
	int y = popObject->getY();
	int distance = INT_MAX;
	for (int i = 0; i < MAX_OBJECTS; i++) {
		if (popObjects_[i] && popObjects_[i] != popObject) {
			int dist = sqrt(pow(popObjects_[i]->getX() - x, 2) + pow(popObjects_[i]->getY() - y, 2));
			if (dist < distance) {
				nearest = popObjects_[i];
			}
		}
	}
	return nearest;
}

PopObject* Manager::findObject(const type_info* type) {
	for (int i = 0; i < MAX_OBJECTS; i++) {
		if (popObjects_[i] && typeid(*popObjects_[i]) == *type) {
			return popObjects_[i];
		}
	}
	return NULL;
}

void Manager::doCommand(int command) {
	for (int i = 0; i < MAX_OBJECTS; i++) {
		if (popObjects_[i])
		popObjects_[i]->doCommand(command);
	}
}

Manager::~Manager() {
	for (int i = 0; i < MAX_OBJECTS; i++) if (popObjects_[i]) {
		delete popObjects_[i];
	}
}
