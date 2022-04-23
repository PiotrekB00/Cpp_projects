#pragma once
//#include "Symulacja.h"
#include <vector>
#include <iostream>

class Grzejnik {
private:
	float moc_nominalna;
	float akt_poziom_mocy;

public:
	Grzejnik();
	~Grzejnik();

	float akcesor_moc_nominalna() { return moc_nominalna; }
	float akcesor_akt_poziom_mocy() { return akt_poziom_mocy; }

	void ustaw_poziom_mocy(float akt_poziom_mocy);
	void ustaw_moc_nominalna(float _moc_nominalna);
};