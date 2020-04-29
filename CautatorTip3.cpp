#include "CautatorTip3.h"

CautatorTip3::CautatorTip3(Harta& h) {
	this->ID += "BB";
	this->nume = "Bilbo Baggins";
	this->poz = new Pozitie(h.nrLin - 1, 0);
	arieVizibilitate = 2;
	h.M[h.nrLin - 1][0] = 'B';
}

void CautatorTip3::mutare(Harta& h) {
	//se duce cat mai departe posibil de restul cautatorilor si evita sa se intersecteze cu acestia

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

	else {
		Pozitie pozCaut = Pozitie(0, 0);

		//verific daca langa el se afla un cautator
		for (int i = lin - 1; i <= lin + 1; i++) {
			for (int j = col - 1; j <= col + 1; j++) {
				//daca pozitia exista si pe aceasta se afla un cautator
				if (h.apartine(i, j)) {
					if (h.M[i][j] != '-' || h.M[i][j] != '|' || h.M[i][j] != 'X' || h.M[i][j] != 'B') {
						pozCaut = Pozitie(i, j);
						break;
					}
				}
			}
		}

		if (pozCaut != Pozitie(0, 0)) {
			//vector in care retin pozitia/pozitiile cele mai indepartate de cautator
			vector<Pozitie> pozOpt;	

			//distanta pozitiei/pozitiilor cele mai indepartate fata de cautator
			double dist;				

			//calculez distanta dintre pozitia cautatorului si pozitiile posibile pe care se poate deplasa
			//si retin pozitia/pozitiile ce au distanta maxima fata de cea a cautatorului
			for (int i = lin - 1; i <= lin + 1; i++) {
				for (int j = col - 1; j <= col + 1; j++) {
					//verific daca pozitia exista in matrice si este accesibila cautatorului curent
					if (h.apartine(i, j) && (h.M[i][j] == '-' || h.M[i][j] == 'X')) {
						double d = sqrt(pow((pozCaut.getLinie() - i), 2) + pow((pozCaut.getColoana() - j), 2));

						//daca vectorul este gol adaug pozitia
						if (pozOpt.size() == 0) {
							pozOpt.push_back(Pozitie(i, j));
							dist = d;
						}

						//verific daca distanta pozitiei actuale este > decat 
						//distanta pozitiei/pozitiilor din vector fata de cautator
						//caz in care golesc vectorul si adaug noua pozitie
						else if (d > dist) {
							pozOpt.clear();
							pozOpt.push_back(Pozitie(i, j));
							dist = d;
						}

						//verific daca distanta pozitiei actuale este = cu distanta pozitiei/pozitiilor din vector
						//caz in care adaug pozitia actuala in vector
						else if (d == dist)
							pozOpt.push_back(Pozitie(i, j));
					}
				}
			}

			//daca exist mai multe pozitii ce se afla la distante maxime egale fata de cautator
			//se alege random una dintre ele
			if (pozOpt.size() > 1) {
				delete this->poz;
				srand(time(NULL));
				this->poz = new Pozitie(pozOpt[rand() % pozOpt.size()]);
			}

			//daca am o singura pozitie in vector, pe aceasta se va duce cautatorul
			else if (pozOpt.size() == 1) {
				delete this->poz;
				this->poz = new Pozitie(pozOpt[0]);
			}
		}

		//daca nu se afla langa un cautator determin pozitia optima pe care se poate deplasa
		//(pozitia cu cele mai multe posibilitati de continuare si care nu se afla langa un alt cautator)
		else {
			//vector ce retine pozitia/pozitiile optime pe care se poate deplasa cautatorul
			vector<Pozitie> pozOpt;	

			//numarul de pozitii accesibile pentru pozitia/pozitiile din vector
			int pozPos = 0;					

			//pentru fiecare pozitie accesibila cautatorului numar la cate pozitii are acces si
			//daca se afla sau nu langa un alt cautator
			for (int i = lin - 1; i <= lin + 1; i++) {
				for (int j = col - 1; j <= col + 1; j++) {
					int nrPos = 0;

					//daca pozitia exista si este accesibila ma uit la vecii ei
					if (h.apartine(i, j) && (h.M[i][j] != '-' || h.M[i][j] != 'X')) {
						for (int i1 = i - 1; i1 <= i + 1; i1++) {
							for (int j1 = j - 1; j1 <= j + 1; j1++) {
								//daca pozitia exista
								if (h.apartine(i1, j1)) {
									//verific daca este accesibila
									if (h.M[i1][j1] == '-' || h.M[i1][j1] == 'X')
										nrPos++;

									//verific daca pe pozitie se afla un cautator
									else if (h.M[i1][j1] != '|' && h.M[i1][j1] != 'B') {
										nrPos = 0;
										break;
									}
								}
							}
						}

						//daca vectorul este vid adaug pozitia in vector
						if (pozOpt.size() == 0) {
							pozOpt.push_back(Pozitie(i, j));
							pozPos = nrPos;
						}

						//daca numarul de pozitii accesibile din pozitia curenta este > decat
						//cel accesibile din pozitia/pozitiile din vector
						//golesc vctorul si adaug pozitia
						else if (nrPos > pozPos) {
							pozOpt.clear();
							pozOpt.push_back(Pozitie(i, j));
							pozPos = nrPos;
						}

						//daca numarul de pozitii accesibile din pozitia curenta este egal cu
						//numarul de pozitii accesibile din vector
						//adaug pozitia curenta la vector
						else if (nrPos == pozPos)
							pozOpt.push_back(Pozitie(i, j));
					}
				}
			}

			//daca exist mai multe pozitii la fel de optime se alege random una dintre ele
			if (pozOpt.size() > 1) {
				delete this->poz;
				srand(time(NULL));
				this->poz = new Pozitie(pozOpt[rand() % pozOpt.size() - 1]);
			}

			//daca am o singura pozitie in vector, pe acesta se va duce cautatorul
			else if (pozOpt.size() == 1) {
				delete this->poz;
				this->poz = new Pozitie(pozOpt[0]);
			}
		}
	}

	//marchez pozitia pe care ajung
	h.M[this->poz->getLinie()][this->poz->getColoana()] = 'B';
}