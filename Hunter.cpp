#include "Hunter.h"
#include "Pictures.h"
#include "Manager.h"
extern Manager* manager;

void Hunter::interact(PopObject* object) {

}

void Hunter::draw(Graphics^ graphics) {
	switch (this->nr) {
	case 0: {
		graphics->DrawImage(Pictures::hunter1, this->_x, this->_y, 40.0, 40.0);
		break;
	}
	case 1: {
		graphics->DrawImage(Pictures::hunter2, this->_x, this->_y, 40.0, 40.0);
		break;
	}
	case 2: {
		graphics->DrawImage(Pictures::hunter3, this->_x, this->_y, 40.0, 40.0);
		break;
	}
	}
	
}

Hunter::Hunter(int frameWidth, int frameHeight) : Creature(frameWidth, frameHeight) {
	this->nr = rand() % 2;
	this->_size = 20;
	this->_dx = 0;
	this->_dy = 0;
}

void Hunter::doCommand(int command) {
	switch (command) {
	case 1: {
		this->_dy = -2;
		this->_dx = 0;
		break;
	}
	case 2: {
		this->_dy = 0;
		this->_dx = 0;
		break;
	}
	case 3: {
		this->_dy = 2;
		this->_dx = 0;
		break;
	}
	case 4: {
		this->_dy = 0;
		this->_dx = 0;
		break;
	}
	case 5: {
		this->_dx = 2;
		this->_dy = 0;
		break;
	}
	case 6: {
		this->_dx = 0;
		this->_dy = 0;
		break;
	}
	case 7: {
		this->_dx = -2;
		this->_dy = 0;
		break;
	}
	case 8: {
		this->_dx = 0;
		this->_dy = 0;
		break;
	}
	}
}
