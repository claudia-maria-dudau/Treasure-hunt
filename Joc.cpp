#include "Joc.h"

int Joc::idRunda = 0;

Joc::Joc(const int dimLin, const int dimCol) {
	//creare harta
	h = new Harta(dimLin, dimCol);

	//creare cautatori
	cautatori.push_back(new CautatorTip1((*h)));
	cautatori.push_back(new CautatorTip2((*h)));
	cautatori.push_back(new CautatorTip3((*h)));
	cautatori.push_back(new CautatorTip4((*h)));

	//creare comori
	for (int i = 1; i <= 3; i++)
		this->comori.push_back(new Comoara((*h)));
}

Joc::~Joc() {
	this->idRunda = 0;

	//stergere vector cautatori
	this->cautatori.clear();

	//stergere vector comori
	this->comori.clear();

	//stergere harta
	delete h;
}

void Joc::runda() {
	//verific daca pot genera runda
	if ((*h).getNrCasuteNeexplorate() && this->comori.size() && this->cautatori.size()) {
		idRunda++;
		for (int i = 0; i < this->cautatori.size(); i++) {
			//retin pozitia curenta (care v-a deveni anterioara odata ce cautatorul se muta)
			Pozitie p = (*cautatori[i]).getPoz();
			(*h).marchezVizitat(p.getLinie(), p.getColoana());

			//mut cautatorul
			(*cautatori[i]).mutare();
			(*h).cresteNrCasuteExplorate();

			//retin ID-ul cautatorului si pozitia curenta
			string idCaut = (*cautatori[i]).getID();
			Pozitie p1 = (*cautatori[i]).getPoz();

			//verific unde a ajuns pe harta
			//daca a ramas pe aceeasi pozitie inseamna ca s-a blocat si deci nu mai poate participa la joc
			if (p1 == p) {
				cout << "Cautatorul " + idCaut.substr(0, 1) + "s-a blocat :(" << endl;
				cout << "Better luck next time pal" << endl;
				(*cautatori[i]).setStadiu("Blocat");
				cautatori.erase(cautatori.begin() + (i - 1));
				i--;
				break;
			}

			//daca a gasit comoara
			int ok = 0;
			for(int j = 0; j < this->comori.size(); j++)
				if (p1 == (*comori[j]).getPoz()) {
					(*comori[j]).gasitComoara(idCaut, *h);
					comori.erase(comori.begin() + (j - 1));
					ok = 1;
					break;
				}
			if (ok) {
				(*cautatori[i]).setStadiu("Gasit comoara in runda " + to_string(idRunda));
				cautatori.erase(cautatori.begin() + (i - 1));
				i--;
				break;
			}
		}
	}
	else
		throw exceptieJoc();
}


void Joc::afisare() {
	cout << "Runda " << idRunda << " :" << endl;
	cout << (*h);
	cout << "Nr de cautatori ce se afla pe harta: " << this->cautatori.size() << endl;
	cout << "Nr de comori negasite: " << this->comori.size() << endl;
	cout << "Nr de casute neexplorate inca: " << (*h).getNrCasuteNeexplorate() << endl;
	cout << endl;
}