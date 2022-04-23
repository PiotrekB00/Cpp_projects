//Piotr Barabasz
//255294
#include "Symulacja.h"

int main() {
    Symulacja symulacja1;
	int w;

	while (1) {
		do {
			std::cout << "Uklad automatycznej regulacji" << std::endl << "1 - nowa symulacja" << std::endl << "2 - zakoncz" << std::endl;
			std::cin >> w;
			system("cls");
			if (std::cin.fail() == true) { //wykrycie b³êdu
				std::cin.clear(); //resetowanie flag b³êdu
				std::cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
			}
			else break;
		} while (w != 1 && w != 2);

		switch (w) {
		case 1:
			system("cls");
			symulacja1.start();
			system("pause");
			break;
		case 2:
			system("cls");
			return 0;
		default:
			system("cls");
			break;
		}
	}

    std::cin.get();
	return 0;
}

