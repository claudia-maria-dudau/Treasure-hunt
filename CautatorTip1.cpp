#include "CautatorTip1.h"

CautatorTip1::CautatorTip1(Harta& h) {
	this->ID += "IJ";
	this->nume = "Indiana Jones";
	this->poz = new Pozitie(0, 0);
	this->pozAnt = new Pozitie(0, 0);
	arieVizibilitate = 2;
	h.M[0][0] = 'I';
}

CautatorTip1::~CautatorTip1() {
	delete this->pozAnt;
}

void CautatorTip1::mutare(Harta& h) {
	//imparte aria sa vizuala in 4 cadrane (cu cate 6 patratele in fiecare)
	//din cele 4 cadrane nu ia in considerare cadranul in care se afla pozitia sa anterioara
	//alege sa se mute in cadranul ce are cele mai multe casute neexplorate si
	//cele mai multe casute in care poate ajunge

	int lin = this->poz->getLinie(), col = this->poz->getColoana();
	int linAnt = this->pozAnt->getLinie(), colAnt = this->pozAnt->getColoana();

	//pozitia anterioara ia valoarea pozitiei curente
	delete this->pozAnt;
	this->pozAnt = new Pozitie(*poz);

	//verific ca cautatorul sa nu se afla pe aceeasi pozitie ca cea anterioara
	if (lin != linAnt || col != colAnt) {
		//pentru fiecare cadran, cu exceptia celui in care se afla pozitia anterioara a cautatorului,
		//calculez numarul de casute neexplorate 

		//vector ce retine cadranul/cadranele cu numarul min de casute neexplorate
		vector<int> cadraneOpt;		

		//numarul de casute neexplorate corespunzatoare cadaranului/cadranelor din vector
		int neexp = 0;				

		//numarul casutelor posibile pe care se poate deplasa cautatorul in cadarnul/cadranele din vector
		int posibil = 0;			

		//cadran 1
		//verific ca pozitia anterioara sa nu se alfe in cadranul 1
		if (linAnt > lin - 1 || colAnt > col) {
			int nrNeexp = 0, nrPosib = 0;
			for (int i = lin - 2; i <= lin - 1; i++) {
				for (int j = col - 2; j <= col; j++) {
					//verific ca pozitia sa existe in matrice si sa fie neexplorata
					if (h.apartine(i, j) && (h.M[i][j] == '-' || h.M[i][j] == 'X')) {
						nrNeexp++;

						//verific daca poate ajunge pe pozitia respectiva
						if (i == lin - 1 && (j == col - 1 || j == col))
							nrPosib++;
					}
				}
			}

			if (nrNeexp != 0) {
				//intrucat ne aflam in primul cadran, vectorul este gol, deci adaugam direct cadranul in vector
				cadraneOpt.push_back(1);
				neexp = nrNeexp;
				posibil = nrPosib;
			}
		}

		//cadranul 2
		//verific ca pozitia naterioara sa nu se alfe in cadranul 2
		if (linAnt > lin || colAnt < col + 1) {
			int nrNeexp = 0, nrPosib = 0;
			for (int i = lin - 2; i <= lin; i++) {
				for (int j = col + 1; j <= col + 2; j++) {
					//verific ca pozitia sa existe in matrice si sa fie neexplorata
					if (h.apartine(i, j) && (h.M[i][j] == '-' || h.M[i][j] == 'X')) {
						nrNeexp++;

						//verific daca poate ajunge pe pozitia respectiva
						if ((i == lin - 1 || i == lin) && j == col + 1)
							nrPosib++;
					}
				}
			}

			if (nrNeexp != 0) {
				//daca vectorul este gol, adaug cadranul
				if (cadraneOpt.size() == 0) {
					cadraneOpt.push_back(2);
					neexp = nrNeexp;
					posibil = nrPosib;
				}

				//daca numarul de casute neexplorate din cadarn este > decat cel al cadranelor din vector, 
				//golesc vectorul si adaug cadranul
				else if (nrNeexp > neexp) {
					cadraneOpt.clear();
					cadraneOpt.push_back(2);
					neexp = nrNeexp;
					posibil = nrPosib;
				}

				//verific daca numarul de casute neexplorate din cadran este = cu cel al cadranelor din vector
				else if (nrNeexp = neexp) {
					//daca in cadranul curent se poate ajunge in mai multe casute decat din cadranele din vector
					//golesc vectorul si adug cadranul curent
					if (nrPosib > posibil) {
						cadraneOpt.clear();
						cadraneOpt.push_back(2);
						neexp = nrNeexp;
						posibil = nrPosib;
					}

					//daca, atat din cadranul curent cat si din cele din vector, 
					//se poate ajunge in acelasi numar de casute, adaug cadarnul la vector
					if (posibil == nrPosib)
						cadraneOpt.push_back(2);
				}
			}
		}

		//cadranul 3
		//verific ca pozitia naterioara sa nu se alfe in cadranul 3
		if (linAnt < lin + 1 || colAnt < col) {
			int nrNeexp = 0, nrPosib = 0;
			for (int i = lin + 1; i <= lin + 2; i++) {
				for (int j = col; j <= col + 2; j++) {
					//verific ca pozitia sa existe in matrice si sa fie neexplorata
					if (h.apartine(i, j) && (h.M[i][j] == '-' || h.M[i][j] == 'X')) {
						nrNeexp++;

						//verific daca poate ajunge pe pozitia respectiva
						if (i == lin + 1 && (j == col + 1 || j == col))
							nrPosib++;
					}
				}
			}

			if (nrNeexp != 0) {
				//daca vectorul este gol, adaug cadranul
				if (cadraneOpt.size() == 0) {
					cadraneOpt.push_back(3);
					neexp = nrNeexp;
					posibil = nrPosib;
				}

				//daca numarul de casute neexplorate din cadarn este > decat cel al cadranelor din vector, 
				//golesc vectorul si adaug cadranul
				else if (nrNeexp > neexp) {
					cadraneOpt.clear();
					cadraneOpt.push_back(3);
					neexp = nrNeexp;
					posibil = nrPosib;
				}

				//verific daca numarul de casute neexplorate din cadran este = cu cel al cadranelor din vector
				else if (nrNeexp = neexp) {
					//daca in cadranul curent se poate ajunge in mai multe casute 
					//decat din cadranul/cadranele din vector
					//atunci golesc vectorul si adaug cadranul
					if (nrPosib > posibil) {
						cadraneOpt.clear();
						cadraneOpt.push_back(3);
						neexp = nrNeexp;
						posibil = nrPosib;
					}

					//daca, atat din cadranul curent cat si din cele din vector, 
					//se poate ajunge in acelasi numar de causte, adaug cadarnul la vector
					if (posibil == nrPosib)
						cadraneOpt.push_back(3);
				}
			}
		}

		//cadranul 4
		//verific ca pozitia naterioara sa nu se alfe in cadranul 4
		if (linAnt < lin || colAnt > col - 1) {
			int nrNeexp = 0, nrPosib = 0;
			for (int i = lin; i <= lin + 2; i++) {
				for (int j = col - 2; j <= col - 1; j++) {
					//verific ca pozitia sa existe in matrice si sa fie neexplorata
					if (h.apartine(i, j) && (h.M[i][j] == '-' || h.M[i][j] == 'X')) {
						nrNeexp++;

						//verific daca poate ajunge pe pozitia respectiva
						if ((i == lin + 1 || i == lin) && j == col - 1)
							nrPosib++;
					}
				}
			}

			if (nrNeexp != 0) {
				//daca vectorul este gol, adaug cadranul
				if (cadraneOpt.size() == 0) {
					cadraneOpt.push_back(4);
					neexp = nrNeexp;
					posibil = nrPosib;
				}

				//daca numarul de casute neexplorate din cadarn este > decat cel al cadranelor din vector, 
				//golesc vectorul si adaug cadranul
				else if (nrNeexp > neexp) {
					cadraneOpt.clear();
					cadraneOpt.push_back(4);
					neexp = nrNeexp;
					posibil = nrPosib;
				}

				//verific daca numarul de casute neexplorate din cadran este = cu cel al cadranelor din vector
				else if (nrNeexp = neexp) {
					//daca in cadranul curent se poate ajunge in mai multe casute
					//decat din cadranul/cadranele din vector
					//atunci golesc vectorul si adaug cadranul
					if (nrPosib > posibil) {
						cadraneOpt.clear();
						cadraneOpt.push_back(4);
						neexp = nrNeexp;
						posibil = nrPosib;
					}

					//daca, atat din cadranul curent cat si din cele din vector, 
					//se poate ajunge in acelasi numar de casute, adaug cadarnul la vector
					if (posibil == nrPosib)
						cadraneOpt.push_back(4);
				}
			}
		}

		if (cadraneOpt.size() > 0) {
			int cadran, posDep;

			//daca exista mai multe cadrane optime se alege la intamplare unul dintre acestea
			if (cadraneOpt.size() > 1) {
				srand(time(NULL));
				cadran = cadraneOpt[rand() % cadraneOpt.size()];
			}

			//daca exista un singur cadran se alege acesta
			else
				cadran = cadraneOpt[0];

			//daca exista mai multe posibilitati de deplasare, se alege la intampalare una dintre acestea
			int ok = 0;
			if (posibil == 2) {
				posDep = rand() % 2 + 1;
				ok = 1;
			}

			//in functie de cadranul ales se alege pozitia pe care va inainta cautatorul
			switch (cadran) {
			case 1:	//cadranul 1
				if (ok) {
					if (posDep == 1)	//diagonala
						this->poz->setPozitie(lin - 1, col - 1);
					else	//sus
						this->poz->setPozitie(lin - 1, col);
				}
				else {
					if (h.apartine(lin - 1, col - 1) && (h.M[lin - 1][col - 1] == '-' || h.M[lin - 1][col - 1] == 'X'))
						this->poz->setPozitie(lin - 1, col - 1);
					else if (h.apartine(lin - 1, col) && (h.M[lin - 1][col] == '-' || h.M[lin - 1][col] == 'X'))
						this->poz->setPozitie(lin - 1, col);
				}
				break;
			case 2:	//cadranul 2
				if (ok) {
					if (posDep == 1)	//diagonala
						this->poz->setPozitie(lin - 1, col + 1);
					else	//dreapta
						this->poz->setPozitie(lin, col + 1);
				}
				else {
					if (h.apartine(lin - 1, col + 1) < h.nrCol && (h.M[lin - 1][col + 1] == '-' || h.M[lin - 1][col + 1] == 'X'))
						this->poz->setPozitie(lin - 1, col + 1);
					else if (h.apartine(lin, col + 1) && (h.M[lin][col + 1] == '-' || h.M[lin][col + 1] == 'X'))
						this->poz->setPozitie(lin, col + 1);
				}
				break;
			case 3:	//cadranul 3
				if (ok) {
					if (posDep == 1)	//diagonala
						this->poz->setPozitie(lin + 1, col + 1);
					else	//jos
						this->poz->setPozitie(lin + 1, col);
				}
				else {
					if (h.apartine(lin + 1, col + 1) && (h.M[lin + 1][col + 1] == '-' || h.M[lin + 1][col + 1] == 'X'))
						this->poz->setPozitie(lin + 1, col + 1);
					else if (h.apartine(lin + 1, col) && (h.M[lin + 1][col] == '-' || h.M[lin + 1][col] == 'X'))
						this->poz->setPozitie(lin + 1, col);
				}
				break;
			case 4:	//cadranul 4
				if (ok) {
					if (posDep == 1)	//diagonala
						this->poz->setPozitie(lin + 1, col - 1);
					else	//stanga
						this->poz->setPozitie(lin, col - 1);
				}
				else {
					if (h.apartine(lin + 1, col - 1) && (h.M[lin + 1][col - 1] == '-' || h.M[lin + 1][col - 1] == 'X'))
						this->poz->setPozitie(lin + 1, col - 1);
					else if (h.apartine(lin, col - 1) && (h.M[lin][col - 1] == '-' || h.M[lin][col - 1] == 'X'))
						this->poz->setPozitie(lin, col - 1);
				}
				break;
			}
		}
	}

	//daca se afla la inceputul jocului se alege random o mutare de start
	else {
		//se alege random prima mutare a jucatorului

		int i = rand() % 3;
		switch (i) {
		case 0:	//se muta la dreapta
			this->poz->setPozitie(lin, col + 1);
			break;
		case 1:	//se muta pe diagonala in jos si la dreapta
			this->poz->setPozitie(lin + 1, col + 1);
			break;
		case 2:	//se muta in jos
			this->poz->setPozitie(lin + 1, col);
			break;
		}
	}

	//marchez pozitia pe care ajung
	h.M[this->poz->getLinie()][this->poz->getColoana()] = 'I';
}