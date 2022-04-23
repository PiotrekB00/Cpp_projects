#include "Czas.h"
#include "Harmonogram.h"

int main() {
	int sek = 0, min = 0, godz = 0;
	int x, y;

	Czas czas1(10, 1, 5), czas2(20, 10, 5), czas3(346), czas4(54, 63), czas5(0), czas_suma, czas_z_konsoli(sek, min, godz), czas_zakres(sek, min, godz);		//, czas_zakres_suma;
	Harmonogram h1, h3;

	/*if ((czas1 < czas2) || (czas1 == czas2)) {

	}
	czas1 + czas2;*/

	h1.dodajCzas(czas1);
	h1.dodajCzas(czas2);
	h1.dodajCzas(czas3);
	h1.dodajCzas(czas4);
	h1.dodajCzas(czas5);

	while (1) {
		std::cout << "Harmonogram" << std::endl;
		std::cout << "1 - Pokaz czasy" << std::endl;
		std::cout << "2 - Dodaj czas" << std::endl;
		std::cout << "3 - Pokaz liczbe czasow" << std::endl;
		std::cout << "4 - Wybierz konkretny czas do wyswietlenia" << std::endl;
		std::cout << "5 - Zsumuj czasy" << std::endl;
		std::cout << "6 - Skopiuj n czasow" << std::endl;
		std::cout << "7 - Dodaj kopie harmonogramu z zakresem" << std::endl;
		std::cout << "8 - Dodaj zadana liczbe sekund do wybranego czasu" << std::endl;
		std::cin >> y;

		switch (y) {
		case 1:													//Pokaz czasy
			system("cls");
			std::cout << "Wpisane czasy:" << std::endl;
			h1.pokaz();
			break;
		case 2:													//Dodaj czas
			system("cls");

			std::cout << "Podaj liczbe sekund: ";
			std::cin >> sek;
			std::cout << "Podaj liczbe minut: ";
			std::cin >> min;
			std::cout << "Podaj liczbe godzin: ";
			std::cin >> godz;

			czas_z_konsoli.wprowadzCzas(sek, min, godz);
			h1.dodajCzas(czas_z_konsoli);
			std::cout << "Dodano" << std::endl;

			break;
		case 3:													//Pokaz liczbe czasow
			system("cls");
			h1.wyswietl_liczbe_czasow();
			break;
		case 4:													//Wybierz konkretny czas do pokazania
			system("cls");

			h1.pokaz();

			do {
				std::cout << "Podaj czas do wyswietlenia: ";
				std::cin >> x;
			} while ((x >= (h1.get_liczba_czasow()) + 1) || x <= 0);

			h1.wybierz(x);

			break;
		case 5:													//Zsumuj czas
			system("cls");

			h1.pokaz();
			//czas_suma = h1.sumuj();
			h1.sumuj(czas_suma);
			std::cout << "Suma - ";
			czas_suma.wyswietl();

			break;
		case 6:													//Skopiuj n czasow
			system("cls");

			h1.pokaz();
			
			do {
				std::cout << "Do ktorego czasu chcesz skopiowac: ";
				std::cin >> x;
			} while ((x >= (h1.get_liczba_czasow()) + 1) || x <= 0);
			x = h1.get_liczba_czasow();
			h3 = h1;
			std::cout << "Kopia: " << std::endl;
			h3.pokaz();

			break;
		case 7:													//Dodaj kopie harmonogramu z zakresem
			system("cls");
			
			std::cout << "Podaj zakres:" << std::endl;
			std::cout << "Podaj liczbe sekund: ";
			std::cin >> sek;
			std::cout << "Podaj liczbe minut: ";
			std::cin >> min;
			std::cout << "Podaj liczbe godzin: ";
			std::cin >> godz;

			czas_zakres.wprowadzCzas(sek, min, godz);
			//czas_zakres.wyswietl();
			
			//czas_suma = h1.sumuj();
			h1.sumuj(czas_suma);

			if (((czas_suma < czas_zakres) == 1) || (czas_suma == czas_zakres) == 1) {
				h3 = h1;
			}
			else {
				h3 = h1.dodaj_do_zakresu(czas_zakres);
			}
			
			h3.pokaz();
			break;
		case 8:													//Dodaj zadana liczbe sekund do wybranego czasu
			system("cls");

			h1.pokaz();

			do {
				std::cout << "Podaj do ktorego czasu chcesz dodac sekundy: ";
				std::cin >> x;
			} while ((x >= (h1.get_liczba_czasow()) + 1) || x <= 0);

			std::cout << "Podaj o ile sekund chcesz dodac: ";
			std::cin >> sek;

			h1.dodaj_sek(x, sek);

			break;
		default:
			system("cls");
			std::cout << "Wprowadz liczbe:" << std::endl;
			break;
		}
	
	}
	//std::cin.get();
	return 0;
}
