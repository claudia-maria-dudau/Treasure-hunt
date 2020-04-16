#include "ComoaraTip3.h"

ComoaraTip3::ComoaraTip3(Harta& h) : Comoara(h) {
	this->ID += "C3";

	//initializare lista cautatori compatibili
	compatibil.insert("C1");
	compatibil.insert("C3");
}

void ComoaraTip3::gasitComoara(const string idCaut) {
	cout << "Comoara " << this->ID.substr(0, 1) + "a fost gasita de cautarorul " + idCaut.substr(0, 1) + " :) ";
	cout << "Good job" << endl;
}
