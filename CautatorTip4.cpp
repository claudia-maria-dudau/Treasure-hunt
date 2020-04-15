#include "CautatorTip4.h"

unsigned CautatorTip4::id = 0;

CautatorTip4::CautatorTip4(Harta& h) {
	this->id++;
	this->ID = this->ID + "C4" + to_string(id);
	this->poz = new Pozitie(h.nrLin - 1, h.nrCol - 1);
	arieVizibilitate = 3;
	h.M[h.nrLin - 1][h.nrCol -  1] = 'C';
}

void CautatorTip4::mutare() {
	//???MISTER???
}