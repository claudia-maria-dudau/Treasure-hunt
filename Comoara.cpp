#include "Comoara.h"

Comoara::Comoara(const int l, const int c) : poz(l, c) {}

Comoara::~Comoara() {
	delete this;
}