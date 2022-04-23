#include "RegulatorBB.h"

RegulatorBB::RegulatorBB() 
	: aktualna_moc_BB(0)
	, zmierzona_temperatura(0)
{}

RegulatorBB::~RegulatorBB() {}


float RegulatorBB::steruj(float zadana_temperatura,/* float zmierzona_temperatura, */float delta_t, Pomieszczenie* pomieszczenie, Grzejnik grzejnik) {
	try {
		zmierzona_temperatura = pomieszczenie->getTemperatura();
		if (zmierzona_temperatura < zadana_temperatura) {
			//return 1;
			grzejnik.ustaw_poziom_mocy(1);
		}
		else {
			//return 0;
			grzejnik.ustaw_poziom_mocy(0);
		}
	}
	catch (const char* komunikat_wyjatek) {
		std::cout << komunikat_wyjatek << std::endl;
	}

	aktualna_moc_BB = grzejnik.akcesor_akt_poziom_mocy() * grzejnik.akcesor_moc_nominalna();
	pomieszczenie->dodajCieplo(aktualna_moc_BB);

	//std::cout << "2cieplo: " << aktualna_moc_BB << std::endl;

	return aktualna_moc_BB;//aktualna_moc;
}

