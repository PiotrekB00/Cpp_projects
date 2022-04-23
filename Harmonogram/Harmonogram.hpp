#pragma once
#include <iostream>
#include "Czas.h"

class Harmonogram {

private:
	int liczbaCzasow;
	Czas* tabCzasow;
public:
	Harmonogram();
	Harmonogram(const Harmonogram& kopia_Harmonogram);
	~Harmonogram();

	int get_liczba_czasow() { return liczbaCzasow; }
	void pokaz();
	void wybierz(int x);
	void wyswietl_liczbe_czasow();
	//void dodawannie_czasow();
	void dodajCzas(Czas& nowyCzas);
	Czas sumuj(Czas& _suma);
	Czas dodaj_sek(int x, int sek);
	Harmonogram dodaj_do_zakresu(Czas& czas_zakres);
	Harmonogram& operator=(const Harmonogram& _harmonogram);

};