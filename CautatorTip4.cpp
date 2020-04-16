#include "CautatorTip4.h"

CautatorTip4::CautatorTip4(Harta& h) {
	this->id++;
	this->ID += "C4";
	this->poz = new Pozitie(h.nrLin - 1, h.nrCol - 1);
	arieVizibilitate = 3;
	h.M[h.nrLin - 1][h.nrCol -  1] = 'C';
}

void CautatorTip4::mutare() {
	//???MISTER???
}