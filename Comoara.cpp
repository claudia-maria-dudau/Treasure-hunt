#include "Comoara.h"
#include <random>

unsigned Comoara::id = 0;

Comoara::Comoara(const int dimLin, const int dimCol) {
	//creare ID
	id++;					
	this->ID = "C" + to_string(id);
	
	//generare pozitie comoara
	default_random_engine generator;
	uniform_int_distribution<int> distributie(1, dimLin - 1);
	int l = distributie(generator);
	uniform_int_distribution<int> distributie(1, dimCol - 1);
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