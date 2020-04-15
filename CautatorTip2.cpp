#include "CautatorTip2.h"

unsigned CautatorTip2::id = 0;

CautatorTip2::CautatorTip2(Harta& h) {
	this->id++;
	this->ID = this->ID + "C2" + to_string(id);
	this->poz = new Pozitie(0, h.nrCol - 1);
	arieVizibilitate = 1;
	h.M[0][h.nrCol - 1] = 'C';
}

void CautatorTip2::mutare() {
	//???MISTER???
}
