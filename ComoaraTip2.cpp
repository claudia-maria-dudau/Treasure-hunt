#include "ComoaraTip2.h"

ComoaraTip2::ComoaraTip2(Harta& h) : Comoara(h) {
	this->ID += "C2";

	//initializare lista cautatori compatibili
	compatibil.insert("IJ");
	compatibil.insert("LC");
	compatibil.insert("SM");
}

void ComoaraTip2::gasitComoara(const string numeCaut) {
	cout << "Comoara " << this->ID.substr(0, 1) + " a fost gasita de " + numeCaut + " :) ";
	cout << "Excelent work" << endl;
}