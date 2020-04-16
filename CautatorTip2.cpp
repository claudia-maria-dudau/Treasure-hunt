#include "CautatorTip2.h"

CautatorTip2::CautatorTip2(Harta& h) {
	this->ID += "LC";
	this->nume = "Lara Croft";
	this->poz = new Pozitie(0, h.nrCol - 1);
	this->pozAnt = new Pozitie(*poz);
	arieVizibilitate = 1;
	h.M[0][h.nrCol - 1] = 'L';
}

void CautatorTip2::mutare(Harta& h) {
	//scopul lui este sa se indeparteze cat mai mult de pozitia anterioara
	
	int lin = this->poz->getLinie(), col = this->poz->getColoana();
	int linAnt = this->pozAnt->getLinie(), colAnt = this->pozAnt->getColoana();

	//pozitia anterioara ia valoarea pozitiei curente
	delete this->pozAnt;
	this->pozAnt = new Pozitie(*poz);
	
	//daca se afla pe aceeasi line cu pozitia anterioara
	if (lin == linAnt) {
		//daca se afla in dreapta pozitiei anterioare
		if (col == colAnt + 1) {
			if (col + 1 <h.nrCol && h.M[lin][col + 1] == '-')
				this->poz->setPozitie(lin, col + 1);
			else if (lin - 1 >= 0 && col + 1 <h.nrCol && h.M[lin - 1][col + 1] == '-')
				this->poz->setPozitie(lin - 1, col + 1);
			else if (lin + 1 < h.nrLin && col + 1 < h.nrCol && h.M[lin + 1][col + 1] == '-')
				this->poz->setPozitie(lin + 1, col + 1);
			else if (lin - 1 >= 0 && h.M[lin - 1][col] == '-')
				this->poz->setPozitie(lin - 1, col);
			else if (lin + 1 < h.nrLin && h.M[lin + 1][col] == '-')
				this->poz->setPozitie(lin + 1, col);
			else if (lin - 1 >= 0 && h.M[lin - 1][col - 1] == '-')
				this->poz->setPozitie(lin - 1, col - 1);
			else if (lin + 1 < h.nrLin && h.M[lin + 1][col - 1] == '-')
				this->poz->setPozitie(lin + 1, col - 1);
		}

		//daca se afla in stanga pozitiei anterioare
		else {
			if (col - 1 >= 0 && h.M[lin][col - 1] == '-')
				this->poz->setPozitie(lin, col - 1);
			else if (lin + 1 < h.nrLin && col - 1 >= 0 && h.M[lin + 1][col - 1] == '-')
				this->poz->setPozitie(lin + 1, col - 1);
			else if (lin - 1 >= 0 && col - 1 >= 0 && h.M[lin - 1][col - 1] == '-')
				this->poz->setPozitie(lin - 1, col - 1);
			else if (lin + 1 < h.nrLin && h.M[lin + 1][col] == '-')
				this->poz->setPozitie(lin + 1, col);
			else if (lin - 1 >= 0 && h.M[lin - 1][col] == '-')
				this->poz->setPozitie(lin - 1, col);
			else if (lin + 1 < h.nrLin && h.M[lin + 1][col + 1] == '-')
				this->poz->setPozitie(lin + 1, col + 1);
			else if (lin - 1 >= 0 && h.M[lin - 1][col + 1] == '-')
				this->poz->setPozitie(lin - 1, col + 1);
		}
	}

	//daca se afla pe aceeasi coloana cu pozitia anterioara
	else if (col == colAnt) {
		//daca se afla deasupra pozitiei anterioare
		if (lin == linAnt - 1) {
			if (lin - 1 >= 0 && h.M[lin - 1][col] == '-')
				this->poz->setPozitie(lin - 1, col);
			else if (lin - 1 >= 0 && col - 1 >= 0 && h.M[lin - 1][col - 1] == '-')
				this->poz->setPozitie(lin - 1, col - 1);
			else if (lin - 1 >= 0 && col + 1 < h.nrCol && h.M[lin - 1][col + 1] == '-')
				this->poz->setPozitie(lin - 1, col + 1);
			else if (col - 1 >= 0 && h.M[lin][col - 1] == '-')
				this->poz->setPozitie(lin, col - 1);
			else if (col + 1 < h.nrCol && h.M[lin][col + 1] == '-')
				this->poz->setPozitie(lin, col + 1);
			else if (col - 1 >= 0 && h.M[lin + 1][col - 1] == '-')
				this->poz->setPozitie(lin + 1, col - 1);
			else if (col + 1 < h.nrCol && h.M[lin + 1][col + 1] == '-')
				this->poz->setPozitie(lin + 1, col + 1);
		}

		//daca se afla sub pozitia anterioara
		else {
			if (lin + 1 < h.nrLin && h.M[lin + 1][col] == '-')
				this->poz->setPozitie(lin + 1, col);
			else if (lin + 1 < h.nrLin && col + 1 < h.nrCol && h.M[lin + 1][col + 1] == '-')
				this->poz->setPozitie(lin + 1, col + 1);
			else if (lin + 1 < h.nrLin && col - 1 >= 0 && h.M[lin + 1][col - 1] == '-')
				this->poz->setPozitie(lin + 1, col - 1);
			else if (col + 1 < h.nrCol && h.M[lin][col + 1] == '-')
				this->poz->setPozitie(lin, col + 1);
			else if (col - 1 >= 0 && h.M[lin][col - 1] == '-')
				this->poz->setPozitie(lin, col - 1);
			else if (col + 1 < h.nrCol && h.M[lin - 1][col + 1] == '-')
				this->poz->setPozitie(lin - 1, col + 1);
			else if (col - 1 >= 0 && h.M[lin - 1][col - 1] == '-')
				this->poz->setPozitie(lin - 1, col - 1);
		}		
	}

	//daca se afla deasupra si la dreapta fata de pozitia initiala
	else if (lin == linAnt - 1 && col == colAnt + 1) {
		if (lin - 1 >= 0 && col + 1 < h.nrCol && h.M[lin - 1][col + 1] == '-')
			this->poz->setPozitie(lin - 1, col + 1);
		else if (lin - 1 >= 0 && h.M[lin - 1][col] == '-')
			this->poz->setPozitie(lin - 1, col);
		else if (col + 1 < h.nrCol && h.M[lin][col + 1] == '-')
			this->poz->setPozitie(lin, col + 1);
		else if (lin - 1 >= 0 && h.M[lin - 1][col - 1] == '-')
			this->poz->setPozitie(lin - 1, col - 1);
		else if (col + 1 < h.nrCol && h.M[lin + 1][col + 1] == '-')
			this->poz->setPozitie(lin + 1, col + 1);
		else if(h.M[lin][col - 1] == '-')
			this->poz->setPozitie(lin, col - 1);
		else if(h.M[lin + 1][col] == '-')
			this->poz->setPozitie(lin + 1, col);
	}

	//daca se afla deasupra si la stanga fata de pozitia initiala
	else if (lin == linAnt - 1 && col == colAnt - 1) {
		if (lin - 1 >= 0 && col - 1 >= 0 && h.M[lin - 1][col - 1] == '-')
			this->poz->setPozitie(lin - 1, col - 1);
		else if (col - 1 >= 0 && h.M[lin][col - 1] == '-')
			this->poz->setPozitie(lin, col - 1);
		else if (lin - 1 >= 0 && h.M[lin - 1][col] == '-')
			this->poz->setPozitie(lin - 1, col);
		else if (col - 1 >= 0 && h.M[lin + 1][col - 1] == '-')
			this->poz->setPozitie(lin + 1, col - 1);
		else if (lin - 1 >= 0 && h.M[lin - 1][col + 1] == '-')
			this->poz->setPozitie(lin - 1, col + 1);
		else if (h.M[lin + 1][col] == '-')
			this->poz->setPozitie(lin + 1, col);
		else if (h.M[lin][col + 1] == '-')
			this->poz->setPozitie(lin, col + 1);
	}

	//daca se afla sub si in dreapta pozitieie anterioare
	else if (lin == linAnt + 1 && col == colAnt + 1) {
		if(lin + 1 < h.nrLin && col + 1 < h.nrCol && h.M[lin + 1][col + 1] == '-')
			this->poz->setPozitie(lin + 1, col + 1);
		else if (col + 1 < h.nrCol && h.M[lin][col + 1] == '-')
			this->poz->setPozitie(lin, col + 1);
		else if (lin + 1 < h.nrLin && h.M[lin + 1][col] == '-')
			this->poz->setPozitie(lin + 1, col);
		else if (col + 1 < h.nrCol && h.M[lin - 1][col + 1] == '-')
			this->poz->setPozitie(lin - 1, col + 1);
		else if (lin + 1 < h.nrLin && h.M[lin + 1][col - 1] == '-')
			this->poz->setPozitie(lin + 1, col - 1);
		else if (h.M[lin - 1][col] == '-')
			this->poz->setPozitie(lin - 1, col);
		else if (h.M[lin][col - 1] == '-')
			this->poz->setPozitie(lin, col - 1);
	}

	//daca se afla sub si in stanga pozitiei anterioare
	else if (lin == linAnt + 1 && col == colAnt - 1) {
		if(lin + 1 < h.nrLin && col - 1 >= 0 && h.M[lin + 1][col - 1] == '-')
			this->poz->setPozitie(lin + 1, col - 1);
		else if (lin + 1 < h.nrLin && h.M[lin + 1][col] == '-')
			this->poz->setPozitie(lin + 1, col);
		else if (col - 1 >= 0 && h.M[lin][col - 1] == '-')
			this->poz->setPozitie(lin, col - 1);
		else if (lin + 1 < h.nrLin && h.M[lin + 1][col + 1] == '-')
			this->poz->setPozitie(lin + 1, col + 1);
		else if (col - 1 >= 0 && h.M[lin - 1][col - 1] == '-')
			this->poz->setPozitie(lin - 1, col - 1);
		else if (h.M[lin][col + 1] == '-')
			this->poz->setPozitie(lin, col + 1);
		else if (h.M[lin - 1][col] == '-')
			this->poz->setPozitie(lin - 1, col);
	}

	//daca se afla pe aceeasi pozitie cu pozitia anterioara inseamna ca ori este inceputul jocului ori s-a blocat
	//ne intereseaza doar cazul in care abia a inceput jocul
	//daca jucatorul este blocat el nu o sa se poata oricum muta nicaieri
	else {
		//se alege random prima mutare a jucatorului
		srand(time(NULL));
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

	h.M[this->poz->getLinie()][this->poz->getColoana()] = 'L';
}