#include "CautatorTip4.h"

CautatorTip4::CautatorTip4(Harta& h) {
	this->ID += "SM";
	this->nume = "Scrooge McDuck";
	this->poz = new Pozitie(h.nrLin - 1, h.nrCol - 1);
	arieVizibilitate = 3;
	h.M[h.nrLin - 1][h.nrCol -  1] = 'S';
}

void CautatorTip4::mutare(Harta& h) {
	//???MISTER???
}