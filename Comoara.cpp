#include "Comoara.h"
#include <random>

unsigned Comoara::id = 0;

Comoara::Comoara(int dim) {
	//creare ID
	id++;					
	this->ID = "C" + to_string(id);
	
	//generare pozitie comoara
	default_random_engine generator;
	uniform_int_distribution<int> distributie(1, dim - 1);
	int l = distributie(generator);
	int c = distributie(generator);
	this->poz.setPozitie(l, c);
}

Comoara::~Comoara() {
	delete this;
}

void Comoara::gasitComoara(string idCaut, Harta& h) {			
	//in cazul in care un cautator a gasit o comoara afisez mesajul corepsunzator
	cout << "Comoara " << stoul(this->ID.substr(2)) << "a fost gasita de cautarorul " << stoul(idCaut.substr(4)) <<endl;
	h.M[this->poz.getLinie()][this->poz.getColoana()] = 'X';
}