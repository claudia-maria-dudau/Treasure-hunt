#include "Comoara.h"
#include <stdlib.h>
#include <time.h>

unsigned Comoara::id = 0;

Comoara::Comoara(Harta& h) {
	//creare ID
	this->id++;					
	this->ID = "C" + to_string(id);
	
	//generare pozitie comoara
	int l, c;

	srand(time(NULL));
	do {
		l = rand() % h.nrLin + 1;
		c = rand() % h.nrCol + 1;
	} while (h.M[l][c] != '-');

	this->poz = new Pozitie(l, c);
	h.M[l][c] = 'X';
}

Comoara::~Comoara() {
	this->ID = "";
	delete this->poz;
	delete this;
}

void Comoara::gasitComoara(string idCaut, Harta& h) {			
	//in cazul in care un cautator a gasit o comoara afisez mesajul corepsunzator
	cout << "Comoara " << stoul(this->ID.substr(2)) << "a fost gasita de cautarorul " << stoul(idCaut.substr(0, 1)) <<endl;
	//h.M[(*poz).getLinie()][(*poz).getColoana()] = 'X';
}

Pozitie Comoara::getPoz() const {
	return *poz;
}