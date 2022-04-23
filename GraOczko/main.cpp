//Projekt 2 - Gra w oczko
//Piotr Barabasz 255294

#include "Kasyno.h"

int main() {

	Kasyno kasyno1;
	int w;
	setlocale(LC_CTYPE, "Polish");
	while (1) {
		std::cout << "Gra w oczko" << std::endl << "1 - nowa gra" << std::endl << "2 - zakoncz" << std::endl;
		std::cin >> w; //pobranie zmiennej
		system("cls");
		//Zabezpiecznie przed wpisaniem tekstu
		if (std::cin.fail() == true) { //wykrycie b³êdu		
			std::cin.clear(); //resetowanie flag b³êdu
			std::cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
		}

		switch (w) {
		case 1:
			system("cls");
			kasyno1.rozgrywka();
			system("pause");
			std::cout << "zaczeto gra" << std::endl;
			break;
		case 2:
			system("cls");
			//system("pause");
			//break;
			return 0;
		default:
			system("cls");
			break;
		}
	}	
	return 0;
};	

