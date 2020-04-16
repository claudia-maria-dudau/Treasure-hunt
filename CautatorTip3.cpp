#include "CautatorTip3.h"

CautatorTip3::CautatorTip3(Harta& h) {
	this->ID += "C3";
	this->poz = new Pozitie(h.nrLin - 1, 0);
	arieVizibilitate = 2;
	h.M[h.nrLin - 1][0] = 'C';
}

void CautatorTip3::mutare(Harta&) {
	//???MISTER???
}