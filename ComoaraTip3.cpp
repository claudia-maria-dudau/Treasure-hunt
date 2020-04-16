#include "ComoaraTip3.h"

ComoaraTip3::ComoaraTip3(Harta& h) : Comoara(h) {
	this->ID += "C3";

	//initializare lista cautatori compatibili
	compatibil.insert("IJ");
	compatibil.insert("BB");
}

void ComoaraTip3::gasitComoara(const string numeCaut) {
	cout << "Comoara " << this->ID.substr(0, 1) + " a fost gasita de " + numeCaut + " :) ";
	cout << "Good job" << endl;
}
