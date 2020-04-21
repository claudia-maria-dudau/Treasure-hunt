#include "Comoara.h"
#include <stdlib.h>
#include <time.h>

unsigned Comoara::id = 0;

Comoara::Comoara(Harta& h) {
	//creare ID
	this->id++;					
	this->ID = to_string(id) + '-';
	
	//generare pozitie comoara
	int l, c;
	srand(time(NULL));
	do {
		l = rand() % (h.nrLin - 1) + 1;
		c = rand() % (h.nrCol - 1) + 1;
	} while (h.M[l][c] != '-');
	this->poz = new Pozitie(l, c);
	h.M[l][c] = 'X';
}

Comoara::~Comoara() {
	this->id = 0;
	this->ID = "";
	delete this->poz;
	this->compatibil.clear();
}

Pozitie Comoara::getPoz() const {
	return *poz;
}

set<string> Comoara::getCompatibil() const {
	return this->compatibil;
}

void Comoara::repozitionare(Harta& h) {
	//stergere pozitie veche
	delete this->poz;

	//generare pozitie noua
	int l, c;
	srand(time(NULL));
	do {
		l = rand() % (h.nrLin - 1) + 1;
		c = rand() % (h.nrCol - 1) + 1;
	} while (h.M[l][c] != '-');
	this->poz = new Pozitie(l, c);
	h.M[l][c] = 'X';

	cout << "Comoara " + this->ID.substr(0, 1) + " a fost repozitionata" << endl;
}