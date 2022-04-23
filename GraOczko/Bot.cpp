#include "Bot.h"

Bot::Bot(){

}
Bot::~Bot() {

}

void Bot::nazwij_bot(int _n) {
	char temp[20]{ 'B','o','t','\0' };

	if (_n == 0) {
		temp[3] = '1';
	}
	else if (_n == 1) {
		temp[3] = '2';
	}
	else if (_n == 2) {
		temp[3] = '3';
	}
		
	for (int i = 0; i < 20; i++) {
		nazwa[i] = temp[i];
	}

	//system("pause");
}
void Bot::ustaw_odwage(){
	do {
		while (1) { //nieskoñczona pêtla
			system("cls");

			std::cout << "Ustaw poziom odwagi botow 1 - nie odwazny, 2 - sredni, 3 - odwazny" << std::endl;
			std::cin >> odwaga; //pobranie zmiennej
			if (std::cin.fail() == true) { //wykrycie b³êdu
				std::cin.clear(); //resetowanie flag b³êdu
				std::cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
			}
			else break;
		}
	} while ((odwaga != 1) && (odwaga != 2) && (odwaga != 3));

}

void Bot::wybor_bot() {
	if (punkty > 21) {
		decyzja_czy_dobieram = false;
	}
	else if (decyzja_czy_dobieram == false) {
		decyzja_czy_dobieram = false;
	}
	else if (odwaga == 1) {
		if (punkty < 10) {
			decyzja_czy_dobieram = true;
		}
		else {
			decyzja_czy_dobieram = false;
		}
	}
	else if (odwaga == 2) {
		if (punkty < 13) {
			decyzja_czy_dobieram = true;
		}
		else {
			decyzja_czy_dobieram = false;
		}
	}
	else {
		if (punkty < 16) {
			decyzja_czy_dobieram = true;
		}
		else {
			decyzja_czy_dobieram = false;
		}
	}

}