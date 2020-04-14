#include "Pozitie.h"

Pozitie::Pozitie(int l, int c): lin(l), col(c) {}

bool Pozitie::operator ==(const Pozitie& p) {
	return (this->lin = p.lin && this->col == p.col);
}
