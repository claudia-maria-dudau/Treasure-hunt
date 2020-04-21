#include "Cautator.h"

unsigned Cautator::id = 0;

Cautator::Cautator() {
	this->id++;
	this->ID = to_string(id) + "-";
	this->stadiu = "In cautare";
}

Cautator::~Cautator() {
	this->arieVizibilitate = 0;
	this->id = 0;
	this->ID = this->stadiu = this->nume = "";
	delete this->poz;
}

string Cautator::getID() const {
	return this->ID;
}

Pozitie Cautator::getPoz() const{
	return *poz;
}

void Cautator::setStadiu(const string s) {
	this->stadiu = s;
}

string Cautator::getStadiu() const {
	return this->stadiu;
}

string Cautator::getNume() const {
	return this->nume;
}