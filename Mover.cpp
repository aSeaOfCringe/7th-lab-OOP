#include "Mover.h"
#include<iostream>
#include<cstdlib>
#include <math.h>
#include <typeinfo>
#include "Explosion.h"
#include "Hunter.h"
#include "Zombie.h"
#include "House.h"
#include "Manager.h"
using namespace std;
using namespace System;
extern Manager* manager;

Mover::Mover(int frameWidth, int frameHeight) : PopObject() {
	this->stepsCount = 0;
	this->_size = 8;
	do {
		this->_x = rand() % (frameWidth - 80) + 40;
		this->_y = rand() % (frameHeight - 80) + 40;
	} while (manager->search(this->_x, this->_y));
	
	this->_frameWidth = frameWidth;
	this->_frameHeight = frameHeight;
	Color color = Color::FromArgb(rand() % 256, rand() % 256, rand() % 256);
	this->_color = color.ToArgb();
	int dx = rand() % 2 - 5, dy = rand() % 2 - 5;
	while (dx == 0 && dy == 0) {
		dx = rand() % 2 - 5, dy = rand() % 2 - 5;
	}
	this->_dx = dx;
	this->_dy = dy;
}

void Mover::setPos(int x, int y) {
	if (x < this->_size / 2) this->_x = this->_size / 2;
	else if (x > this->_frameWidth - this->_size / 2)
		this->_x = this->_frameWidth - this->_size / 2;
	else this->_x = x;

	if (y < this->_size / 2) this->_y = this->_size / 2;
	else if (y > this->_frameHeight - this->_size / 2)
		this->_y = this->_frameHeight - this->_size / 2;
	else this->_y = y;

}

float Mover::getX() {
	return this->_x;
}

float Mover::getY() {
	return this->_y;
}

float Mover::getdX() {
	return this->_dx;
}

float Mover::getdY() {
	return this->_dy;
}

void Mover::setdX(float dx) {
	this->_dx = dx;
}
void Mover::setdY(float dy) {
	this->_dy = dy;
}

void Mover::setX(float x) {
	this->_x = x;
}
void Mover::setY(float y) {
	this->_y = y;
}

int Mover::getSize() {
	return this->_size;
}

int Mover::getStepsCount() {
	return this->stepsCount;
}

void Mover::setDirection(float x, float y) {}

void Mover::move(PopObject* popObject) {
	if (stepsCount >= 100 && popObject && (typeid(*popObject) == typeid(Hunter) ||
		typeid(*popObject) == typeid(Zombie))) {
		stepsCount = 0;
		followTo(popObject->getX(), popObject->getY());
	}
	if (this->_x + this->_dx < this->_size / 2 ||
		this->_x + this->_dx > this->_frameWidth - this->_size / 2)
		this->_dx = -this->_dx;
	if (this->_y + this->_dy < this->_size / 2 ||
		this->_y + this->_dy > this->_frameHeight - this->_size / 2)
		this->_dy = -this->_dy;
	this->_x += this->_dx;
	this->_y += this->_dy;
	setPos(this->_x, this->_y);
	this->stepsCount++;
}

void Mover::followTo(float x, float y) {
	float speed = sqrt(pow(this->_dx, 2) + pow(this->_dy, 2));
	float angle = atan2(y - this->_y, x - this->_x);
	this->_dx = speed * cos(angle);
	this->_dy = speed * sin(angle);
}

void Mover::followAway(int x, int y) {
	float speed = sqrt(pow(this->_dx, 2) + pow(this->_dy, 2));
	float angle = atan2(y - this->_y, x - this->_x);
	this->_dx = -speed * cos(angle);
	this->_dy = -speed * sin(angle);
}

bool Mover::checkInteraction(PopObject* popObject) {
	if (!popObject || !interactable(popObject)) return false;
	float dist = sqrt(pow(this->_x - popObject->getX(), 2) + pow(this->_y - popObject->getY(), 2));
	float radiuses = sqrt(pow((this->_size + popObject->getSize()) / 2, 2));
	if (dist <= radiuses && popObject->interactable(this)) {
		return true;
	}
	else return false;
}

void Mover::interact(PopObject* object) {
	if (!interactable(object)) return;
	setPos(this->_x - this->_dx, this->_y - this->_dy);
	this->_dx = -this->_dx;
	this->_dy = -this->_dy;
}

bool Mover::interactable(PopObject* popObject) {
	return true;
}

void Mover::doCommand(int command) {}

