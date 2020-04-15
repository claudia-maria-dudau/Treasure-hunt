#include "CautatorTip1.h"

unsigned CautatorTip1::id = 0;

CautatorTip1::CautatorTip1() {
	this->id++;
	this->ID = this->ID + "C1" + to_string(id);
	this->poz = new Pozitie(0, 0);
	arieVizibilitate = 2;
}

void CautatorTip1::mutare() {
	//???MISTER???
}