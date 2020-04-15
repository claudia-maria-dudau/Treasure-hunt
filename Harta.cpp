#include "Harta.h"

Harta::Harta(const int dim): nrLin(dim), nrCol(dim) {
	//creare harta
	this->M = new char* [dim];
	for (int i = 0; i < dim; i++) {
		this->M[i] = new char[dim];
		this->M[i] = new char('-');
	}
	M[0][0] = M[0][nrCol - 1] = M[nrLin - 1][0] = M[nrLin - 1][nrCol - 1] = 'C';	//colturile pe care se afla cautatorii

	this->nrCasuteExplorate = 4;

	//creare cautatori - cand o sa ii am !!!!!!!

	//creare comori
	for (int i = 1; i <= 3; i++)
		this->comori.push_back(new Comoara(dim));
}

Harta::~Harta() {
	//stergere vector cautatori
	cautatori.clear();	

	//stergere vector comori
	comori.clear();						

	//stergere harta
	for (int i = 0; i < this->nrLin; i++)
		delete[] M[i];
	delete[] M;
}

ostream& operator <<(ostream& out, Harta& h) {
	for (int i = 0; i < h.nrLin; i++) {
		for (int j = 0; j < h.nrCol; j++)
			out << h.M[i][j] << " ";
		out << endl;
	}
	out << "Nr de cautatori ce se afla pe harta: " << h.cautatori.size() << endl;
	out << "Nr de comori negasite: " << h.comori.size() << endl;
	out << "Nr de casute neexplorate inca: " << h.nrCasuteExplorate << endl;
	return out;
}