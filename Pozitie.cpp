#include "Pozitie.h"

Pozitie::Pozitie(int l, int c): lin(l), col(c) {}

void Pozitie::setPozitie(int l, int c) {
	this->lin = l;
	this->col = c;
}

int Pozitie::getLinie() const {
	return this->lin;
}

int Pozitie::getColoana() const {
	return this->col;
}

Pozitie Pozitie::operator = (const Pozitie& p) {
	this->lin = p.lin;
	this->col = p.col;
	return *this;
}

bool operator ==(const Pozitie& p1, const Pozitie& p2) {
	return (p1.getLinie() == p2.getLinie() && p1.getColoana() == p2.getColoana());
}

bool operator !=(const Pozitie& p1, const Pozitie& p2) {
	return !(p1.getLinie() == p2.getLinie() && p1.getColoana() == p2.getColoana());
}
