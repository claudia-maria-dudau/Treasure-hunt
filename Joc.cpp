#include "Joc.h"

int Joc::idRunda = 0;

Joc::Joc(const int dimLin, const int dimCol) {
	//creare harta
	this->h = new Harta(dimLin, dimCol);

	//creare cautatori
	this->cautatori.push_back(new CautatorTip1(*h));
	this->cautatori.push_back(new CautatorTip2(*h));
	this->cautatori.push_back(new CautatorTip3(*h));
	this->cautatori.push_back(new CautatorTip4(*h));

	//creare comori
	this->comori.push_back(new ComoaraTip1(*h));
	this->comori.push_back(new ComoaraTip2(*h));
	this->comori.push_back(new ComoaraTip3(*h));
}

Joc::~Joc() {
	this->idRunda = 0;
	this->cautatori.clear();
	this->comori.clear();
	this->Clasament.clear();
	delete h;
}

void Joc::runda() {
	//verific daca pot genera runda
	if (h->getNrCasuteNeexplorate() && this->comori.size() && this->cautatori.size()) {
		idRunda++;
		cout << "Runda " << idRunda << " :" << endl;

		for (int i = 0; i < this->cautatori.size(); i++) {
			//retin pozitia curenta (care v-a deveni anterioara odata ce cautatorul se muta)
			Pozitie pAnt = cautatori[i]->getPoz();
			h->marchezVizitat(pAnt.getLinie(), pAnt.getColoana());

			//mut cautatorul
			cautatori[i]->mutare(*h);
			if(cautatori[i]->getPoz() != pAnt)
				h->cresteNrCasuteExplorate();

			//verific unde a ajuns pe harta
			string idCaut = cautatori[i]->getID(), numeCaut = cautatori[i]->getNume();
			Pozitie pAct = cautatori[i]->getPoz();
			int ok = 0;

			//daca a ramas pe aceeasi pozitie inseamna ca s-a blocat si deci nu mai poate participa la joc
			if (pAct == pAnt) {
				cout << numeCaut + " s-a blocat :( Better luck next time pal" << endl;
				cautatori[i]->setStadiu("Blocat in runda " + to_string(idRunda));
				ok = 1;
			}

			//daca a gasit comoara
			else {
				for (int j = 0; j < this->comori.size(); j++) {
					if (pAct == comori[j]->getPoz()) {
						set<string> comp = comori[j]->getCompatibil();

						//verific daca cautatorul este compatibil cu comoara gasita
						//in caz afirmatic marchez comoara ca gasita si scot cautatorul de pe harta
						if (comp.find(idCaut.substr(2, 4)) != comp.end()) {
							comori[j]->gasitComoara(numeCaut);
							comori.erase(comori.begin() + j);
							cautatori[i]->setStadiu("Gasit comoara in runda " + to_string(idRunda));
							ok = 1;
							break;
						}

						//daca cautatorul nu este compatibil cu comoara repozitionez comoara pe harta
						else {
							cout << numeCaut + " a gasit o comoara cu care nu este compatibil. Uneori pierzi alteori nu castigi" << endl;
							comori[j]->repozitionare(*h);
						}
					}
				}
			}

			//daca cautatorul se gaseste in unul dintre cazurile anterioare 
			//atunci il scot din vecotrul de cautatori si il adaug in vectorul pentru clasament
			if (ok) {
				adaugClasament(cautatori[i]);
				cautatori.erase(cautatori.begin() + i);
				i--;
			}

			//verific daca mai exista comori pe harta
			//daca nu mai exista opresc jocul
			if (comori.size() == 0 && cautatori.size() != 0) {
				adaugClasament(cautatori[0]);
				cautatori.erase(cautatori.begin());
				break;
			}
		}
	}
	else
		throw exceptieJoc();
}


void Joc::afisare() {
	cout << endl << (*h) << endl;
	cout << "Nr de cautatori ce se afla pe harta: " << this->cautatori.size() << endl;
	cout << "Nr de comori negasite: " << this->comori.size() << endl;
	cout << "Nr de casute neexplorate inca: " << (*h).getNrCasuteNeexplorate() << endl;
	cout << endl;
}

void Joc::clasament() {
	cout << "----- !!! CLASAMENT !!! -----" << endl;
	cout << "Boss de boss: " + Clasament[0]->getNume() + " - " + Clasament[0]->getStadiu() << endl;
	cout << "Almost there: " + Clasament[1]->getNume() + " - " + Clasament[1]->getStadiu() << endl;
	cout << "Not great, not terrrible: " + Clasament[2]->getNume() + " - " + Clasament[2]->getStadiu() << endl;
	cout << "There was an attempt: " + Clasament[3]->getNume() + " - " + Clasament[3]->getStadiu() << endl;
}

void Joc::adaugClasament(Cautator* c) {
	int i = 0;
	while (i < this->Clasament.size() && (Clasament[i]->getStadiu()).substr(0, 1) == "G")
		i++;
	Clasament.insert(Clasament.begin() + i, c);
}

bool Joc::terminat() {
	return (cautatori.size() == 0);
}

void Joc::afisareComoriRamase() {
	//daca mai exista comori pe tabla afisez pozitia lor
	if (this->comori.size()) {
		cout << endl;
		cout << "Comorile ramase se gaseau la:" << endl;
		for (int i = 0; i < this->comori.size(); i++) {
			Pozitie p = comori[i]->getPoz();
			cout << "(" << p.getLinie() << ", " << p.getColoana() << ")" << " - compatibila cu cautatorii: ";
			set<string> comp = comori[i]->getCompatibil();
			for (auto j : comp)
				cout << j << " ";
			cout << endl;
		}
	}
	cout << endl;
}