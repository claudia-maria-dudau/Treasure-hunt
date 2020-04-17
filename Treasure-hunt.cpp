#include "Joc.h"

int main() {
	int nrLin, nrCol;

	//citesc nr de linii si coloane
	cout << "Ce dimensiune doresti sa aiba harta?" << endl;
	cout << "Nr lini (minim 15): ";
	cin >> nrLin;
	cout << "Nr coloane (minim 15): ";
	cin >> nrCol;
	cout << endl;

	try {
		if (nrLin < 15 || nrCol < 15)
			throw length_error("Harta este prea mica");

		//creez jocul
		srand(time(NULL));
		Joc j(nrLin, nrCol);
		cout << "Starea initiala: " << endl;
		j.afisare();
		cout << "Cum doriti sa se desfasoare jocul?" << endl;
		cout << "1 - Runda cu runda, cu posibilitatea de a opri jocul cand doriti" << endl;
		cout << "2 - Simulare integrala joc" << endl;
		int OP, op = 1;
		cin >> OP;
		cout << endl;
		system("pause");
		cout << endl;

		try {
			if (OP != 1 && OP != 2)
				throw invalid_argument("Operatia introdusa este gresita");

			switch (OP) {
			case 1:	//Simulare runda cu runda a jocului atat cat doreste utilizatorul
				do {
					cout << endl;

					try {
						j.runda();
					}

					catch (exceptieJoc e) {
						cout << e.what();
						break;
					}

					j.afisare();
					cout << "Doriti sa continuati? 0 - Nu / 1 - Da: ";
					cin >> op;
				} while (op);
				break;

			case 2:	//simulare integrala joc
				while (!j.terminat()) {
					j.runda();
					j.afisare();
				}
				j.afisare();
				break;
			}

			//daca am terminat jocul afisez clasamentul
			if (j.terminat()) {
				cout << endl;
				j.clasament();
			}

			j.afisareComoriRamase();
			cout << "GAME OVER";
		}

		catch (invalid_argument e) {
			cout << e.what();
		}
	}

	catch (length_error e) {
		cout << e.what();
	}

	return 0;
}