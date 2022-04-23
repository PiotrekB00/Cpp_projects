#include "Czas.h"
#include "Harmonogram.h"


Harmonogram::Harmonogram() 
	: liczbaCzasow(0)
	, tabCzasow(nullptr)
{

}

Harmonogram::Harmonogram(const Harmonogram& kopia_Harmonogram) {	//konstruktor kopiujacy
	liczbaCzasow = kopia_Harmonogram.liczbaCzasow;
	tabCzasow = new Czas[liczbaCzasow];
	
	for (int i = 0; i < liczbaCzasow; i++) {
		tabCzasow[i] = kopia_Harmonogram.tabCzasow[i];
	}

}

Harmonogram::~Harmonogram() {
	delete[] tabCzasow;

}

Czas Harmonogram::sumuj(Czas& temp) {
	//chyba w konstruktorze sie zeruje

	for (int i = 0; i < liczbaCzasow; i++) {
		//temp.dodawanie(tabCzasow[i]);
		temp = temp + tabCzasow[i];

	}
	return temp;
}

void Harmonogram::dodajCzas(Czas& nowyCzas) {
	if (tabCzasow == nullptr) {
		tabCzasow = new Czas[++liczbaCzasow];
		tabCzasow[0] = nowyCzas;
	
	}
	else if (tabCzasow != nullptr) {
		Czas* temp = new Czas[liczbaCzasow + 1];
		for (int i = 0; i < liczbaCzasow; i++) {
			temp[i] = tabCzasow[i];
			
		}
		temp[liczbaCzasow] = nowyCzas;
		delete[] tabCzasow;

		tabCzasow = temp;
		liczbaCzasow++;

	}

}

Harmonogram& Harmonogram::operator=(const Harmonogram& _harmonogram) {
	if (&_harmonogram == this) return *this;

	delete[] tabCzasow;
	liczbaCzasow = _harmonogram.liczbaCzasow;
	tabCzasow = new Czas[liczbaCzasow];

	for (int i = 0; i < liczbaCzasow; i++) {
		tabCzasow[i] = _harmonogram.tabCzasow[i];
		
	}
	return *this;
}

void Harmonogram::pokaz() {
	for (int i = 0; i < liczbaCzasow; i++) {
		std::cout << i + 1 << " - ";
		tabCzasow[i].wyswietl();
	}

}

void Harmonogram::wybierz(int x) {
		tabCzasow[x-1].wyswietl();
	
}

void Harmonogram::wyswietl_liczbe_czasow() {
	std::cout << "Aktualna liczba czasow: " << liczbaCzasow << std::endl;
}

Harmonogram Harmonogram::dodaj_do_zakresu(Czas& czas_zakres) {
	Czas temp = 0;
	Harmonogram harmonogram_kopia;

		for (int i = 0; i < liczbaCzasow; i++) {
			//temp.dodawanie(tabCzasow[i]);
			temp = temp + tabCzasow[i];
			if (temp < czas_zakres) {
				harmonogram_kopia.dodajCzas(tabCzasow[i]);
			}
			else break;
		}

	return harmonogram_kopia;

}

Czas Harmonogram::dodaj_sek(int x, int sek) {

	tabCzasow[x - 1] = tabCzasow[x - 1] + sek;
	tabCzasow[x - 1].wyswietl();

	return tabCzasow[x - 1];
}

