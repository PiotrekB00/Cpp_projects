#include "Grzejnik.h"

Grzejnik::Grzejnik()
	: moc_nominalna(0)
	, akt_poziom_mocy(0)
{}

Grzejnik::~Grzejnik() {}

void Grzejnik::ustaw_poziom_mocy(float _akt_poziom_mocy) {
	if (_akt_poziom_mocy >= 0.0 && _akt_poziom_mocy <= 1.0) {
		akt_poziom_mocy = _akt_poziom_mocy;
	}
	//std::cout << "akt_poziom_mocy: " << akt_poziom_mocy << std::endl;
}

void Grzejnik::ustaw_moc_nominalna(float _moc_nominalna) {
	moc_nominalna = _moc_nominalna;
}