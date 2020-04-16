#include "CautatorTip2.h"

CautatorTip2::CautatorTip2(Harta& h) {
	this->id++;
	this->ID += "C2";
	this->poz = new Pozitie(0, h.nrCol - 1);
	arieVizibilitate = 1;
	h.M[0][h.nrCol - 1] = 'C';
}

void CautatorTip2::mutare() {
	//???MISTER???
}
