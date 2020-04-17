#include "CautatorTip2.h"
#include <cmath>

CautatorTip2::CautatorTip2(Harta& h) {
	this->ID += "LC";
	this->nume = "Lara Croft";
	this->poz = new Pozitie(0, h.nrCol - 1);
	this->pozAnt = new Pozitie(*poz);
	arieVizibilitate = 1;
	h.M[0][h.nrCol - 1] = 'L';
}

CautatorTip2::~CautatorTip2() {
	delete this->pozAnt;
}

void CautatorTip2::mutare(Harta& h) {
	//scopul lui este sa se indeparteze cat mai mult de pozitia anterioara
	
	int lin = this->poz->getLinie(), col = this->poz->getColoana();
	int linAnt = this->pozAnt->getLinie(), colAnt = this->pozAnt->getColoana();

	//pozitia anterioara ia valoarea pozitiei curente
	delete this->pozAnt;
	this->pozAnt = new Pozitie(*poz);

	//daca se afla pe o pozitie diferita fata de cea anterioara
	if (lin != linAnt || col != colAnt) {
		vector<Pozitie> pozOpt;		//vector in care retin pozitia/pozitiile cele mai indepartate de pozitia anterioara
		double dist;				//distanta pozitiei/pozitiilor cele mai indepartate fata de pozitia anterioara

		//calculez distanta dintre pozitia anterioara si pozitiile posibile pe care cautatorul se poate deplasa
		//si retin pozitia/pozitiile ce au distanta maxima fata de cea anterioara
		for (int i = lin - 1; i <= lin + 1; i++) {
			for (int j = col - 1; j <= col + 1; j++) {
				//verific daca pozitia exista in matrice si este accesibila cautatorului
				if (i >= 0 && i < h.nrLin && j >= 0 && j < h.nrCol && (h.M[i][j] == '-' || h.M[i][j] == 'X')) {
					double d = sqrt(pow((linAnt - i), 2) + pow((colAnt - j), 2));

					//daca vectorul este gol adaug pozitia
					if (pozOpt.size() == 0) {
						pozOpt.push_back(Pozitie(i, j));
						dist = d;
					}

					//verific daca distanta pozitiei actuale este mai mare decat distanta pozitiilor din vector
					//caz in care golesc vectorul si adaug noua pozitie
					else if (d > dist) {
						pozOpt.clear();
						pozOpt.push_back(Pozitie(i, j));
						dist = d;
					}

					//verific daca distanta pozitiei actuale este egala cu distanta pozitiilor din vector
					//caz in care adaug pozitia actuala in vector
					else if (d == dist)
						pozOpt.push_back(Pozitie(i, j));
				}
			}
		}

		//daca exist mai multe pozitii ce se afla la distante egale fata de pozitia anteriora
		//se alege random una dintre ele
		if (pozOpt.size() > 1) {
			delete this->poz;
			srand(time(NULL));
			this->poz = new Pozitie(pozOpt[rand() % (pozOpt.size() - 1)]);
		}

		//daca am o singura pozitie in vector, pe aceasta se va duce cautatorul
		else if (pozOpt.size() == 1) {
			delete this->poz;
			this->poz = new Pozitie(pozOpt[0]);
		}
	}

	//daca se afla pe pozitia initiala se alege o pozitia la intamplare pe care sa se mute
	else {
		//se alege random prima mutare a jucatorului
		int i = rand() % 3;
		switch (i) {
		case 0:	//se muta la stanga
			this->poz->setPozitie(lin, col - 1);
			break;
		case 1:	//se muta pe diagonala in jos si la stanga
			this->poz->setPozitie(lin + 1, col - 1);
			break;
		case 2:	//se muta in jos
			this->poz->setPozitie(lin + 1, col);
			break;
		}
	}

	//marchez pozitia pe care ajung
	h.M[this->poz->getLinie()][this->poz->getColoana()] = 'L';
}