#include "CautatorTip1.h"

CautatorTip1::CautatorTip1(Harta& h) {
	this->ID += "C1";
	this->poz = new Pozitie(0, 0);
	this->pozAnt = new Pozitie(0, 0);
	arieVizibilitate = 2;
	h.M[0][0] = 'C';
}

void CautatorTip1::mutare(Harta& h) {
	//???MISTER???
	//marchez pozitia pe care ajung
}