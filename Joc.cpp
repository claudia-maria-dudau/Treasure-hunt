#include "Joc.h"

int Joc::idRunda = 0;

Joc::Joc(const int dimLin, const int dimCol) {
	//creare harta
	this->h = new Harta(dimLin, dimCol);

	//creare cautatori
	this->cautatori.push_back(new CautatorTip1((*h)));
	this->cautatori.push_back(new CautatorTip2((*h)));
	this->cautatori.push_back(new CautatorTip3((*h)));
	this->cautatori.push_back(new CautatorTip4((*h)));

	//creare comori
	this->comori.push_back(new ComoaraTip1((*h)));
	this->comori.push_back(new ComoaraTip2((*h)));
	this->comori.push_back(new ComoaraTip3((*h)));
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
	if (h->getNrCasuteNeexplorate() && this->comori.size() && this->cautatori.size()) {
		idRunda++;
		cout << "Runda " << idRunda << " :" << endl;

		for (int i = 0; i < this->cautatori.size(); i++) {
			//retin pozitia curenta (care v-a deveni anterioara odata ce cautatorul se muta)
			Pozitie p = (*cautatori[i]).getPoz();

			//verific daca pe pozitia curenta se af;a o harta innacesibila cautatorului
			int ok = 0;
			for (int j = 0; j < comori.size(); j++) {
				if (comori[j]->getPoz() == p) {
					ok = 1;
					break;
				}
			}

			//daca da, las marcajul comorii pe harta
			if(ok)
				h->marchez(p.getLinie(), p.getColoana(), 'X');
			
			//daca nu, marchez casuta ca fiind vizitata
			else
				h->marchez(p.getLinie(), p.getColoana(), '|');

			//mut cautatorul
			cautatori[i]->mutare();
			if(!(cautatori[i]->getPoz() == p))
				h->cresteNrCasuteExplorate();

			//verific unde a ajuns pe harta
			string idCaut = cautatori[i]->getID();
			Pozitie p1 = cautatori[i]->getPoz();
			ok = 0;

			//daca a ramas pe aceeasi pozitie inseamna ca s-a blocat si deci nu mai poate participa la joc
			if (p1 == p) {
				cout << "Cautatorul " + idCaut.substr(0, 1) + " s-a blocat :( Better luck next time pal" << endl;
				cautatori[i]->setStadiu("Blocat in runda " + to_string(idRunda));
				ok = 1;
			}

			//daca a gasit comoara
			for(int j = 0; j < this->comori.size(); j++)
				if (p1 == comori[j]->getPoz()) {
					set <string> comp = comori[i]->getCompatibil();

					//verific daca cautatorul este compatibil cu comoara gasita
					//in caz afirmatic marchez comoara ca gasita si scot cautatorul de pe harta
					if (comp.find(idCaut.substr(2, 4)) != comp.end()) {
						comori[j]->gasitComoara(idCaut);
						comori.erase(comori.begin() + j);
						cautatori[i]->setStadiu("Gasit comoara in runda " + to_string(idRunda));
						ok = 1;
						break;
					}
					else
						cout << "Cautatorul " + idCaut.substr(0, 1) + " a gasit o comoara cu care nu este compatibil. Uneori pierzi alteori nu castigi" << endl;
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
			if (comori.size() == 0) {
				adaugClasament(cautatori[0]);
				cautatori.erase(cautatori.begin());
				break;
			}
		}
		this->afisare();
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
	cout << "Boss de boss: Cautator " << Clasament[0]->getID().substr(0, 1)<< " - " + Clasament[0]->getStadiu() << endl;
	cout << "Almost there: Cautator " << Clasament[1]->getID().substr(0, 1) << " - " + Clasament[1]->getStadiu() << endl;
	cout << "Not great, not terrrible: Cautator " << Clasament[2]->getID().substr(0, 1) << " - " + Clasament[2]->getStadiu() << endl;
	cout << "There was an attempt: Cautator " << Clasament[3]->getID().substr(0, 1) << " - " + Clasament[3]->getStadiu() << endl;

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

void Joc::adaugClasament(Cautator* c) {
	int i = 0;
	while (i < this->Clasament.size() && (Clasament[i]->getStadiu()).substr(0, 1) == "R")
		i++;
	Clasament.insert(Clasament.begin() + i, c);
}

bool Joc::terminat() {
	return (cautatori.size() == 0);
}