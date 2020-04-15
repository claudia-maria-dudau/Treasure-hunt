#include "CautatorTip1.h"

unsigned CautatorTip1::id = 0;

CautatorTip1::CautatorTip1(Harta& h) {
	this->id++;
	this->ID = this->ID + "C1" + to_string(id);
	this->poz = new Pozitie(0, 0);
	arieVizibilitate = 2;
	h.M[0][0] = 'C';
}

void CautatorTip1::mutare() {
	//???MISTER???
	//marchez pozitia pe care ajung
}