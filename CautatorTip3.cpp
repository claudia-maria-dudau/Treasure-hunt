#include "CautatorTip3.h"

CautatorTip3::CautatorTip3(Harta& h) {
	this->ID += "BB";
	this->nume = "Bilbo Baggins";
	this->poz = new Pozitie(h.nrLin - 1, 0);
	arieVizibilitate = 2;
	h.M[h.nrLin - 1][0] = 'B';
}

void CautatorTip3::mutare(Harta& h) {
	/*//

	int lin = this->poz->getLinie(), col = this->poz->getColoana();

	//verific daca se afla pe pozitia initiala
	if(lin == h.nrLin - 1 && col == 0) {
		//se alege random prima mutare a jucatorului
		int i = rand() % 3;
		switch (i) {
		case 0:	//se muta in sus
			this->poz->setPozitie(lin - 1, col);
			break;
		case 1:	//se muta pe diagonala in sus si la dreapta
			this->poz->setPozitie(lin - 1, col + 1);
			break;
		case 2:	//se muta la dreapta
			this->poz->setPozitie(lin, col + 1);
			break;
		}
	}

	//marchez pozitia pe care ajung
	h.M[this->poz->getLinie()][this->poz->getColoana()] = 'B';*/
}