#include "Gracz.h"

Gracz::Gracz()
	:karta()
	,nr_karty(0)
	,punkty(0)
	, decyzja_czy_dobieram(true)
{
	
}

Gracz::~Gracz() {

}

std::string Gracz::pokaz_karty() {//bez pkt
	std::string tmp = "";

	for (int i = 0; i < nr_karty; i++) {

		tmp = tmp+karta[i]->getFigura();
		if (karta[i]->getKolor() == 3) {
			tmp = tmp + "K" + " ";//karo
		}
		else if (karta[i]->getKolor() == 4) {
			tmp = tmp + "k" + " ";//kier
		}
		else if (karta[i]->getKolor() == 5) {
			tmp = tmp + "T" + " ";//trefl
		}
		else if (karta[i]->getKolor() == 6) {
			tmp = tmp + "P" + " ";//pik
		}
		
		//tmp = tmp+karta[i]->getKolor() + " ";
	}
	return tmp;
}

void Gracz::nazwij() {
	std::cout << "Podaj nazwe gracza" << std::endl;
	std::cin >> nazwa;
}

void Gracz::wezKarte(Karta* _karta) {
	karta[nr_karty] = _karta;
	nr_karty++;
	if (nr_karty == 11)nr_karty = 0;

	punkty = punkty + (_karta->getWartosc());
}

void Gracz::pokaz() {//pokaz karty z pkt 
	std::cout << "karta gracza:	";
	for (int i = 0; i < nr_karty; i++) {
		karta[i]->wypisz();
	}	
	pokaz_punkty();
}

int Gracz::pokaz_nr_karty() {
	return nr_karty;
}

void Gracz::pokaz_punkty() {
	std::cout << std::endl << "punkty na rece:	" << punkty << std::endl << std::endl;
}

void Gracz::wybor_pas() {
	int n = 0;

	//decyzja_czy_dobieram = PRAWDA - dobieram
	//decyzja_czy_dobieram = FALSZ  - pas

	if (punkty > 21) {
		decyzja_czy_dobieram = false;
		//std::cout << "Przekroczono 21 punkty!" << std::endl;
	}
	else if (decyzja_czy_dobieram == false) {
		decyzja_czy_dobieram = false;
		//std::cout << "Ten gracz juz spasowal" << std::endl;
	}
	else {
		do {
			while (1) { //nieskoñczona pêtla
				//system("cls");
				std::cout << "1 - dobieram" << std::endl << "0 - pasuje" << std::endl;
				std::cin >> n; //pobranie zmiennej
				if (std::cin.fail() == true) { //wykrycie b³êdu
					std::cin.clear(); //resetowanie flag b³êdu
					std::cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
				}
				else break;
			}
		} while ((n != 0) && (n != 1));

		if (n == 1) {
			decyzja_czy_dobieram = true;
			//std::cout << "dobieram-gracz" << std::endl;
		}
		else {
			decyzja_czy_dobieram = false;
			//std::cout << "pasuje-gracz" << std::endl;
		}
	}
}

