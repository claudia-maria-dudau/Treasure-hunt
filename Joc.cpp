#include "Joc.h"

int Joc::idRunda = 0;

Joc::Joc(const int dimLin, const int dimCol) {
	//creare harta
	h = new Harta(dimLin, dimCol);

	//creare cautatori - cand o sa ii am !!!!!!!

	//creare comori
	for (int i = 1; i <= 3; i++)
		this->comori.push_back(new Comoara(dimLin, dimCol));
}

Joc::~Joc() {
	this->idRunda = 0;

	//stergere vector cautatori
	this->cautatori.clear();

	//stergere vector comori
	this->comori.clear();

	//stergere harta
	delete h;
}

void Joc::runda() {
	
}


void Joc::afisare() {
	cout << (*h);
	cout << "Nr de cautatori ce se afla pe harta: " << this->cautatori.size() << endl;
	cout << "Nr de comori negasite: " << this->comori.size() << endl;
	cout << "Nr de casute neexplorate inca: " << (*h).getNrCasuteNeexplorate() << endl;
}