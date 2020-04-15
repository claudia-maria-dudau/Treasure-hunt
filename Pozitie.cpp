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

bool Pozitie::operator ==(const Pozitie& p) {
	return (this->lin = p.lin && this->col == p.col);
}
