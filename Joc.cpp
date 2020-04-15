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
	if (h->getNrCasuteNeexplorate() && this->comori.size() && this->cautatori.size()) {
		idRunda++;
		cout << "Runda " << idRunda << " :" << endl;

		for (int i = 0; i < this->cautatori.size(); i++) {
			//retin pozitia curenta (care v-a deveni anterioara odata ce cautatorul se muta)
			Pozitie p = (*cautatori[i]).getPoz();
			h->marchezVizitat(p.getLinie(), p.getColoana());

			//mut cautatorul
			cautatori[i]->mutare();
			if(!(cautatori[i]->getPoz() == p))
				h->cresteNrCasuteExplorate();

			//retin ID-ul cautatorului si pozitia curenta
			string idCaut = cautatori[i]->getID();
			Pozitie p1 = cautatori[i]->getPoz();

			//verific unde a ajuns pe harta
			int ok = 0;

			//daca a ramas pe aceeasi pozitie inseamna ca s-a blocat si deci nu mai poate participa la joc
			if (p1 == p) {
				cout << "Cautatorul " + idCaut.substr(0, 1) + " s-a blocat :( " << "Better luck next time pal" << endl;
				cautatori[i]->setStadiu("Blocat in runda " + to_string(idRunda));
				ok = 1;
			}

			//daca a gasit comoara
			for(int j = 0; j < this->comori.size(); j++)
				if (p1 == comori[j]->getPoz()) {
					comori[j]->gasitComoara(idCaut, *h);
					comori.erase(comori.begin() + j);
					cautatori[i]->setStadiu("Gasit comoara in runda " + to_string(idRunda));
					ok = 1;
					break;
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
		cout << "Comorile ramase se gaseau la: ";
		for (int i = 0; i < this->comori.size(); i++) {
			Pozitie p = comori[i]->getPoz();
			cout << "(" << p.getLinie() << ", " << p.getColoana() << ")" << " ";
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