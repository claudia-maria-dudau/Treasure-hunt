#include "Harta.h"

Harta::Harta(const int dimLin, const int dimCol): nrLin(dimLin), nrCol(dimCol) {
	this->M = new char* [nrLin];
	for (int i = 0; i < nrLin; i++) {
		this->M[i] = new char[nrCol];
		for(int j = 0; j < nrCol; j ++)
			this->M[i][j] = '-';
	}
	this->nrCasuteExplorate = 4;	//colturile ocupate de cei 4 cautatori
}

Harta::~Harta() {				
	for (int i = 0; i < this->nrLin; i++)
		delete[] this->M[i];
	delete[] this->M;
	this->nrLin = this->nrCol = this->nrCasuteExplorate = 0;
}

int Harta::getNrCasuteNeexplorate() const {
	return this->nrLin * this->nrCol - this->nrCasuteExplorate;
}

void Harta::cresteNrCasuteExplorate() {
	this->nrCasuteExplorate++;
}

void Harta::marchezVizitat(const int l, const int c) {
	this->M[l][c] = '|';
}

bool Harta::apartine(const int lin, const int col) const {
	return (lin >= 0 && lin < nrLin && col >= 0 && col < nrCol);
}

ostream& operator <<(ostream& out, Harta& h) {
	for (int i = 0; i < h.nrLin; i++) {
		for (int j = 0; j < h.nrCol; j++)
			out << h.M[i][j] << " ";
		out << endl;
	}
	return out;
}