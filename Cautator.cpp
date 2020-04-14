#include "Cautator.h"

Cautator::Cautator(const int l, const int c) : poz(l, c) {}

Cautator::~Cautator() {
	delete this;
}