#include "CautatorTip4.h"

CautatorTip4::CautatorTip4(Harta& h) {
	this->ID += "SM";
	this->nume = "Scrooge McDuck";
	this->poz = new Pozitie(h.nrLin - 1, h.nrCol - 1);
	arieVizibilitate = 3;
	h.M[h.nrLin - 1][h.nrCol -  1] = 'S';
}

void CautatorTip4::mutare(Harta& h) {
	//la fiecare pas se alege pozitia din care se poate ajunge in cele mai multe pozitii
	//luand in considerare mutarile posibile pentru urmatoarele doua runde

	int lin = this->poz->getLinie(), col = this->poz->getColoana();

	//verific daca se afla pe pozitia initiala
	if (lin == h.nrLin - 1 && col == h.nrCol - 1) {
		//se alege random prima mutare a jucatorului
		int i = rand() % 3;
		switch (i) {
		case 0:	//se muta in sus
			this->poz->setPozitie(lin - 1, col);
			break;
		case 1:	//se muta pe diagonala in sus si la stanga
			this->poz->setPozitie(lin - 1, col - 1);
			break;
		case 2:	//se muta la stanga
			this->poz->setPozitie(lin, col - 1);
			break;
		}
	}

	else {
		//vector ce retine pozitia/pozitiile optime pe care se poate deplasa cautatorul
		vector<Pozitie> pozOpt;		

		//numarul de pozitii accesibile pentru pozitia/pozitiile din vector
		int pozPos = 0;					

		//pentru fiecare pozitie aceesibila jucatorului 
		//numar cate pozitii poate aceesa fiecare pozitie accesibila acesteia
		for (int i = lin - 1; i <= lin + 1; i++) {
			for (int j = col - 1; j <= col + 1; j++) {
				int nrPos = 0;

				//daca exista pozitia in matrice si este accesibila
				if (h.apartine(i, j) && (h.M[i][j] == '-' || h.M[i][j] == 'X')) {
					for (int i1 = i - 1; i1 <= i + 1; i1++) {
						for (int j1 = j - 1; j1 <= j + 1; j1++) {
							//daca exista pozitia in matrice si este accesibila
							if (h.apartine(i1, j1) && (h.M[i][j] == '-' || h.M[i][j] == 'X')) {
								if (i1 == i - 1 && j1 == j - 1) {	//diagonala stanga sus
									for (int i2 = i1 - 1; i2 <= i1; i2++) {
										for (int j2 = j1 - 1; j2 <= j1 + 1; j2++) {
											//daca exista pozitia
											if (h.apartine(i2, j2)) {
												//daca pozitia este nvizitata o adaug la numarul de pozitii posibile
												if (h.M[i2][j2] == '-' || h.M[i2][j2] == 'X')
													nrPos++;

												//daca pe pozitia data se afla un cautator scad 2 din numarul de pozitii posibile
												//(pozitiile pe care le poate bloca cautatorul respectiv in urmatoarele 2 runde)
												else if (h.M[i2][j2] != '|')
													nrPos -= 2;
											}
										}
									}
								}

								if (i1 == i - 1 && j1 == j + 1) {	//diagonala dreapta sus
									for (int i2 = i1 - 1; i2 <= i1 + 1; i2++) {
										for (int j2 = j1; j2 <= j1 + 1; j2++) {
											//daca exista pozitia
											if (h.apartine(i2, j2)) {
												//daca pozitia este nvizitata o adaug la numarul de pozitii posibile
												if (h.M[i2][j2] == '-' || h.M[i2][j2] == 'X')
													nrPos++;

												//daca pe pozitia data se afla un cautator scad 2 din numarul de pozitii posibile
												//(pozitiile pe care le poate bloca cautatorul respectiv in urmatoarele 2 runde)
												else if (h.M[i2][j2] != '|')
													nrPos -= 2;
											}
										}
									}
								}

								if (i1 == i + 1 && j1 == j + 1) {	//diagonala stanga jos
									for (int i2 = i1; i2 <= i1 + 1; i2++) {
										for (int j2 = j1 - 1; j2 <= j1 + 1; j2++) {
											//daca exista pozitia
											if (h.apartine(i2, j2)) {
												//daca pozitia este nvizitata o adaug la numarul de pozitii posibile
												if (h.M[i2][j2] == '-' || h.M[i2][j2] == 'X')
													nrPos++;

												//daca pe pozitia data se afla un cautator scad 2 din numarul de pozitii posibile
												//(pozitiile pe care le poate bloca cautatorul respectiv in urmatoarele 2 runde)
												else if (h.M[i2][j2] != '|')
													nrPos -= 2;
											}
										}
									}
								}

								if (i1 == i + 1 && j1 == j - 1) {	//diagonala dreapta jos
									for (int i2 = i1 - 1; i2 <= i1 + 1; i2++) {
										for (int j2 = j1; j2 <= j1 + 1; j2++) {
											//daca exista pozitia
											if (h.apartine(i2, j2)) {
												//daca pozitia este nvizitata o adaug la numarul de pozitii posibile
												if (h.M[i2][j2] == '-' || h.M[i2][j2] == 'X')
													nrPos++;

												//daca pe pozitia data se afla un cautator scad 2 din numarul de pozitii posibile
												//(pozitiile pe care le poate bloca cautatorul respectiv in urmatoarele 2 runde)
												else if (h.M[i2][j2] != '|')
													nrPos -= 2;
											}
										}
									}
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

					//daca numarul de pozitii accesibile din pozitia curenta este = cu
					//numarul de pozitii accesibile din vector
					//adaug pozitia curenta la vector
					else if (nrPos == pozPos)
						pozOpt.push_back(Pozitie(i, j));
				}
			}
		}

		//daca exist mai multe pozitii cu acelasi numar de pozitii accesibile
		//se alege random una dintre ele
		if (pozOpt.size() > 1) {
			delete this->poz;
			srand(time(NULL));
			this->poz = new Pozitie(pozOpt[rand() % pozOpt.size()]);
		}

		//daca am o singura pozitie in vector, pe acesta se va duce cautatorul
		else if (pozOpt.size() == 1) {
			delete this->poz;
			this->poz = new Pozitie(pozOpt[0]);
		}
	}

	//marchez pozitia pe care ajung
	h.M[this->poz->getLinie()][this->poz->getColoana()] = 'S';
}