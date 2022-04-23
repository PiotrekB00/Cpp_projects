#pragma once
#include "Karta.h"
#include <string>

class Kasyno;
class Gracz {
private:
	Karta* karta[10];	
	int nr_karty;

public:
	char nazwa[20];//z getchar
	bool decyzja_czy_dobieram;
	int punkty;

	Gracz();
	~Gracz();

	std::string pokaz_karty();

	void nazwij();
	void pokaz_punkty();
	void wybor_pas();
	void wezKarte(Karta* _karta);
	void pokaz();

	int pokaz_nr_karty();

	char* akcesor_nazwa() { return nazwa; }

};