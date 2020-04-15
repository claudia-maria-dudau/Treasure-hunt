#include "Joc.h"
#include <time.h>

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
		int op = 1;
		system("pause");
		
		//rulez rundele atata timp cat doreste utilizatorul
		do {
			cout << endl << endl;

			try {
				j.runda();
			}
			catch (exceptieJoc e) {
				cout << e.what();
				break;
			}
			
			cout << "Doriti sa continuati? 0 - Nu / 1 - Da: ";
			cin >> op;
		} while (op);

		//daca am terminat jocul afisez clasamentul
		if (j.terminat()) {
			cout << endl << endl;
			j.clasament();
		}
		cout << endl << "GAME OVER";
	}
	catch (length_error e) {
		cout << e.what();
	}

	return 0;
}