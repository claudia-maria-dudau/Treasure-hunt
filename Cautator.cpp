#include "Cautator.h"

unsigned Cautator::id = 0;

Cautator::Cautator() {
	id++;
	this->ID = to_string(id) + "-";
}

Cautator::~Cautator() {
	delete this;
}

string Cautator::getID() {
	return this->ID;
}