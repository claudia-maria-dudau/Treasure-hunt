#include "Comoara.h"
#include <random>

unsigned Comoara::id = 0;

Comoara::Comoara(Harta& h) {
	//creare ID
	this->id++;					
	this->ID = "C" + to_string(id);
	
	//generare pozitie comoara
	default_random_engine generator;
	uniform_int_distribution<int> distributie(1, h.nrLin - 2);
	int l = distributie(generator);
	uniform_int_distribution<int> distributie(1, h.nrCol - 2);
	int c = distributie(generator);
	this->poz = new Pozitie(l, c);
}

Comoara::~Comoara() {
	this->ID = "";
	delete this->poz;
	delete this;
}

void Comoara::gasitComoara(string idCaut, Harta& h) {			
	//in cazul in care un cautator a gasit o comoara afisez mesajul corepsunzator
	cout << "Comoara " << stoul(this->ID.substr(2)) << "a fost gasita de cautarorul " << stoul(idCaut.substr(0, 1)) <<endl;
	h.M[(*poz).getLinie()][(*poz).getColoana()] = 'X';
}

Pozitie Comoara::getPoz() const {
	return *poz;
}