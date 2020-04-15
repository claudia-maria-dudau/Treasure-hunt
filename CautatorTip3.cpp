#include "CautatorTip3.h"

unsigned CautatorTip3::id = 0;

CautatorTip3::CautatorTip3(Harta& h) {
	this->id++;
	this->ID = this->ID + "C3" + to_string(id);
	this->poz = new Pozitie(h.nrLin - 1, 0);
	arieVizibilitate = 2;
	h.M[h.nrLin - 1][0] = 'C';
}

void CautatorTip3::mutare() {
	//???MISTER???
}