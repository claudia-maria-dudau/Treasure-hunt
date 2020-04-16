#include "CautatorTip3.h"

CautatorTip3::CautatorTip3(Harta& h) {
	this->ID += "BB";
	this->nume = "Bilbo Baggins";
	this->poz = new Pozitie(h.nrLin - 1, 0);
	arieVizibilitate = 2;
	h.M[h.nrLin - 1][0] = 'B';
}

void CautatorTip3::mutare(Harta&) {
	//???MISTER???
}