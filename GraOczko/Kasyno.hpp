#pragma once
#include "Karta.h"
#include "Gracz.h"
#include "Bot.h"
#include <fstream>
#include <string>

class Kasyno {
private:
	Karta talia[52];
	int akt_karta;
	Karta* karta;
	Gracz* gracz_ludzki;
	Bot* gracz_komputerowy;
public:
	Kasyno();
	~Kasyno();

	void rozgrywka();
	void pokaz_talie();
	void Potasuj();
	void Zapisz_do(int _n, int _f);
	void rozdawanie_kart(int _n, int _f);
	void Podsumowanie(int _n, int _f);

	Karta* dajKarte();
	Karta* akcesor_talia(int _i);

};